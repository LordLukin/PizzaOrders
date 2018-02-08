#pragma once
#include <list>
#include <set>
#include "Ingredient.h"

class Pizza
{
public:
    Pizza() = default;
    ~Pizza() = default;	// should be virtual

private:
    std::list<Ingredient> ingredients;
};

using Pizzas = std::set<Pizza*>;
