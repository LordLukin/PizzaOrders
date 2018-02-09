#include "OrderSystem.h"
#include <iostream>

void OrderSystem::makeOrder(Pizzeria pizzeria, Pizzas pizzas)
{
    if (pizzeria.validateOrder(pizzas))
    {
        pizzeria.makeOrder(pizzas);
        auto price = pizzeria.calculatePrice(pizzas);
        std::cout << "You need to pay " << price << " PLN." << std::endl;
        if (charge(price))
        {
            std::cout << "Payment was successful" << std::endl;
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
    // calls something asynchronously and poll it's state.
    // refactor to observer pattern
    return true;
}
