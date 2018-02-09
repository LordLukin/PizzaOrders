#pragma once
#include <set>
#include "Pizzeria.h"
#include "Pizza.h"

class OrderSystem
{
public:
    void makeOrder(Pizzeria pizzeria, Pizzas pizzas);
    bool charge(double price);
};
