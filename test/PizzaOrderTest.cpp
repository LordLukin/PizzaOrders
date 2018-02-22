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
    OrderSystem os(
    { {"Venezia - real Italian pizza", { Pizza{"Margherita", 100.0, minutes(3)}}},
      {"Bravo - good and cheap pizza", { Pizza{"Fungi", 80.0, minutes(4)}}},
      {"Grindtorp pizzeria - local pizza",
       { Pizza{"Margherita", 90.0, minutes(3)}, Pizza{"Funghi", 110.0, minutes(3)}}
      }}
    );
    os.selectPizzeria(Pizzerias::BRAVO);
    const PaymentStrategy& paybycash = PayByCash();
    ASSERT_TRUE(os.makeOrder( paybycash, {Pizza {"Fungi" , 100.0 , minutes (3)}}, "some address"));
}

TEST_F(PizzaOrderTest, makeOrderWithNotAvailablePizza)
{
    OrderSystem os(
    { {"Venezia - real Italian pizza", { Pizza{"Margherita", 100.0, minutes(3)}}},
      {"Bravo - good and cheap pizza", { Pizza{"Fungi", 80.0, minutes(4)}}},
      {"Grindtorp pizzeria - local pizza",
       { Pizza{"Margherita", 90.0, minutes(3)}, Pizza{"Funghi", 110.0, minutes(3)}}
      }}
    );
    os.selectPizzeria(Pizzerias::BRAVO);
    const PaymentStrategy& paybycash = PayByCash();
    ASSERT_FALSE(os.makeOrder(paybycash, {Pizza {"KebabPizza" , 100.0 , minutes (3)}}, "some address"));
}
