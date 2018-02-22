#include <gtest/gtest.h>
#include "OrderSystem.h"
#include "Cash.h"
#include "DotPay.h"
#include "CreditCardSystem.h"
#include "PayPal.h"
#include "Pizza.h"
#include "IPizza.h"
#include "Mozzarella.h"
#include "Mushrooms.h"
#include "Ham.h"
#include "PizzaBible.h"


using namespace std;

class PizzaOrderTest : public ::testing::Test
{
public:
    void SetUp() override
    {
        pizzerias_.insert(std::make_pair(PizzeriaKey::VENEZIA, Pizzeria{"Venezia - real Italian pizza", {new Pizza{}}}));
        pizzerias_.insert(std::make_pair(PizzeriaKey::BRAVO, Pizzeria{"Bravo - good and cheap pizza", {new Pizza{}}}));
        pizzerias_.insert(std::make_pair(PizzeriaKey::GRINDTORP, Pizzeria{"Grindtorp pizzeria - local pizza", {new Pizza{}}}));
    }

    std::map<PizzeriaKey, Pizzeria> pizzerias_;
};

/*TEST_F(PizzaOrderTest, paymentByCreditIsAlwaysSuccessfull)
{
    CreditCardSystem credit;
    ASSERT_TRUE(credit.charge(20.0));
}*/


/*TEST_F(PizzaOrderTest, paymentByDotPayIsAlwaysSuccessfull)
{
    DotPay dotpay;
    ASSERT_TRUE(dotpay.charge(20.0));
}*/

TEST_F(PizzaOrderTest, paymentByCashIsAlwaysSuccessfull)
{
    Cash cash;
    ASSERT_TRUE(cash.charge(20.0));
}

/*TEST_F(PizzaOrderTest, paymentByPayPalIsAlwaysSuccessfull)
{
    PayPal paypal;
    ASSERT_TRUE(paypal.charge(20.0));
}*/

TEST_F(PizzaOrderTest, makeOrderInBravo)
{
    OrderSystem os(pizzerias_);
    os.selectPizzeria(PizzeriaKey::BRAVO);
    ASSERT_TRUE(os.makeOrder({new Pizza{}}, "some address"));
}

TEST_F(PizzaOrderTest, makeOrderWithNotAvailablePizza)
{
    OrderSystem os(pizzerias_);
    os.selectPizzeria(PizzeriaKey::BRAVO);
    Pizza p;
    Mozzarella m(&p);
    ASSERT_FALSE(os.makeOrder({&m, &m}, "some address"));
}

TEST_F(PizzaOrderTest, makeBasePizza)
{
    Pizza p;
//    std::cout << "Bake time, pizza" << p.getBakingTime();
    std::cout << p.toString() << std::endl;
    std::cout << "Price, pizza: " << p.getPrice() << std::endl;
}

TEST_F(PizzaOrderTest, makeMozzarellaPizza)
{
    Pizza p;
    Mozzarella m(&p);
    std::cout << m.toString() << std::endl;
    std::cout << "Price, mozzarella pizza: " << m.getPrice() << std::endl;
}

TEST_F(PizzaOrderTest, makeSuperPizza)
{
    Pizza p;
    Mozzarella m(&p);
    Ham h(&m);
    Mushrooms mushrooms(&h);
    std::cout << mushrooms.toString() << std::endl;
    std::cout << "Price, super pizza: " << mushrooms.getPrice() << std::endl;
}

TEST_F(PizzaOrderTest, makeCapricosaPizza)
{
    IPizza* cap = PizzaBible().makePizza(PizzaType::Capriciosa);

    std::cout << cap->toString() << std::endl;
    std::cout << "Price, super pizza: " << cap->getPrice() << std::endl;
}
