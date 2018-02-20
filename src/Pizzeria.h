#pragma once
#include <string>
#include <tuple>
#include <vector>
#include <chrono>
#include "Pizzeria.h"
#include "Pizza.h"

using order = std::tuple<int, Pizzas, std::chrono::system_clock::time_point, std::string, int>;

class Pizzeria
{
public:
    Pizzeria(std::string const & name, Pizzas availablePizzas);
    std::string getName();
    int makeOrder(Pizzas pizzas);
    bool validateOrder(Pizzas pizzas);
    double calculatePrice(Pizzas pizzas);
    int setDeliveryAddress(int orderId, std::string deliveryAddress);
    bool checkDeliveryStatus(int deliveryId);
    bool isOrderReady(int orderId);

private:
    std::string name_;
    Pizzas availablePizzas_;
    std::vector<order> orders_;
};
