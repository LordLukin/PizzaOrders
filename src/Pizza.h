#pragma once
#include <list>
#include <set>
#include <chrono>
#include "Ingredient.h"

using minutes = std::chrono::seconds;   // To simulate time flow ;)

class Pizza
{
public:
    Pizza(std::string const & name, double price, minutes bakingTime);
    ~Pizza() = default;             // TODO: Non virtual destructor! Possible memory leaks
    virtual std::string getName();  // TODO: const correctnest
    virtual double getPrice() const;
    virtual minutes getBakingTime() const;
    void addIngreditent(Ingredient ingredient);

private:
    std::string name_;
    double price_;
    minutes bakingTime_;
    std::list<Ingredient> ingredients_;  // TODO: Seems not used
};

using Pizzas = std::set<Pizza*>;
