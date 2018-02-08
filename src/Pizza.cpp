#include "Pizza.h"

Pizza::Pizza(std::string const & name)
    : name_(name), ingredients_{}
{}

std::string Pizza::getName()
{
    return name_;
}