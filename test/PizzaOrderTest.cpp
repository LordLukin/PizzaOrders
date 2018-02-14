#include <gtest/gtest.h>

using namespace std;

class Fixture : public ::testing::Test
{

};

TEST_F(Fixture, Dummy)
{
    ASSERT_TRUE(false);
}
