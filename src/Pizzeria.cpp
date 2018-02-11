#include "Pizzeria.h"
#include <iostream>

Pizzeria::Pizzeria(std::string const & name)
    : name_(name)
{}

std::string Pizzeria::getName()
{
    return name_;
}

bool Pizzeria::validateOrder(Pizzas pizzas)
{
    // TODO: Implement
    return true;
}

int Pizzeria::makeOrder(Pizzas pizzas)
{
    for (auto const & pizza : pizzas)
    {
        std::cout << "Pizzeria " << name_
                  << ". Making a perfect pizza: " << pizza->getName()
                  << std::endl;
    }
    // TODO: Implement this function to return some wrong id (rand%100)?
    return 1;
}

double Pizzeria::calculatePrice(Pizzas pizzas)
{
    // TODO: Implement
    return 0.0;
}

int Pizzeria::setDeliveryAddress(int orderId, std::string deliveryAddress)
{
    // TODO: Implement this function to return some wrong id (rand%100)?
    return 1;
}

bool Pizzeria::checkDeliveryStatus(int deliveryId)
{
    // TODO: Implement
    return true;
}

bool Pizzeria::isOrderReady(int orderId)
{
    // TODO: Implement
    return true;
}
