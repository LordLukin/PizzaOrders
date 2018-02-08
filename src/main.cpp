#include <iostream>
#include "Margherita.h"
#include "Funghi.h"
#include "Pizzeria.h"
#include "OrderSystem.h"

int main()
{
    Pizza* margherita = new Margherita{};
    Pizza* funghi = new Funghi{};
    Pizzas pizzas = { margherita, funghi };

    Pizzeria vesuvio{"Vesuvio - real Italian pizza"};   // 3 different pizzerias with different interfaces
                                                        // refactor to facade

    OrderSystem os;
    os.makeOrder(vesuvio, pizzas);

    delete margherita;
    delete funghi;

    std::cout << "Hello World!" << std::endl;
    system("PAUSE");
}
