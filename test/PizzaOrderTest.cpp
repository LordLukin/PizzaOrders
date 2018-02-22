#include <gtest/gtest.h>
#include "OrderSystem.h"
#include "Cash.h"
#include "DotPay.h"
#include "CreditCardSystem.h"
#include "PayPal.h"


using namespace std;

class PizzaOrderTest : public ::testing::Test
{
public:
    void SetUp() override
    {
        pizzerias_.insert(std::make_pair(PizzeriaKey::VENEZIA, Pizzeria{"Venezia - real Italian pizza", {new Funghi{100.0}}}));
        pizzerias_.insert(std::make_pair(PizzeriaKey::BRAVO, Pizzeria{"Bravo - good and cheap pizza", {new Margherita{80.0}}}));
        pizzerias_.insert(std::make_pair(PizzeriaKey::GRINDTORP, Pizzeria{"Grindtorp pizzeria - local pizza", {new Margherita{90.0}, new Funghi{110.0}}}));
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
    ASSERT_TRUE(os.makeOrder({new Margherita{100.0}}, "some address"));
}

TEST_F(PizzaOrderTest, makeOrderWithNotAvailablePizza)
{
    OrderSystem os(pizzerias_);
    os.selectPizzeria(PizzeriaKey::BRAVO);
    ASSERT_FALSE(os.makeOrder({new Funghi{100.0}}, "some address"));
}
