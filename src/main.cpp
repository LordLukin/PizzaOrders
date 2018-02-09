#include <iostream>
#include "Margherita.h"
#include "Funghi.h"
#include "Pizzeria.h"
#include "OrderSystem.h"

int main()
{
    Pizzas pizzas = {new Margherita{}, new Funghi{}};

    // To break: 3 different pizzerias with different interfaces. Refactor to facade
    Pizzeria vesuvio{"Vesuvio - real Italian pizza"};
    Pizzeria bravo{"Bravo - good, because it's cheap"};
    Pizzeria grubyBenek{"Gruby Benek - Wroclaw's pizza"};

    // To break: pizzerias added via add method. Add a constructor
    OrderSystem os{};
    os.makeOrder(vesuvio, pizzas);
    os.makeOrder(grubyBenek, pizzas);

    system("PAUSE");
}