#include "OrderSystem.h"
#include <iostream>

void OrderSystem::makeOrder(Pizzeria pizzeria, Pizzas pizzas)
{
    if (pizzeria.validateOrder(pizzas))
    {
        pizzeria.makeOrder(pizzas);
    }
    else
    {
        std::cout << "At least one of selected pizza is not available in "
                  << pizzeria.getName()
                  << std::endl;
    }
}
