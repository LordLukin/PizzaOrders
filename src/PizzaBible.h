#pragma once
#include "IPizza.h"
#include <memory>
#include "Mushrooms.h"
#include "Mozzarella.h"
#include "Ham.h"

enum class PizzaType {
    Capriciosa,
    Margherita,
    Funghi
};

class PizzaBible {
public:
    IPizza* makePizza(PizzaType pizzaType) {
        switch (pizzaType) {
        case PizzaType::Capriciosa:
            return new Ham{ new Pizza{} };
        case PizzaType::Funghi:
            return new Mushrooms{ new Pizza{} };
        case PizzaType::Margherita:
            return new Mozzarella{ new Pizza{} };
        }
    }

};
