#pragma once
#include "Pizzeria.h"
#include "Pizza.h"
#include "Margherita.h"
#include "Funghi.h"

enum Pizzerias
{
    VENEZIA = 0,
    BRAVO,
    GRINDTORP
};

enum PaymentMethod
{
    PAY_PAL,
    CREDIT_CARD,
    DOTPAY,
    CASH
};

class OrderSystem
{
public:
    static OrderSystem& instance();

    OrderSystem(OrderSystem const &) = delete;
    OrderSystem& operator=(OrderSystem const &) = delete;

    bool makeOrder(Pizzas pizzas, std::string deliveryAddress);
    void selectPizzeria(Pizzerias p);
    bool charge(double price);
    void selectPaymentMethod(PaymentMethod pm);

private:
    ~OrderSystem() = default;
    OrderSystem() = default;


    static OrderSystem* instance_;
    Pizzeria* selected_;
    int paymentMethod_;

    Pizzeria venezia_{"Venezia - real Italian pizza", {new Funghi{100.0}}};
    Pizzeria bravo_{"Bravo - good and cheap pizza", {new Margherita{80.0}}};
    Pizzeria grindtorp_{"Grindtorp pizzeria - local pizza", {new Margherita{90.0}, new Funghi{110.0}}};
};
