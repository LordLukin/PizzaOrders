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

enum PaymentMethod    // REFACTOR: Enum class is safer
{
    PAY_PAL,
    CREDIT_CARD,
    DOTPAY,
    CASH
};

class OrderSystem   // REFACTOR: God class
{
public:
    static OrderSystem& instance();

    OrderSystem(OrderSystem const &) = delete;
    OrderSystem& operator=(OrderSystem const &) = delete;

    void makeOrder(Pizzas pizzas, std::string deliveryAddress);
    void selectPizzeria(Pizzerias p);
    void printReceipt(double price, Pizzas pizzas);     // REFACTOR: should be private
    bool charge(double price);                          // REFACTOR: should be private
    void selectPaymentMethod(PaymentMethod pm);

private:
    ~OrderSystem() = default;
    OrderSystem() = default;


    static OrderSystem* instance_;
    Pizzeria* selected_;  // REFACTOR: not initialized
    int paymentMethod_;   // REFACTOR: not initialized

    // REFACTOR: pizzerias should be added via constructor, which is not available now
    // They are tightly couple right now. They should be kept in a collection
    // Additionaly, if time allows: methods for adding/removing pizzerias in runtime are missing
    Pizzeria venezia_{"Venezia - real Italian pizza", {new Funghi{100.0}}};
    Pizzeria bravo_{"Bravo - good and cheap pizza", {new Margherita{80.0}}};
    Pizzeria grindtorp_{"Grindtorp pizzeria - local pizza", {new Margherita{90.0}, new Funghi{110.0}}};
};
