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

private:
    std::string name_;
    std::list<Ingredient> ingredients_;
};

using Pizzas = std::set<Pizza*>;
