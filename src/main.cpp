#include <iostream>
#include "Margherita.h"
#include "Funghi.h"
#include "Pizzeria.h"
#include "OrderSystem.h"
#include "Cash.h"
#include <memory>

int main()
{

    // TODO: pizzerias should be added via constructor, which is not available now
    // They are tightly couple right now. They should be kept in a collection
    // Additionaly, if time allows: methods for adding/removing pizzerias in runtime are missing
    std::map<PizzeriaKey, Pizzeria> pizzerias;
    pizzerias.insert(std::make_pair(PizzeriaKey::VENEZIA, Pizzeria{"Venezia - real Italian pizza", {new Funghi{100.0}}}));
    pizzerias.insert(std::make_pair(PizzeriaKey::BRAVO, Pizzeria{"Bravo - good and cheap pizza", {new Margherita{80.0}}}));
    pizzerias.insert(std::make_pair(PizzeriaKey::GRINDTORP, Pizzeria{"Grindtorp pizzeria - local pizza", {new Margherita{90.0}, new Funghi{110.0}}}));

    OrderSystem os(pizzerias);

    os.selectPizzeria(PizzeriaKey::GRINDTORP);
    os.selectPaymentMethod(std::move(std::make_unique<Cash>()));
    // TODO: Where is price validation? In grindtorp Margherita costs 90.0
    Pizzas pizzas = {new Margherita{80.0}, new Funghi{110.0}};
    std::string deliveryAddress{"Nytorpsvagen 9, 183 53 Taby, Sweden"};
    os.makeOrder(pizzas, deliveryAddress);  // TODO: returned value is ignored!
}
