# PizzaOrders [![Build Status](https://www.travis-ci.org/LordLukin/PizzaOrders.svg?branch=master)](https://www.travis-ci.org/LordLukin/PizzaOrders)


### Things to break:
* Singleton in OrderSystem
* Tight coupling of Ingredients from pizza and somewhere else
* Untestability. Add System Test. Fixing Tight coupling should make code unit testable
* Premature optimization. Think about it in the end.
* Indescriptive Naming. Introduce in the end.
* Duplication in pizzas and pizzerias.

### General coding rules:
* Const correctness (functions and params)
* RAII (acquire in constructor)
* Code formatting
* Get rid of Memory leaks
* Use STL

### Things to fix:
* SRP - Order class should be extracted from OrderSystem. Pizzeria should be extracted from OrderSystem? OrderSystem god class?
* OCP - Remove Tight Coupling. Create Pizza base class, to easily add new pizzas and not operate on existing ones.
* LSP - 
* ISP - 
* DIR - 

### Design Patterns to apply:
* Decorator - for adding more ingredients and/or sauce to pizza and calculating price
* Facade - pizzerias have different interaces. They should be hidden in facade.
* Observer - for asynchronous call of makePayment or charge function?
* Strategy - inside Facade - if pizzeria == 1, do this, pizzeria2 do that, etc.

### Design Antipatterns:
* God class - OrderSystem to split
* Dead code - put it somewhere
* Copy & Paste - Pizzas to remove duplication