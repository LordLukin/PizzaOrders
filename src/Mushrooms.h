#pragma once
#include <string>
#include <Pizza.h>
#include <algorithm>
#include "IPizza.h"
#include "PizzaDecorator.h"

class Mushrooms : public PizzaDecorator
{
public:
    Mushrooms(IPizza* pizza)
        : PizzaDecorator(pizza)
    {}

    std::string toString() const override
    {
        return wrappedPizza->toString() + ", mushrooms";
    }

    double getPrice() const override
    {
        return wrappedPizza->getPrice() + 5.0;
    }

    minutes getBakingTime() const override
    {
        return std::max(wrappedPizza->getBakingTime(), minutes(2));
    }

private:

};
