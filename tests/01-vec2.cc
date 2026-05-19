#include <gtest/gtest.h>
#
#define ALGEBRA_IMPLEMENTATION
#include "./../vec2.hpp"

int main(int ac, char **av) {
    ::testing::InitGoogleTest(&ac, av);
    return (RUN_ALL_TESTS());
}

/* vec2add */

GTEST_TEST(vec2add, zero_identity) {
    vec2 a = { .x = 0.0, .y = 0.0 },
         b = { .x = 0.0, .y = 0.0 };
    vec2 expect = { .x = 0.0, .y = 0.0 };
    
    EXPECT_TRUE(vec2eq(expect, vec2add(a, b)));
}

/* more tests here... */
