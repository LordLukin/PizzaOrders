#pragma once
#include <set>
#include "Pizzeria.h"
#include "Pizza.h"

class OrderSystem
{
public:
    static OrderSystem& instance();

    OrderSystem(OrderSystem const &) = delete;
    OrderSystem& operator=(OrderSystem const &) = delete;

    void makeOrder(Pizzeria pizzeria, Pizzas pizzas);
    bool charge(double price);

private:
    OrderSystem() = default;
    ~OrderSystem() = default;

    static OrderSystem* instance_;
};
