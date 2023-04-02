//
// Created by John on 4/1/2023.
//
#include <gtest/gtest.h>

#include "../../src/Polynomial.cpp"

TEST(MyPolynomial_Tests, MyPolynomial_ParseExponent_Function_Test01) {

    // 1. Setup
    auto poly = new Polynomial<int,int>();

    // 2. Code
    std::string test = "x^2";
    int result = poly->parseExponent(test); // part[1] contains the exponent after the carrot


    // 3. Result
    EXPECT_EQ(result, 2);
}

TEST(MyPolynomial_Tests, MyPolynomial_ParseExponent_Function_Test02) {

    // 1. Setup
    auto poly = new Polynomial<int,int>();

    // 2. Code
    std::string test = "x^-2";
    int result = poly->parseExponent(test); // part[1] contains the exponent after the carrot


    // 3. Result
    EXPECT_EQ(result, -2);
}

TEST(MyPolynomial_Tests, MyPolynomial_ParseExponent_Function_Test03) {

    // 1. Setup
    auto poly = new Polynomial<int,int>();

    // 2. Code
    std::string test = "x^22";
    int result = poly->parseExponent(test); // part[1] contains the exponent after the carrot


    // 3. Result
    EXPECT_EQ(result, 22);
}

TEST(MyPolynomial_Tests, MyPolynomial_ParseExponent_Function_Test04) {

    // 1. Setup
    auto poly = new Polynomial<int,int>();

    // 2. Code
    std::string test = "x";
    int result = poly->parseExponent(test); // part[1] contains the exponent after the carrot


    // 3. Result
    EXPECT_EQ(result, 1); // I.e x^1
}

TEST(MyPolynomial_Tests, MyPolynomial_ParseExponent_Function_Test05) {

    // 1. Setup
    auto poly = new Polynomial<int,int>();

    // 2. Code
    std::string test = "5";
    int result = poly->parseExponent(test); // part[1] contains the exponent after the carrot


    // 3. Result
    EXPECT_EQ(result, 0); // I.e 5x^0
}

TEST(MyPolynomial_Tests, MyPolynomial_ParseExponent_Function_Test06) {

    // 1. Setup
    auto poly = new Polynomial<int,int>();

    // 2. Code
    std::string test = "-3x^3";
    int result = poly->parseExponent(test); // part[1] contains the exponent after the carrot


    // 3. Result
    EXPECT_EQ(result, 3); // I.e 5x^0
}