#include <gtest/gtest.h>
#
#define ALGEBRA_IMPLEMENTATION
#include "./../vec3.hpp"

int main(int ac, char **av) {
    ::testing::InitGoogleTest(&ac, av);
    return (RUN_ALL_TESTS());
}

/* more tests here... */
