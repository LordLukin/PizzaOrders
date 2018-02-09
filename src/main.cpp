#include <iostream>
#include "Margherita.h"
#include "Funghi.h"
#include "Pizzeria.h"
#include "OrderSystem.h"

int main()
{
    Pizzas pizzas = { new Margherita{}, new Funghi{} };

    // 3 different pizzerias with different interfaces
    // refactor to facade
    Pizzeria vesuvio{ "Vesuvio - real Italian pizza" };
    Pizzeria bravo{"Bravo - good, because it's cheap"};

    OrderSystem os;
    os.makeOrder(vesuvio, pizzas);
    os.makeOrder(bravo, pizzas);

    system("PAUSE");
}
