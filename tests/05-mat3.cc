#include <gtest/gtest.h>
#
#define ALGEBRA_IMPLEMENTATION
#include "./../mat3.hpp"

int main(int ac, char **av) {
    ::testing::InitGoogleTest(&ac, av);
    return (RUN_ALL_TESTS());
}

/* mat3add */

GTEST_TEST(mat3add, zero_identity) {
    mat3 a = mat3zero(),
         b = mat3zero();
    mat3 expect = mat3zero();
    
    EXPECT_TRUE(mat3eq(expect, mat3add(a, b)));
}

/* more tests here... */
