#include <iostream>
#include "Margherita.h"
#include "Funghi.h"
#include "Pizzeria.h"
#include "OrderSystem.h"

int main()
{
    Pizzas pizzas = {new Margherita{}, new Funghi{}};

    // To break: 3 different pizzerias with different interfaces. Refactor to facade
    Pizzeria venezia{"Venezia - real Italian pizza"};
    Pizzeria bravo{"Bravo - good and cheap pizza"};
    Pizzeria grindtorp{"Grindtorp pizzeria - local pizza"};

    std::string deliveryAddress{"Nytorpsvagen 9, 183 03 Taby, Sweden"};

    // To break: pizzerias added via add method. Add a constructor
    OrderSystem& os = OrderSystem::instance();
    os.makeOrder(grindtorp, pizzas, deliveryAddress);

    system("PAUSE");
}
