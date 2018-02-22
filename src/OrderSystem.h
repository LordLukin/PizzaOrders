#pragma once
#include "Pizzeria.h"
#include "Pizza.h"
#include "paymentstrategy.h"
#include <vector>

enum class Pizzerias
{
    VENEZIA = 0,
    BRAVO,
    GRINDTORP
};

enum class PaymentMethod
{
    PAY_PAL,
    CREDIT_CARD,
    DOTPAY,
    CASH
};

class OrderSystem   // TODO: God class
{
public:
    OrderSystem(const std::vector<Pizzeria>& _allPizzerias) :
        ourPizzerias(_allPizzerias){}
    OrderSystem(const OrderSystem &) = default;
    OrderSystem & operator=(const OrderSystem &) = default;
    OrderSystem(OrderSystem &&) noexcept = default;
    OrderSystem & operator=(OrderSystem &&) noexcept = default;
    //OrderSystem() = default;
    ~OrderSystem() = default;

    bool makeOrder(const PaymentStrategy & strategy, Pizzas pizzas, std::string deliveryAddress);
    void selectPizzeria(Pizzerias p);

private:

    bool charge(double price, const PaymentStrategy &paymentStrategy);

    Pizzeria* selected_ = nullptr;
    std::vector<Pizzeria> ourPizzerias;

    // TODO: pizzerias should be added via constructor, which is not available now
    // They are tightly couple right now. They should be kept in a collection
    // Additionaly, if time allows: methods for adding/removing pizzerias in runtime are missing

    void printReceipt(Pizzas pizzas, auto price);
    void waitForOrder(int orderId);
    void waitForDelivery(int orderId);
};
