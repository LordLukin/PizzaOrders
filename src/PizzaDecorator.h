#pragma once
#include <string>
#include "IPizza.h"

class PizzaDecorator : public IPizza
{
public:
    PizzaDecorator(IPizza* pizza)
        :wrappedPizza(pizza)
    {}

protected:
    IPizza* wrappedPizza;
};
