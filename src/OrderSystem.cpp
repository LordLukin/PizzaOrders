#include "OrderSystem.h"
#include "IPayment.hpp"
#include <iostream>
#include <iomanip>
#include <thread>

OrderSystem::OrderSystem(std::map<PizzeriaKey, Pizzeria>& pizzerias)
    : pizzerias_(pizzerias)
{
}

void OrderSystem::selectPizzeria(PizzeriaKey p)
{
    selectedPizzeria_ = &pizzerias_.at(p);
}

bool OrderSystem::makeOrder(Pizzas pizzas, std::string deliveryAddress)
{
    if (selectedPizzeria_->validateOrder(pizzas))
    {
        auto price = selectedPizzeria_->calculatePrice(pizzas);
        std::cout << "You need to pay " << price << " SEK." << std::endl;
        if (charge(price))
        {
            int orderId = selectedPizzeria_->makeOrder(pizzas);
            std::cout << "Your order has id " << orderId << std::endl;

            std::cout << "---- RECEIPT ----" << std::endl;
            for (auto pizza : pizzas)
            {
                std::cout << std::fixed << std::right << std::setprecision(2);
                std::cout << " " << pizza->toString() << " " << pizza->getPrice() << std::endl;
            }
            std::cout << "-----------------" << std::endl;
            std::cout << " TOTAL: " << price << std::endl;

            bool isOrderReady = false;
            do  // TODO: from active polling to observer pattern
            {
                isOrderReady = selectedPizzeria_->isOrderReady(orderId);
                std::cout << "Order is not ready yet. Wait for the orderId " << orderId
                          << " to finish" << std::endl;
                std::this_thread::sleep_for(minutes(2));
            } while (!isOrderReady);

            std::cout << "Your order with id " << orderId << " is ready" << std::endl;

            auto deliveryId = selectedPizzeria_->setDeliveryAddress(orderId, deliveryAddress);
            std::cout << "Expect delivery soon to " << deliveryAddress << std::endl;

            bool isOrderDelivered = false;
            do
            {
                isOrderDelivered = selectedPizzeria_->checkDeliveryStatus(deliveryId);
                std::cout << "Please be patient. Your pizza is on the way." << std::endl;
                std::this_thread::sleep_for(minutes(2));
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
                  << selectedPizzeria_->getName()
                  << std::endl;
        return false;
    }
}

void OrderSystem::selectPaymentMethod(std::unique_ptr<IPayment> pm)
{
    paymentMethod_ = std::move(pm);
}

bool OrderSystem::charge(double price)
{
    if (paymentMethod_ == nullptr) {
        std::cout << "No payment method selected" << std::endl;
    }
    return paymentMethod_->charge(price);
}
