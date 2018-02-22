#pragma once
#include "Pizzeria.h"
#include "Pizza.h"
#include "Margherita.h"
#include "Funghi.h"
#include "IPayment.hpp"
#include <memory>
#include <Cash.h>
#include <map>

enum class PizzeriaKey
{
    VENEZIA = 0,
    BRAVO,
    GRINDTORP
};

class OrderSystem   // TODO: God class
{
public:
    ~OrderSystem() = default;
    OrderSystem() = default;
    OrderSystem(std::map<PizzeriaKey, Pizzeria> & pizzerias);

    OrderSystem(OrderSystem const &) = delete;
    OrderSystem& operator=(OrderSystem const &) = delete;

    bool makeOrder(Pizzas pizzas, std::string deliveryAddress);
    void selectPizzeria(PizzeriaKey p);
    bool charge(double price);                          // TODO: should be private
    void selectPaymentMethod(std::unique_ptr<IPayment> pm);

private:
    std::map<PizzeriaKey, Pizzeria> pizzerias_;
    Pizzeria* selectedPizzeria_ = nullptr;
    std::unique_ptr<IPayment> paymentMethod_ = std::make_unique<Cash>();
};
