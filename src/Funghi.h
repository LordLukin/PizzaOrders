#pragma once
#include "Pizza.h"

class Funghi : public Pizza
{
public:
    Funghi();
private:
    Ingredient mozzarella;
    Ingredient tomatoSauce;
    Ingredient mushrooms;
};
