#include <iostream>
#include "Margherita.h"
#include "Funghi.h"
#include "Pizzeria.h"
#include "OrderSystem.h"
#include "Cash.h"
#include <memory>

int main()
{
    OrderSystem& os = OrderSystem::instance();

    os.selectPizzeria(GRINDTORP);
    os.selectPaymentMethod(std::move(std::make_unique<Cash>()));
    // TODO: Where is price validation? In grindtorp Margherita costs 90.0
    Pizzas pizzas = {new Margherita{80.0}, new Funghi{110.0}};
    std::string deliveryAddress{"Nytorpsvagen 9, 183 53 Taby, Sweden"};
    os.makeOrder(pizzas, deliveryAddress);  // TODO: returned value is ignored!
}
