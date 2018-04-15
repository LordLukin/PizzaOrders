#include "OrderSystem.h"
#include "DotPay.h"
#include "PayPal.h"
#include "CreditCardSystem.h"

#include <iostream>
#include <iomanip>
#include <thread>
#include <Time.h>

OrderSystem::OrderSystem(ITime *t) : time(t)
{

}

OrderSystem::~OrderSystem()
{
    delete time;
}

void OrderSystem::selectPizzeria(Pizzerias p)
{
    switch (p)
    {
    case VENEZIA:
        selected_ = &venezia_;
        break;
    case BRAVO:
        selected_ = &bravo_;
        break;
    case GRINDTORP:
        selected_ = &grindtorp_;
        break;
    }
}

bool OrderSystem::makeOrder(Pizzas pizzas, std::string deliveryAddress)
{
    if (selected_->validateOrder(pizzas))
    {
        auto price = selected_->calculatePrice(pizzas)    ;
        std::cout << "You need to pay " << price << " SEK." << std::endl;
        if (charge(price))
        {
            int orderId = selected_->makeOrder(pizzas);
            std::cout << "Your order has id " << orderId << std::endl;

            std::cout << "---- RECEIPT ----" << std::endl;
            for (auto pizza : pizzas)
            {
                std::cout << std::fixed << std::right << std::setprecision(2);
                std::cout << " " << pizza->getName() << " " << pizza->getPrice() << std::endl;
            }
            std::cout << "-----------------" << std::endl;
            std::cout << " TOTAL: " << price << std::endl;

            bool isOrderReady = false;
            do  // TODO: from active polling to observer pattern
            {
                isOrderReady = selected_->isOrderReady(orderId);
                std::cout << "Order is not ready yet. Wait for the orderId " << orderId
                          << " to finish" << std::endl;
                time -> wait(minutes(2));


            } while (!isOrderReady);

            std::cout << "Your order with id " << orderId << " is ready" << std::endl;

            std::cout << "Expect delivery soon to " << deliveryAddress << std::endl;

            bool isOrderDelivered = false;
            do
            {
                isOrderDelivered = selected_->checkDeliveryStatus(orderId);
                std::cout << "Please be patient. Your pizza is on the way." << std::endl;
                time->wait(minutes(2));
            } while (!isOrderDelivered);

            std::cout << "Pizza delivered. Thank you for using our system!" << std::endl;
            return true;
        }
        else
        {
            std::cout << "Payment unsuccessful. Order cancelled." << std::endl;
            return false;
        }
    }
    else
    {
        std::cout << "At least one of selected pizza is not available in "
                  << selected_->getName()
                  << std::endl;
        return false;
    }
}

void OrderSystem::selectPaymentMethod(PaymentMethod pm)
{
    if (pm == PAY_PAL)
        paymentMethod_ = 0;
    else if (pm == CREDIT_CARD)
        paymentMethod_ = 2;
    else if (pm == DOTPAY)
        paymentMethod_ = 1;
    else
        paymentMethod_ =  3;
}

bool OrderSystem::charge(double price)
{
    bool success;           // TODO: Unintialized data
    // TODO: to a common base class as a payment interface. Now every system has another interface
    // TODO: Strategy pattern. Right now this function is a Facade pattern
    if (paymentMethod_ == 0)  // PayPal
    {
        PayPal pp;
        std::string username;
        std::string password;
        std::cout << "Provide your PayPal credentials" << std::endl;
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;
        pp.login(username, password);   // TODO: Return value checking! Was login successful?
        success = pp.pay(price);
    }
    else if (paymentMethod_ == 1) // dotpay
    {
        std::cout << "DotPay payment was chosen" << std::endl;
        DotPay dp;
        int timer = 0;
        bool valid;
        std::cout << "Waiting for confirmation from online system" << std::endl;
        do  // TODO: observer pattern
        {
            std::chrono::seconds waitTime(1);
            time -> wait(minutes(waitTime));
            timer += 1;
            valid = dp.sslPaymentReditect(price);
        } while (!valid && timer < 300);
        success = valid;
    }
    else if (paymentMethod_ == 2) // CreditCard
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
        std::cout << "Payment by cash selected. Please prepare " << price << " SEK in cash. " << std::endl;
        success = true;
    }

    if (success)
    {
        std::cout << "Payment was successful" << std::endl;
        return true;
    }
    return false;
}
