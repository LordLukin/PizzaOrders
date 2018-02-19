# PizzaOrders [![Build Status](https://www.travis-ci.org/LordLukin/PizzaOrders.svg?branch=master)](https://www.travis-ci.org/LordLukin/PizzaOrders)

## The story so far...
You has been hired as a software engineer in TastyPizza company. It's ordering system was written by a student
and it's suffering severe issues with performance. Moreover it cannot handle multiple users.
There were also situations that clients paid for an order, but order was lost.
Unfortunately the author of the system is no longer working here and he is not answering his phone.
Your task is to improve the system to work with multiple users and make it extansible for futher
features and improvements. You have only 8 hours.

1. Step 1: Identify as much system vulnerabilities as you can
2. Step 2: Write some tests
3. Step 3: Fix problems
4. Step 4: Refactor the code to be maintenable.
5. Step 5: Go to step 2

### Things to break:
+ Singleton in OrderSystem
+ Tight coupling of Ingredients from Pizza, Pizza from Pizzeria, Pizzeria from OrderSystem
* Untestability. Add System Test. Fixing Tight coupling should make code unit testable
* Premature optimization. Think about it in the end.
* Indescriptive Naming. Introduce in the end.
* Duplication in pizzas and pizzerias.

### Things to fix:
* SRP - Order class should be extracted from OrderSystem. Pizzeria should be extracted from OrderSystem? OrderSystem god class?
* OCP - Remove Tight Coupling. Create Pizza base class, to easily add new pizzas and not operate on existing ones.
* LSP - 
* ISP - 
* DIP -

### Design Patterns to apply:
* Decorator - for adding more ingredients and/or sauce to pizza and calculating price
* Facade - payment systems have different interaces. They should be hidden in facade.
* Observer - for asynchronous call of makePayment or charge function?
* Strategy - inside Facade - if pizzeria == 1, do this, pizzeria2 do that, etc.

### Design Antipatterns:
* God class - OrderSystem
* Dead code - Ingredient
* Copy & Paste - OrderSystem

### Code refactoring:
1. Formatting - clang-format, qtCreator. Egyptian braces, Allman braces, spaces vs tabs
2. Naming convention - lowerCamelCase, UpperCamelCase, snake_case?
3. Move implementation from header to cpp files (CreditCardSystem.h, DotPay.h,
3. Remove the dead code from Ingredient
4. Write Unit tests for 1 class, refactor class, repeat for another ones
5. Remove coupling (DIP)


### General coding rules:
* Goal: no comments at all (at least those describing the code). Code should be self-documenting.
* Const correctness (functions and params)
* RAII (acquire in constructor)
* Variables should always be initialized
* Get rid of Memory leaks
* Use STL
* Additionaly, if time allows: keyboard input validation (use of exceptions?)
