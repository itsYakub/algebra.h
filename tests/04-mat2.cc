#include <gtest/gtest.h>
#
#define ALGEBRA_IMPLEMENTATION
#include "./../mat2.hpp"

int main(int ac, char **av) {
    ::testing::InitGoogleTest(&ac, av);
    return (RUN_ALL_TESTS());
}

/* mat2add */

GTEST_TEST(mat2add, zero_identity) {
    mat2 a = { 0 },
         b = { 0 };
    mat2 expect = { 0 };
    
    EXPECT_TRUE(mat2eq(expect, mat2add(a, b)));
}

/* more tests here... */
