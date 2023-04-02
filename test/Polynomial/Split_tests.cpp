//
// Created by John on 4/1/2023.
//
#include <gtest/gtest.h>

#include "../../src/Polynomial.cpp"

TEST(MyPolynomial_Tests, MyPolynomial_Split_Function_Test01) {

    // 1. Setup
    auto poly = new Polynomial<int,int>();

    // 2. Code
    std::string test = "x^2";
    std::vector<std::string> result = poly->split(test, '^');


    // 3. Result
    EXPECT_EQ(result[0], "x");
    EXPECT_EQ(result[1], "2");
}

TEST(MyPolynomial_Tests, MyPolynomial_Split_Function_Test02) {

    // 1. Setup
    auto poly = new Polynomial<int,int>();

    // 2. Code
    std::string test = "4x^5";
    std::vector<std::string> result = poly->split(test, '^');


    // 3. Result
    EXPECT_EQ(result[0], "4x");
    EXPECT_EQ(result[1], "5");
}