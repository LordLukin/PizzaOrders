#pragma once
#include <string>
#include <tuple>
#include <vector>
#include <chrono>
#include "Pizza.h"

using Order = std::tuple<int, Pizzas, std::chrono::system_clock::time_point, std::string>;

class Pizzeria
{
public:
    Pizzeria(std::string const & name, Pizzas availablePizzas, ITime *time);  // TODO: const &
    // TODO: Tight coupling - need to create set of pizzas before creating a pizzeria
    std::string getName();
    int makeOrder(Pizzas pizzas);       // TODO: const argument
    bool validateOrder(Pizzas pizzas);  // TODO: const function
    double calculatePrice(Pizzas pizzas);
    int setDeliveryAddress(int orderId, std::string deliveryAddress);
    bool checkDeliveryStatus(int orderId);
    bool isOrderReady(int orderId);

private:
    ITime *time_;
    std::string name_;
    Pizzas availablePizzas_;
    std::vector<Order> orders_;
};
