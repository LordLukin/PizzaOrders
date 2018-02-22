#include <gtest/gtest.h>
#include "OrderSystem.h"

using namespace std;

class PizzaOrderTest : public ::testing::Test
{

};


TEST_F(PizzaOrderTest, paymentByCashIsAlwaysSuccessfull)
{
    OrderSystem os ;
    os.selectPaymentMethod(CASH);
    ASSERT_TRUE(os.charge(20.0));
}

TEST_F(PizzaOrderTest, makeOrderInBravo)
{
    OrderSystem os;
    os.selectPizzeria(BRAVO);
    ASSERT_TRUE(os.makeOrder({new Margherita{100.0}}, "some address"));
}

TEST_F(PizzaOrderTest, makeOrderWithNotAvailablePizza)
{
    OrderSystem os;
    os.selectPizzeria(BRAVO);
    ASSERT_FALSE(os.makeOrder({new Funghi{100.0}}, "some address"));
}
