#include "OrderSystem.h"
#include <iostream>
#include <iomanip>

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
        std::cout << "You need to pay " << price << " PLN." << std::endl;
        if (charge(price))
        {
            std::cout << "Payment was successful" << std::endl;
            int orderId = pizzeria.makeOrder(pizzas);
            std::cout << "Your order has id " << orderId << std::endl;
            printReceipt(price, pizzas);
            // put function body everywhere. Refactor by extracting method

            bool isOrderReady = false;
            do  // active polling
            {
                isOrderReady = pizzeria.isOrderReady(orderId);
                std::cout << "Order is not ready yet. Wait for the orderId " << orderId
                          << " to finish" << std::endl;
                //sleep(15);      // wait 15 seconds
            } while (!isOrderReady);

            std::cout << "Your order with id " << orderId << " is ready" << std::endl;

            auto deliveryId = pizzeria.setDeliveryAddress(orderId, deliveryAddress);
            std::cout << "Expect delivery soon to " << deliveryAddress << std::endl;

            bool isOrderDelivered = false;
            do
            {
                isOrderDelivered = pizzeria.checkDeliveryStatus(deliveryId);
                std::cout << "Please ba patient. Your pizza is on the way." << std::endl;
                //sleep(15);      // wait 15 seconds
            } while (!isOrderDelivered);

            std::cout << "Pizze delivered. Thank you for using our system!" << std::endl;
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
    // TODO: Implement
    // calls something asynchronously and poll it's state.
    // refactor to observer pattern
    return true;
}

OrderSystem* OrderSystem::instance_ = nullptr;
