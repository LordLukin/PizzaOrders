#include <iostream>
#include "Pizzeria.h"
#include "OrderSystem.h"
#include "Cash.h"
#include <memory>

int main()
{

    // TODO: Additionaly, if time allows: methods for adding/removing pizzerias in runtime are missing
    std::map<PizzeriaKey, Pizzeria> pizzerias;
    pizzerias.insert(std::make_pair(PizzeriaKey::VENEZIA, Pizzeria{"Venezia - real Italian pizza", {new Pizza{}}}));
    pizzerias.insert(std::make_pair(PizzeriaKey::BRAVO, Pizzeria{"Bravo - good and cheap pizza", {new Pizza{}}}));
    pizzerias.insert(std::make_pair(PizzeriaKey::GRINDTORP, Pizzeria{"Grindtorp pizzeria - local pizza", {new Pizza{}}}));

    OrderSystem os(pizzerias);

    os.selectPizzeria(PizzeriaKey::GRINDTORP);
    os.selectPaymentMethod(std::move(std::make_unique<Cash>()));
    // TODO: Where is price validation? In grindtorp Margherita costs 90.0
    Pizzas pizzas = {new Pizza{}};
    std::string deliveryAddress{"Nytorpsvagen 9, 183 53 Taby, Sweden"};
    os.makeOrder(pizzas, deliveryAddress);  // TODO: returned value is ignored!
}
