#include "Pizza.h"

Pizza::Pizza(std::string const & name, double price, minutes bakingTime)
    : name_(name), price_(price), bakingTime_(bakingTime), ingredients_{}
{}

std::string Pizza::getName() const
{
    return name_;
}

void Pizza::addIngreditent(Ingredient ingredient)
{
    ingredients_.push_back(ingredient);
}

double Pizza::getPrice() const
{
    return price_;
}

minutes Pizza::getBakingTime() const
{
    return bakingTime_;
}
