#pragma once
#include <list>
#include <set>
#include "Ingredient.h"

class Pizza
{
public:
    Pizza(std::string const & name);
    virtual ~Pizza() = default;
    std::string getName();
    double getPrice();

private:
    std::string name_;
    double price;
    std::list<Ingredient> ingredients_;
};

using Pizzas = std::set<Pizza*>;
