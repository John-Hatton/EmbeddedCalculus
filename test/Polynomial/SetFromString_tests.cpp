//
// Created by John on 4/1/2023.
//
#include <gtest/gtest.h>

#include "../../src/Polynomial.cpp"

TEST(MyPolynomial_Tests, MyPolynomial_SetFromString_Function_Test01) {

    // 1. Setup
    auto poly = new Polynomial<int,int>();

    // 2. Code
    std::string test = "x^2-2x";
    poly->setFromString(test);



    //int result = poly->parseExponent(parts[1]); // part[1] contains the exponent after the carrot


    // 3. Result
    EXPECT_EQ(2, 2);
}

TEST(MyPolynomial_Tests, MyPolynomial_SetFromString_Function_Test02) {

    // 1. Setup
    auto poly = new Polynomial<int,int>();

    // 2. Code
    std::string test = "x^4-3x^3+2x^2-5";
    poly->setFromString(test);



    //int result = poly->parseExponent(parts[1]); // part[1] contains the exponent after the carrot


    // 3. Result
    EXPECT_EQ(poly->getTermsVector()[0]->getStringRep(), "x^4");
}