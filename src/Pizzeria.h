#pragma once
#include <string>
#include "Pizzeria.h"
#include "Pizza.h"

class Pizzeria
{
public:
    Pizzeria(std::string const & name);
    void makeOrder(Pizzas pizzas);
private:
    std::string name_;
};
