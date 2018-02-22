#pragma once
#include <string>
#include <Pizza.h>
#include <algorithm>
#include "IPizza.h"
#include "PizzaDecorator.h"

class Ham : public PizzaDecorator
{
public:
    Ham(IPizza* pizza)
        : PizzaDecorator(pizza)
    {}

    std::string toString() const override
    {
        return wrappedPizza->toString() + ", ham";
    }

    double getPrice() const override
    {
        return wrappedPizza->getPrice() + 50.0;
    }

    minutes getBakingTime() const override
    {
        return std::max(wrappedPizza->getBakingTime(), minutes(1));
    }

private:

};
