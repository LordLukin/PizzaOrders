#include <gtest/gtest.h>
#include "OrderSystem.h"
#include<string>
#include "paybycash.h"


using namespace std;

class PizzaOrderTest : public ::testing::Test
{

};


TEST_F(PizzaOrderTest, paymentByCashIsAlwaysSuccessfull)
{
    const PaymentStrategy& paybycash = PayByCash();
    ASSERT_TRUE(paybycash.charge((20.0)));
}

TEST_F(PizzaOrderTest, makeOrderInBravo)
{
    OrderSystem os;
    os.selectPizzeria(Pizzerias::BRAVO);
    const PaymentStrategy& paybycash = PayByCash();
    ASSERT_TRUE(os.makeOrder( paybycash, {Pizza {"Fungi" , 100.0 , minutes (3)}}, "some address"));
}

TEST_F(PizzaOrderTest, makeOrderWithNotAvailablePizza)
{
    OrderSystem os;
    os.selectPizzeria(Pizzerias::BRAVO);
    const PaymentStrategy& paybycash = PayByCash();
    ASSERT_FALSE(os.makeOrder(paybycash, {Pizza {"KebabPizza" , 100.0 , minutes (3)}}, "some address"));
}
