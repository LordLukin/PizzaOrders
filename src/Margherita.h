#pragma once
#include "Pizza.h"

class Margherita : public Pizza
{
public:
    Margherita();
private:
    Ingredient mozzarella;
    Ingredient tomatoSauce;
};
