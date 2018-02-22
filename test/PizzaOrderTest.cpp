#include <gtest/gtest.h>
#include "OrderSystem.h"
#include<string>

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
    ASSERT_TRUE(os.makeOrder( {Pizza {"Fungi" , 100.0 , minutes (3)}}, "some address"));
}

TEST_F(PizzaOrderTest, makeOrderWithNotAvailablePizza)
{
    OrderSystem os;
    os.selectPizzeria(BRAVO);
    ASSERT_FALSE(os.makeOrder( {Pizza {"KebabPizza" , 100.0 , minutes (3)}}, "some address"));
}
