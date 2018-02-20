#include <iostream>
#include "Margherita.h"
#include "Funghi.h"
#include "Pizzeria.h"
#include "OrderSystem.h"

int main()
{
    OrderSystem& os = OrderSystem::instance();

    os.selectPizzeria(GRINDTORP);
    os.selectPaymentMethod(CASH);
    Pizzas pizzas = {new Margherita{80.0}, new Funghi{110.0}};
    std::string deliveryAddress{"Nytorpsvagen 9, 183 53 Taby, Sweden"};
    os.makeOrder(pizzas, deliveryAddress);
}
