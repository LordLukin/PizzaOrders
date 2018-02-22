#pragma once
#include <list>
#include <set>
#include <string>
#include "IPizza.h"

 // To simulate time flow ;)

class Pizza : public IPizza
{
public:
    Pizza() = default;

    ~Pizza() = default;             // TODO: Non virtual destructor! Possible memory leaks
    std::string toString() const override
    {
        return "Pizza";
    }
    double getPrice() const override
    {
        return 50.0;
    }
    minutes getBakingTime() const override
    {
        return minutes(2);
    }

private:


};

using Pizzas = std::set<IPizza*>;
