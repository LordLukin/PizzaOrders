#pragma once
#include <string>
#include "Pizzeria.h"
#include "Pizza.h"

class Pizzeria
{
public:
    Pizzeria(std::string const & name);
    std::string getName();
    int makeOrder(Pizzas pizzas);       // To fix: const argument
    bool validateOrder(Pizzas pizzas);  // To fix: const function
    double calculatePrice(Pizzas pizzas);
    int setDeliveryAddress(int orderId, std::string deliveryAddress);
    bool checkDeliveryStatus(int deliveryId);
    bool isOrderReady(int orderId);

private:
    std::string name_;
};
