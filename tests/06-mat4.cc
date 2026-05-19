#include <gtest/gtest.h>
#
#define ALGEBRA_IMPLEMENTATION
#include "./../mat4.hpp"

int main(int ac, char **av) {
    ::testing::InitGoogleTest(&ac, av);
    return (RUN_ALL_TESTS());
}

/* mat4add */

GTEST_TEST(mat4add, zero_identity) {
    mat4 a = mat4zero(),
         b = mat4zero();
    mat4 expect = mat4zero();
    
    EXPECT_TRUE(mat4eq(expect, mat4add(a, b)));
}

/* more tests here... */
