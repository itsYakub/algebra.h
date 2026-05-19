#include <gtest/gtest.h>
#
#define ALGEBRA_IMPLEMENTATION
#include "./../vec3.hpp"

int main(int ac, char **av) {
    ::testing::InitGoogleTest(&ac, av);
    return (RUN_ALL_TESTS());
}

/* vec3add */

GTEST_TEST(vec3add, zero_identity) {
    vec3 a = { .x = 0.0, .y = 0.0, .z = 0.0 },
         b = { .x = 0.0, .y = 0.0, .z = 0.0 };
    vec3 expect = { .x = 0.0, .y = 0.0, .z = 0.0 };
    
    EXPECT_TRUE(vec3eq(expect, vec3add(a, b)));
}

/* more tests here... */
