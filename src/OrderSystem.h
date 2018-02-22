#pragma once
#include "Pizzeria.h"
#include "Pizza.h"
#include"paymentstrategy.h"

enum class Pizzerias
{
    VENEZIA = 0,
    BRAVO,
    GRINDTORP
};

enum class PaymentMethod    // TODO: Enum class is safer
{
    PAY_PAL,
    CREDIT_CARD,
    DOTPAY,
    CASH
};

class OrderSystem   // TODO: God class
{
public:

    OrderSystem() = default;
    ~OrderSystem() = default;

    OrderSystem(OrderSystem const &) = default;
    OrderSystem& operator=(OrderSystem const &) = default;

    bool makeOrder(const PaymentStrategy & strategy, Pizzas pizzas, std::string deliveryAddress);
    void selectPizzeria(Pizzerias p);

private:

     bool charge(double price, const PaymentStrategy &paymentStrategy);  // TODO: should be private

    static OrderSystem* instance_;
    Pizzeria* selected_;  // TODO: not initialized
    int paymentMethod_;   // TODO: not initialized

    // TODO: pizzerias should be added via constructor, which is not available now
    // They are tightly couple right now. They should be kept in a collection
    // Additionaly, if time allows: methods for adding/removing pizzerias in runtime are missing
    Pizzeria venezia_{"Venezia - real Italian pizza", { Pizza{"Margherita", 100.0, minutes(3)}}};
    Pizzeria bravo_{"Bravo - good and cheap pizza", { Pizza{"Fungi", 80.0, minutes(4)}}};
    Pizzeria grindtorp_{"Grindtorp pizzeria - local pizza", { Pizza{"Margherita", 90.0, minutes(3)}, Pizza{"Funghi", 110.0, minutes(3)}}};
};
