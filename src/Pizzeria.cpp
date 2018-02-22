#include "Pizzeria.h"
#include <iostream>
#include<algorithm>

Pizzeria::Pizzeria(std::string const & name, const Pizzas &availablePizzas)
    : name_(name)
    , availablePizzas_(availablePizzas)
    , orders_()
{}

std::string Pizzeria::getName()
{
    return name_;
}

bool Pizzeria::validateOrder(const Pizzas& pizzas) const
{
    // TODO: whole alghoritm is std::includes
    for (const auto& pizza : pizzas)
    {
        bool isAvailable = false;
        for (auto availablePizza : availablePizzas_)
        {
            if (pizza.getName() == availablePizza.getName())
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

int Pizzeria::makeOrder(const Pizzas& pizzas, const std::string& deliveryAddress)  // TODO: it should take deliveryAddress
{
    for (auto const & pizza : pizzas)
    {
        std::cout << "Pizzeria " << name_
                  << ". Making a pizza: " << pizza.getName()
                  << std::endl;
    }
    int orderId = rand() % 100;  // TODO: Silly orderId function. Collision possible
    orders_.push_back(std::make_tuple(orderId, pizzas, std::chrono::system_clock::now(), deliveryAddress, 0));
    return orderId;
}

double Pizzeria::calculatePrice(const Pizzas& pizzas)
{
    return std::accumulate(pizzas.begin(), pizzas.end(), 0.0,
                    [](double lhs, const Pizza& rhs){return lhs + rhs.getPrice();});
}

bool Pizzeria::checkDeliveryStatus(int orderId)
{
    for (auto order : orders_)
    {
        if (std::get<0>(order) == orderId)
        {
            auto now = std::chrono::system_clock::now();
            if ((now - std::get<2>(order)) > minutes(7))
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
            auto now = std::chrono::system_clock::now();
            for (auto pizza : std::get<1>(order))
            {
                if (pizza.getBakingTime() > (now - std::get<2>(order)))
                {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}
