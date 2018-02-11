#include "OrderSystem.h"
#include "DotPay.h"
#include "PayPal.h"
#include "CreditCardSystem.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

OrderSystem & OrderSystem::instance()
{
    if (!instance_)
    {
        instance_ = new OrderSystem{};
    }
    return *instance_;
}

void OrderSystem::printReceipt(double price, Pizzas pizzas)
{
    std::cout << "---- RECEIPT ----" << std::endl;
    for (auto pizza : pizzas)
    {
        // TODO: format output
        std::cout << std::fixed << std::right << std::setprecision(2);
        std::cout << " " << pizza->getName() << " " << pizza->getPrice() << std::endl;
    }
    std::cout << "-----------------" << std::endl;
    std::cout << " TOTAL: " << price << std::endl;
}

void OrderSystem::makeOrder(Pizzeria pizzeria, Pizzas pizzas, std::string deliveryAddress)
{
    if (pizzeria.validateOrder(pizzas))
    {
        auto price = pizzeria.calculatePrice(pizzas);
        std::cout << "You need to pay " << price << " SEK." << std::endl;
        if (charge(price))
        {
            int orderId = pizzeria.makeOrder(pizzas);
            std::cout << "Your order has id " << orderId << std::endl;
            printReceipt(price, pizzas);
            // put function body everywhere. Refactor by extracting method

            bool isOrderReady = false;
            do  // REFACTOR: from active polling to observer pattern
            {
                isOrderReady = pizzeria.isOrderReady(orderId);
                std::cout << "Order is not ready yet. Wait for the orderId " << orderId
                          << " to finish" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(8));
            } while (!isOrderReady);

            std::cout << "Your order with id " << orderId << " is ready" << std::endl;

            auto deliveryId = pizzeria.setDeliveryAddress(orderId, deliveryAddress);
            std::cout << "Expect delivery soon to " << deliveryAddress << std::endl;

            bool isOrderDelivered = false;
            do
            {
                isOrderDelivered = pizzeria.checkDeliveryStatus(deliveryId);
                std::cout << "Please be patient. Your pizza is on the way." << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(8));
            } while (!isOrderDelivered);

            std::cout << "Pizza delivered. Thank you for using our system!" << std::endl;
        }
        else
        {
            std::cout << "Payment unsuccessful. Order cancelled." << std::endl;
        }
    }
    else
    {
        std::cout << "At least one of selected pizza is not available in "
                  << pizzeria.getName()
                  << std::endl;
    }
}

bool OrderSystem::charge(double price)
{
    auto paymentMethod = 3; // selectPaymentMethod();
    bool success;       // REFACTOR: Unintialized data
    // REFACTOR: to a common base class as an payment interface. Now every system has other interface
    // REFACTOR: Facade + Strategy
    // REFACTOR: Add enum for payment method
    if (paymentMethod == 0)  // PayPal
    {
        PayPal pp;
        std::string username;
        std::string password;
        std::cout << "Provide your PayPal credentials" << std::endl;
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;
        pp.login(username, password);   // REFACTOR: Return value checking!
        success = pp.pay(price);
    }
    else if (paymentMethod == 1) // dotpay
    {
        std::cout << "DotPay payment was chosen" << std::endl;
        DotPay dp;
        int timer = 0;
        bool valid;
        std::cout << "Waiting for confirmation from online system" << std::endl;
        do  // REFACTOR: observer pattern
        {
            std::chrono::seconds waitTime(1);
            std::this_thread::sleep_for(waitTime);
            timer += 1;
            valid = dp.sslPaymentReditect(price);
        } while (!valid && timer < 300);
        success = valid;
    }
    else if (paymentMethod == 2) // CreditCard
    {
        CreditCardSystem ccs;
        std::string cardNumber;
        std::string owner;
        int monthValid;
        int yearValid;
        int ccv;
        std::cout << "Provide your credit card information:" << std::endl;
        std::cout << "Card number: ";
        std::cin >> cardNumber;
        std::cout << "Owner's name and surname: ";
        std::cin >> owner;
        std::cout << "Valid until month: ";
        std::cin >> monthValid;
        std::cout << "Valid until year: ";
        std::cin >> yearValid;
        std::cout << "CCV code: ";
        std::cin >> ccv;
        bool isDataValid = ccs.enterData(cardNumber, owner, monthValid, yearValid, ccv);
        if (isDataValid)
        {
            success = ccs.charge(price);
        }
        else
        {
            std::cout << "Invalid credit card data" << std::endl;
            success = false;
        }
    }
    else // payByCash
    {
        std::cout << "Payment by cash selected. Please prepare " << price << " in cash.";
        success = true;
    }

    if (success)
    {
        std::cout << "Payment was successful" << std::endl;
        return true;
    }
    return false;
}

OrderSystem* OrderSystem::instance_ = nullptr;
