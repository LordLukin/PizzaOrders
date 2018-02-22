#include "OrderSystem.h"
#include "DotPay.h"
#include "PayPal.h"
#include "CreditCardSystem.h"
#include <iostream>
#include <iomanip>
#include <thread>

OrderSystem & OrderSystem::instance()
{
    if (!instance_)
    {
        instance_ = new OrderSystem{};
    }
    return *instance_;
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
        auto price = selected_->calculatePrice(pizzas);
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
                std::this_thread::sleep_for(minutes(2));
            } while (!isOrderReady);

            std::cout << "Your order with id " << orderId << " is ready" << std::endl;

            auto deliveryId = selected_->setDeliveryAddress(orderId, deliveryAddress);
            std::cout << "Expect delivery soon to " << deliveryAddress << std::endl;

            bool isOrderDelivered = false;
            do
            {
                isOrderDelivered = selected_->checkDeliveryStatus(deliveryId);
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
        success = pp.charge(price);
    }
    else if (paymentMethod_ == 1) // dotpay
    {
        DotPay dp;
        success = dp.charge(price);
    }
    else if (paymentMethod_ == 2) // CreditCard
    {
        CreditCardSystem ccs;
        success = ccs.charge(price);
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

OrderSystem* OrderSystem::instance_ = nullptr;
