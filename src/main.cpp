#include <iostream>
#include <set>
#include "Margherita.h"
#include "Funghi.h"
#include "Pizzeria.h"

int main()
{
    Pizza* margherita = new Margherita{};
    Pizza* funghi = new Funghi{};
    std::set<Pizza*> pizzas = { margherita };

    Pizzeria vesuvio;	// 3 different pizzerias with different interfaces
    					// refactor to facade
    vesuvio.makeOrder(pizzas);

    std::cout << "Hello World!" << std::endl;
    system("PAUSE");
}
