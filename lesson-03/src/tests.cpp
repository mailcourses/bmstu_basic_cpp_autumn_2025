#include "utils.hpp"

#include <gtest/gtest.h>

TEST(Utils, foo_test)
{
    EXPECT_EQ(-10, foo(2)); //<-- не работает
    ASSERT_EQ(1, foo(1));
}

class UtilsTest : public ::testing::Test
{
protected:
    void SetUp()
    {
        std::cout << "UtilsTest::SetUp" << std::endl;
    }

    void TearDown()
    {
        std::cout << "UtilsTest::TearDown" << std::endl;
    }
};

TEST_F(UtilsTest, foo_test_f)
{
    std::cout << "foo_test_f" << std::endl;
    ASSERT_EQ(1, foo(1));
}

TEST_F(UtilsTest, foo_test_g)
{
    std::cout << "foo_test_g" << std::endl;
    ASSERT_EQ(1, foo(1));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

