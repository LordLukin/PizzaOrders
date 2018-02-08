#include <iostream>
#include "Margherita.h"
#include "Funghi.h"
#include "Pizzeria.h"
#include "OrderSystem.h"

int main()
{
    Pizza* margherita = new Margherita{};
    Pizza* funghi = new Funghi{};
    Pizzas pizzas = { margherita };

    Pizzeria vesuvio;   // 3 different pizzerias with different interfaces
                        // refactor to facade

    OrderSystem os;
    os.makeOrder(vesuvio, pizzas);

    std::cout << "Hello World!" << std::endl;
    system("PAUSE");
}
