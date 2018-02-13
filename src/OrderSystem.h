#pragma once
#include "Pizzeria.h"
#include "Pizza.h"

class OrderSystem   // REFACTOR: God class
{
public:
    static OrderSystem& instance();

    OrderSystem(OrderSystem const &) = delete;
    OrderSystem& operator=(OrderSystem const &) = delete;

    void makeOrder(Pizzeria pizzeria, Pizzas pizzas, std::string deliveryAddress);
    void printReceipt(double price, Pizzas pizzas);
    bool charge(double price);

private:
    OrderSystem() = default;
    ~OrderSystem() = default;

    static OrderSystem* instance_;
};
