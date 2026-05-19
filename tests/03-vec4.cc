#include <gtest/gtest.h>
#
#define ALGEBRA_IMPLEMENTATION
#include "./../vec4.hpp"

int main(int ac, char **av) {
    ::testing::InitGoogleTest(&ac, av);
    return (RUN_ALL_TESTS());
}

/* vec4add */

GTEST_TEST(vec4add, zero_identity) {
    vec4 a = { .x = 0.0, .y = 0.0, .z = 0.0, .w = 0.0 },
         b = { .x = 0.0, .y = 0.0, .z = 0.0, .w = 0.0 };
    vec4 expect = { .x = 0.0, .y = 0.0, .z = 0.0, .w = 0.0 };
    
    EXPECT_TRUE(vec4eq(expect, vec4add(a, b)));
}

/* more tests here... */
