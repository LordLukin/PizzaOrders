#pragma once
#include "Pizza.h"

class Margherita : public Pizza
{
public:
    Margherita() = delete;
    Margherita(double price);

private:
    Ingredient mozzarella_;
    Ingredient tomatoSauce_;
};
