#pragma once
#include <string>
#include "Pizzeria.h"
#include "Pizza.h"

class Pizzeria
{
public:
    Pizzeria(std::string const & name);
    std::string getName();
    void makeOrder(Pizzas pizzas);      // To fix: const argument
    bool validateOrder(Pizzas pizzas);  // To fix: const function
    double calculatePrice(Pizzas pizzas);

private:
    std::string name_;
};
