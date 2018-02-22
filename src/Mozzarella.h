#pragma once
#include <string>
#include <Pizza.h>
#include <algorithm>
#include "IPizza.h"
#include "PizzaDecorator.h"

class Mozzarella : public PizzaDecorator
{
public:
    Mozzarella(IPizza* pizza)
        : PizzaDecorator(pizza)
    {}

    std::string toString() const override
    {
        return wrappedPizza->toString() + ", mozzarella";
    }

    double getPrice() const override
    {
        return wrappedPizza->getPrice() + 10.0;
    }

    minutes getBakingTime() const override
    {
        return std::max(wrappedPizza->getBakingTime(), minutes(2));
    }

private:

};
