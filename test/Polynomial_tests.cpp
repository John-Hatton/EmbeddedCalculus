//
// Created by John on 3/30/2023.
//

#include <gtest/gtest.h>
#include <unistd.h>

#include "../src/Polynomial.cpp"

namespace {

    // Initialize Objects Here

    Polynomial<int,int>* poly;

    class Polynomial_Tests : public ::testing::Test {

    protected:
        void SetUp() override {

            poly = new Polynomial<int, int>();
        }

        void TearDown() override {
            poly = nullptr;
        }
    };

    TEST_F(Polynomial_Tests, Polynomial_Set_Function_Test01) {
        //Test

        // Get value created by setup
        poly->setFromString("x^2");

        std::stringstream expected;
        expected << "x^2";


        EXPECT_EQ(expected.str(), poly->toString());
    }

    TEST_F(Polynomial_Tests, Polynomial_Set_Function_Test02) {
        //Test

        // Get value created by setup
        poly->setFromString("1x^2");

        std::stringstream expected;
        expected << "x^2";


        EXPECT_EQ(expected.str(), poly->toString());
    }

    TEST_F(Polynomial_Tests, Polynomial_Set_Function_Test03) {
        //Test

        // Get value created by setup
        poly->setFromString("x^2+3x+1");

        std::stringstream expected;
        expected << "x^2+3x+1";


        EXPECT_EQ(expected.str(), poly->toString());
    }

    TEST_F(Polynomial_Tests, Polynomial_Set_Function_Test04) {
        //Test

        // Get value created by setup
        poly->setFromString("4x^3+2x+1");

        std::cout << "The Coefficient of the leading term is: ";
        std::cout << poly->getTerms()[0].first;
        std::cout <<"\nThe Exponent of the leading term is: ";
        std::cout << poly->getTerms()[0].first;
        std::stringstream expected;
        expected << "4x^3+2x+1";


        EXPECT_EQ(expected.str(), poly->toString());
    }
}

TEST_F(Polynomial_Tests, Polynomial_Set_Function_Test05) {
    //Test

    // Get value created by setup
    poly->setFromString("-x^2");

    std::stringstream expected;
    expected << "-x^2";


    EXPECT_EQ(expected.str(), poly->toString());
}

TEST_F(Polynomial_Tests, Polynomial_Set_Function_Test06) {
    //Test

    // Get value created by setup
    poly->setFromString("x^2-3x+1");

    std::stringstream expected;
    expected << "x^2-3x+1";


    EXPECT_EQ(expected.str(), poly->toString());
}