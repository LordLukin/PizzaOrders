# PizzaOrders [![Build Status](https://www.travis-ci.org/LordLukin/PizzaOrders.svg?branch=master)](https://www.travis-ci.org/LordLukin/PizzaOrders)

Step 1: Identify as much system vulnerabilities as you can (~15 minutes)
Step 2: Compare your findings with other participants (~10 minutes)
Step 3: Presentation from STUPID to SOLID code.
Step 4: Create a common list of problems (~5 minutes)
Step 5: Plan your work. Assign priority numbers to problems (~15 minutes)
Step 6: Plan checkpoints every 1-1.5 hour and what should be done by then
Step 7: Work in a coding-dojo mode. Change every 5-7 minutes.
Step 8: Stop for a while on checkpoints. Check if you follow the plan. Adjust the plan if necessary.
Step 9: Finish after 6 hours of coding. It's time for discussion, repetition and the summary of refactoring
        techniques that you used and if they worked or not.

### Things to repair:
* Singleton in OrderSystem
* Tight coupling of Ingredients to Pizza, Pizza to Pizzeria, Pizzeria to OrderSystem
* Untestability. Fixing Tight coupling should make code unit testable
* Premature optimization. This code was not optimized. Even prematurely :) Applying design pattern instantly usually is a premature optimisation
* Indescriptive Naming. It's really not a work for a programmer.
  Some linguist student can rename variables, functions, etc. You have been spared :)
* Duplication of pizzerias in OrderSystem. But there is no duplicated code.

### Things to apply:
* SRP - Single Responsibility Principle - OrderSystem is a god class. Many things should be extracted.
* OCP - Open Close Principle. Remove Tight Coupling.
        OrderSystem should not own Pizzerias objects. It's difficult to add a new Pizzeria.
        Pizzas should be extensible. A client should be able to add more ingredients to pizza.
* LSP - Liskov Substitution Principle. Not a problem in current code. Abstraction is ok everywhere.
* ISP - Interface Segregation Principle. OrderSystem should have its interfaces segregated.
        There should be: payment specific function, pizzeria specific functions and maybe order specific?
        Pizzeria should have order specific functions and delivery specific ones. Maybe also pizza specific?
* DIP - Dependency Inversion Principle. Classes own objects of another classes only if it is justified.
        Generally, they should own interfaces. You can substitute any object (especially mock for testing)
        if you want to change the owned object.
        To add: IPizzeria, IPizza, IAnythingThatWasCreatedDuringExtractionFromOrderSystem :)

### Design Patterns:
https://sourcemaking.com/design_patterns
* Decorator - for adding more ingredients and/or sauce to pizza and calculating new price. Pizza should inherit
* Strategy - for different payment options. Create IPaymentOption interface.
             Then create specific payment options that inherit this interface. There should be a
             map<PaymentOptionEnum, IPaymentOption> m, which will invoke proper function for selected option.
             A specific call will look like this: m[DOTPAY]->charge(price); but in your code Enum should be passed as
             a parameter and the call will be generic: m[selectedPayment]->charge(price);
* Observer - for asynchronous call of makePayment or charge function?
* Facade - payment systems have different interaces. They are now hidden in facade - charge() function

### Design Antipatterns:
https://sourcemaking.com/antipatterns
* God class - OrderSystem
* Dead code - Ingredient

### Code refactoring:
https://sourcemaking.com/refactoring/refactorings
1. Formatting - clang-format, qtCreator. Egyptian braces, Allman braces, spaces vs tabs
2. Naming convention - lowerCamelCase, UpperCamelCase, snake_case?
3. Move the implementation from header to cpp files (CreditCardSystem.h, DotPay.h, PayPal.h)
4. Remove the dead code from Ingredient
5. Write Unit tests for one class, refactor the class, and only then work on other classes

### General coding rules:
* Goal: no comments at all (at least those describing the code). The code should be self-documenting.
* Const correctness (functions and params)
* RAII (acquire in constructor)
* Variables should always be initialized
* Get rid of memory leaks
* Use STL
* Remember about virtual destructors
* Additionally, if time allows: keyboard input validation (use of exceptions?)
* You should never use any Design Pattern just because you think it should (or will) match there. It's premature optimisation.
  You should refactor the code to some design pattern only if you can see that it has a specific form with specific issues,
  for which the design pattern was created
