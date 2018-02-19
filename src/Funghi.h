#pragma once
#include "Pizza.h"

class Funghi : public Pizza
{
public:
    Funghi() = delete;
    Funghi(double price);

private:
    Ingredient mozzarella_;
    Ingredient tomatoSauce_;
    Ingredient mushrooms_;
};
