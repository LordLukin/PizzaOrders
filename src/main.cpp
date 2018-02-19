#include <iostream>
#include "Margherita.h"
#include "Funghi.h"
#include "Pizzeria.h"
#include "OrderSystem.h"

int main()
{
    Pizzas pizzas = {new Margherita{}, new Funghi{}};

    // To break: 3 different pizzerias with different interfaces. Refactor to facade
    Pizzeria venezia{"Venezia - real Italian pizza", {new Funghi{}}};
    Pizzeria bravo{"Bravo - good and cheap pizza", {new Margherita{}}};
    Pizzeria grindtorp{"Grindtorp pizzeria - local pizza", pizzas};

    std::string deliveryAddress{"Nytorpsvagen 9, 183 53 Taby, Sweden"};

    // To break: pizzerias added via add method. Add a constructor
    OrderSystem& os = OrderSystem::instance();
    os.makeOrder(grindtorp, pizzas, deliveryAddress);
}
