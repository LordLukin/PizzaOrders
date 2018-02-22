#pragma once
#include "Pizzeria.h"
#include "Pizza.h"
#include "Margherita.h"
#include "Funghi.h"
#include "IPayment.hpp"
#include <memory>
#include <Cash.h>

enum Pizzerias
{
    VENEZIA = 0,
    BRAVO,
    GRINDTORP
};

enum PaymentMethod    // TODO: Enum class is safer
{
    PAY_PAL,
    CREDIT_CARD,
    DOTPAY,
    CASH
};

class OrderSystem   // TODO: God class
{
public:
    ~OrderSystem() = default;
    OrderSystem() = default;

    OrderSystem(OrderSystem const &) = delete;
    OrderSystem& operator=(OrderSystem const &) = delete;

    bool makeOrder(Pizzas pizzas, std::string deliveryAddress);
    void selectPizzeria(Pizzerias p);
    bool charge(double price);                          // TODO: should be private
    void selectPaymentMethod(std::unique_ptr<IPayment> pm);

private:
    Pizzeria* selected_;  // TODO: not initialized
    std::unique_ptr<IPayment> paymentMethod_ = std::make_unique<Cash>();

    // TODO: pizzerias should be added via constructor, which is not available now
    // They are tightly couple right now. They should be kept in a collection
    // Additionaly, if time allows: methods for adding/removing pizzerias in runtime are missing
    Pizzeria venezia_{"Venezia - real Italian pizza", {new Funghi{100.0}}};
    Pizzeria bravo_{"Bravo - good and cheap pizza", {new Margherita{80.0}}};
    Pizzeria grindtorp_{"Grindtorp pizzeria - local pizza", {new Margherita{90.0}, new Funghi{110.0}}};
};
