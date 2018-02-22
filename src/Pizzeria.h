#pragma once
#include <string>
#include <tuple>
#include <vector>
#include <chrono>
#include "Pizzeria.h"
#include "Pizza.h"
#include <iostream>

using order = std::tuple<int, Pizzas, std::chrono::system_clock::time_point, std::string, int>;

class Pizzeria
{
public:
    Pizzeria()
    {
        std::cout << "Should not be called!" << std::endl;
    }
    Pizzeria(std::string const & name, Pizzas availablePizzas);  // TODO: const &
    // TODO: Tight coupling - need to create set of pizzas before creating a pizzeria
    std::string getName();
    int makeOrder(Pizzas pizzas);       // TODO: const argument
    bool validateOrder(Pizzas pizzas);  // TODO: const function
    double calculatePrice(Pizzas pizzas);
    int setDeliveryAddress(int orderId, std::string deliveryAddress);
    bool checkDeliveryStatus(int deliveryId);
    bool isOrderReady(int orderId);

private:
    std::string name_;
    Pizzas availablePizzas_;
    std::vector<order> orders_;
};
