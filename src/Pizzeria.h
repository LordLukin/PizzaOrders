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
    Pizzeria(std::string const & name, const Pizzas& availablePizzas);
    // TODO: Tight coupling - need to create set of pizzas before creating a pizzeria
    Pizzeria(const Pizzeria &) = default;
    Pizzeria & operator=(const Pizzeria &) = default;
    Pizzeria(Pizzeria &&) noexcept = default;
    Pizzeria & operator=(Pizzeria &&) noexcept = default;
    Pizzeria() = delete;
    ~Pizzeria() = default;

    std::string getName();
    int makeOrder(const Pizzas& pizzas, const std::string& deliveryAddress);       // TODO: const argument
    bool validateOrder(const Pizzas& pizzas);  // TODO: const function
    double calculatePrice(const Pizzas& pizzas);
    //int setDeliveryAddress(int orderId, std::string deliveryAddress);
    bool checkDeliveryStatus(int orderId);
    bool isOrderReady(int orderId);

private:
    std::string name_;
    Pizzas availablePizzas_;
    std::vector<order> orders_;
};
