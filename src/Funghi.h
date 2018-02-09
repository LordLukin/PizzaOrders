#pragma once
#include "Pizza.h"

class Funghi : public Pizza
{
public:
    Funghi();

private:
    Ingredient mozzarella_;
    Ingredient tomatoSauce_;
    Ingredient mushrooms_;
};
