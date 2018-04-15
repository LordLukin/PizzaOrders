#include "Pizzeria.h"
#include <iostream>
#include <numeric>

Pizzeria::Pizzeria(std::string const & name, Pizzas availablePizzas, ITime *time)
    : name_(name)
    , availablePizzas_(availablePizzas)
    , orders_()
    , time_(time)
{}

std::string Pizzeria::getName()
{
    return name_;
}

bool Pizzeria::validateOrder(Pizzas pizzas)
{
    // TODO: whole alghoritm is std::includes
    for (const auto &pizza : pizzas)
    {
        bool isAvailable = false;
        for (auto availablePizza : availablePizzas_)
        {
            if (pizza->getName() == availablePizza->getName())
            {
                isAvailable = true;
            }
        }
        if (isAvailable == false)
        {
            return false;
        }
    }
    return true;
}

int Pizzeria::makeOrder(Pizzas pizzas)  // TODO: it should take deliveryAddress
{
    for (auto const & pizza : pizzas)
    {
        std::cout << "Pizzeria " << name_
                  << ". Making a pizza: " << pizza->getName()
                  << std::endl;
    }
    int orderId = rand() % 100;  // TODO: Silly orderId function. Collision possible
    orders_.push_back(std::make_tuple(orderId, pizzas, std::chrono::system_clock::now(), ""));
    return orderId;
}

double Pizzeria::calculatePrice(Pizzas pizzas)
{
    return std::accumulate(pizzas.begin(),
                           pizzas.end(),
                           0.0,
                           [](double previousSum, Pizza *pizza)
                           {
                               return previousSum + pizza->getPrice();
                           });
}

int Pizzeria::setDeliveryAddress(int orderId, std::string deliveryAddress)
{
    for (auto & order : orders_)
    {
        if (std::get<0>(order) == orderId)
        {
            std::get<3>(order) = deliveryAddress;
            std::cout << "Delivery address set to " << std::get<3>(order) << std::endl;
        }
    }
    return orderId;
}

bool Pizzeria::checkDeliveryStatus(int orderId)
{
    for (auto order : orders_)
    {
        if (std::get<0>(order) == orderId)
        {
            auto now = std::chrono::system_clock::now();
            if(time_->waitForDelivery(std::get<2>(order)))
            {
                return true;
            }
        }
    }
    return false;
}

bool Pizzeria::isOrderReady(int orderId)
{
    // TODO: std::map<int, pair<pizzas, time_point>> would be better for searching
    for (auto order : orders_)
    {
        if (std::get<0>(order) == orderId)
        {
            for (auto pizza : std::get<1>(order))
            {
                if (time_->waitForBaking(pizza->getBakingTime(), std::get<2>(order)))
                {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}
