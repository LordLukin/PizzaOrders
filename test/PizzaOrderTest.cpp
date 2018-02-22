#include <gtest/gtest.h>
#include "OrderSystem.h"
#include "Cash.h"
#include "DotPay.h"
#include "CreditCardSystem.h"
#include "PayPal.h"


using namespace std;

class PizzaOrderTest : public ::testing::Test
{

};

TEST_F(PizzaOrderTest, createNewInstance)
{
    OrderSystem& os = OrderSystem::instance();
}

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
    OrderSystem& os = OrderSystem::instance();
    os.selectPizzeria(BRAVO);
    ASSERT_TRUE(os.makeOrder({new Margherita{100.0}}, "some address"));
}

TEST_F(PizzaOrderTest, makeOrderWithNotAvailablePizza)
{
    OrderSystem& os = OrderSystem::instance();
    os.selectPizzeria(BRAVO);
    ASSERT_FALSE(os.makeOrder({new Funghi{100.0}}, "some address"));
}
