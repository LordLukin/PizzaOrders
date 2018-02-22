#include "OrderSystem.h"
#include "dotpay.h"
#include "paypal.h"
#include "creditcardsystem.h"
#include <iostream>
#include <iomanip>
#include <thread>


void OrderSystem::selectPizzeria(Pizzerias p)
{
    switch (p)
    {
    case Pizzerias::VENEZIA:
        selected_ = &ourPizzerias[0];
        break;
    case Pizzerias::BRAVO:
       selected_ = &ourPizzerias[1];
        break;
    case Pizzerias::GRINDTORP:
        selected_ = &ourPizzerias[2];
        break;
    }
}

void OrderSystem::printReceipt(Pizzas pizzas, auto price)
{
    std::cout << "---- RECEIPT ----" << std::endl;
    for (auto pizza : pizzas)
    {
        std::cout << std::fixed << std::right << std::setprecision(2);
        std::cout << " " << pizza.getName() << " " << pizza.getPrice() << std::endl;
    }
    std::cout << "-----------------" << std::endl;
    std::cout << " TOTAL: " << price << std::endl;
}

void OrderSystem::waitForOrder(int orderId)
{
    bool isOrderReady = false;
    do  // TODO: from active polling to observer pattern
    {
        isOrderReady = selected_->isOrderReady(orderId);
        std::cout << "Order is not ready yet. Wait for the orderId " << orderId
                  << " to finish" << std::endl;
        std::this_thread::sleep_for(minutes(2));
    } while (!isOrderReady);
}

void OrderSystem::waitForDelivery(int orderId)
{
    bool isOrderDelivered = false;
    do
    {
        isOrderDelivered = selected_->checkDeliveryStatus(orderId);
        std::cout << "Please be patient. Your pizza is on the way." << std::endl;
        std::this_thread::sleep_for(minutes(2));
    } while (!isOrderDelivered);
}


bool OrderSystem::makeOrder(const PaymentStrategy & payment, Pizzas pizzas, std::string deliveryAddress)
{
    if (selected_->validateOrder(pizzas))
    {
        auto price = selected_->calculatePrice(pizzas);
        std::cout << "You need to pay " << price << " SEK." << std::endl;
        if (charge(price, payment))
        {
            int orderId = selected_->makeOrder(pizzas, deliveryAddress);
            std::cout << "Your order has id " << orderId << std::endl;

            printReceipt(pizzas, price);

            waitForOrder(orderId);

            std::cout << "Your order with id " << orderId << " is ready" << std::endl;

            std::cout << "Expect delivery soon to " << deliveryAddress << std::endl;

            waitForDelivery(orderId);

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


bool OrderSystem::charge(double price, const PaymentStrategy & paymentStrategy)
{
   // return paymentStrategy.charge(price);
    // TODO: to a common base class as a payment interface. Now every system has another interface
    // TODO: Strategy pattern. Right now this function is a Facade pattern
    // payByCash

    if (paymentStrategy.charge(price) )
    {
        std::cout << "Payment was successful" << std::endl;
        return true;
    }
    return false;
}

