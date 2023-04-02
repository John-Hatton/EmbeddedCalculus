//
// Created by John on 4/1/2023.
//
#include <gtest/gtest.h>

#include "../../src/Polynomial.cpp"

TEST(MyPolynomial_Tests, MyPolynomial_Trim_Function_Test01) {

    // 1. Setup
    auto poly = new Polynomial<int,int>();

    // 2. Code
    std::string test = " this is a test ";

    std::string result = poly->trim(test);

    // 3. Result
    EXPECT_EQ(result, "this is a test");
}

TEST(MyPolynomial_Tests, MyPolynomial_Trim_Function_Test02) {

    // 1. Setup
    Polynomial<int, int>* poly = new Polynomial<int,int>();

    // 2. Code
    std::string test = " x^2 ";

    std::string result = poly->trim(test);

    // 3. Result
    EXPECT_EQ(result, "x^2");
}
