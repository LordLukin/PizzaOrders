#pragma once
#include <string>
#include "Pizzeria.h"
#include "Pizza.h"

class Pizzeria
{
public:
    Pizzeria(std::string const & name);
    std::string getName();
    void makeOrder(Pizzas pizzas);
    bool validateOrder(Pizzas pizzas);

private:
    std::string name_;
};
