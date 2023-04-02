//
// Created by John on 4/1/2023.
//
#include <gtest/gtest.h>

#include "../../src/Polynomial.cpp"

TEST(MyPolynomial_Tests, MyPolynomial_ParseCoefficient_Function_Test01) {

    // 1. Setup
    auto poly = new Polynomial<int,int>();

    // 2. Code
    std::string test = "x^2";
    int result = poly->parseCoefficient(test);


    // 3. Result
    EXPECT_EQ(result, 1);
}

TEST(MyPolynomial_Tests, MyPolynomial_ParseCoefficient_Function_Test02) {

    // 1. Setup
    auto poly = new Polynomial<int,int>();

    // 2. Code
    std::string test = "2x^2";
    int result = poly->parseCoefficient(test);


    // 3. Result
    EXPECT_EQ(result, 2);
}

TEST(MyPolynomial_Tests, MyPolynomial_ParseCoefficient_Function_Test03) {

    // 1. Setup
    auto poly = new Polynomial<int,int>();

    // 2. Code
    std::string test = "-4x^2";
    int result = poly->parseCoefficient(test);


    // 3. Result
    EXPECT_EQ(result, -4);
}