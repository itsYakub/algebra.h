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
    mat2 a = mat2zero(),
         b = mat2zero();
    mat2 expect = mat2zero();
    
    EXPECT_TRUE(mat2eq(expect, mat2add(a, b)));
}

/* more tests here... */
