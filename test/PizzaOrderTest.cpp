#include <gtest/gtest.h>
#include "OrderSystem.h"

using namespace std;

class PizzaOrderTest : public ::testing::Test
{

};

TEST_F(PizzaOrderTest, createNewInstance)
{
    OrderSystem& os = OrderSystem::instance();
}
