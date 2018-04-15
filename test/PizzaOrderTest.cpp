#include <gtest/gtest.h>
#include "OrderSystem.h"
#include "TimeMock.h"

using namespace std;

class PizzaOrderTest : public ::testing::Test
{
public:
    TimeMock* tm = new TimeMock();
    OrderSystem os{tm};
};


TEST_F(PizzaOrderTest, paymentByCashIsAlwaysSuccessfull)
{
    os.selectPaymentMethod(CASH);
    ASSERT_TRUE(os.charge(20.0));
}

TEST_F(PizzaOrderTest, makeOrderInBravo)
{
    os.selectPizzeria(BRAVO);
    ASSERT_TRUE(os.makeOrder({new Margherita{100.0}}, "some address"));
}

TEST_F(PizzaOrderTest, makeOrderWithNotAvailablePizza)
{
    //using namespace testing;
    //EXPECT_CALL(*tm, waitForDelivery(_)).WillOnce(Return(true));
    os.selectPizzeria(BRAVO);
    ASSERT_FALSE(os.makeOrder({new Funghi{100.0}}, "some address"));
}
