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
    Pizzeria(std::string const & name, Pizzas availablePizzas);  // REFACTOR const &
    // REFACTOR: Tight coupling - need to create set of pizzas before creating a pizzeria
    std::string getName();
    int makeOrder(Pizzas pizzas);       // To fix: const argument
    bool validateOrder(Pizzas pizzas);  // To fix: const function
    double calculatePrice(Pizzas pizzas);
    int setDeliveryAddress(int orderId, std::string deliveryAddress);
    bool checkDeliveryStatus(int deliveryId);
    bool isOrderReady(int orderId);

private:
    std::string name_;
    Pizzas availablePizzas_;
    std::vector<order> orders_;
};
