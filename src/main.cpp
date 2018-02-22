#include <iostream>
#include "Pizzeria.h"
#include "OrderSystem.h"
#include "paybycash.h"

int main()
{
    OrderSystem os;

    os.selectPizzeria(GRINDTORP);
    //os.selectPaymentMethod(CASH);
    // TODO: Where is price validation? In grindtorp Margherita costs 90.0
    Pizzas pizzas = {Pizza{"Margherita", 90.0, minutes(3)}, Pizza{"Funghi", 110.0, minutes(3)}};
//    Pizzas pizzas = {Pizza{80.0}, new Funghi{110.0}};
    std::string deliveryAddress{"Nytorpsvagen 9, 183 53 Taby, Sweden"};
    const PaymentStrategy& paybycash = PayByCash();

    os.makeOrder(paybycash, pizzas, deliveryAddress);  // TODO: returned value is ignored!
}
