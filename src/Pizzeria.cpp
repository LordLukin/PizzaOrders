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
    return true;
}

void Pizzeria::makeOrder(Pizzas pizzas)
{
    for (auto const & pizza : pizzas)
    {
        std::cout << "Pizzeria " << name_
                  << ". Making a perfect pizza: " << pizza->getName()
                  << std::endl;
    }
}
