////
//// Created by John on 3/30/2023.
////
//#pragma once
//
//
//#include <vector>
//#include <string>
//#include <iostream>
//
//
//class Polynomial {
//
//private:
//
//
//    // Highest order term
//    // vector of exponents, in decreasing order
//    // vector of coefficients
//
//
//    float highestOrderTerm;
//
//    std::vector<std::pair<float, float>> termsVector;
//
//    std::string functionRepresentation;
//
//public:
//
//    Polynomial();
//
//    ~Polynomial();
//
//
//    // setFunction
//
//    void setFunction(std::string fOfX);
//
//    std::vector<std::pair<float, float>> checkFunction(std::string inputString);
//
//    // printFunction()
//
//    void printFunction();
//
//
//    // getRoots()
//
//    // derivative()
//
//    // integral()
//
//    // criticalPoints()
//
//    //
//
//
//    float getHighestOrderTerm() const;
//
//    void setHighestOrderTerm(float highestOrderTerm);
//
//    const std::vector<std::pair<float, float>> &getTermsVector() const;
//
//    void setTermsVector(const std::vector<std::pair<float, float>> &termsVector);
//
//    const std::string &getFunctionRepresentation() const;
//
//    void setFunctionRepresentation(const std::string &functionRepresentation);
//
//
//


#include <map>
#include <string>
#include <vector>

template <typename CoeffType, typename ExponentType>
class Polynomial {
private:
    CoeffType leadingCoefficient;
    std::map<ExponentType, CoeffType> coefficients;
public:
    const std::map<ExponentType, CoeffType> &getCoefficients() const {
        return coefficients;
    }

    void setCoefficients(const std::map<ExponentType, CoeffType> &coefficients) {
        Polynomial::coefficients = coefficients;
    }

    const std::vector<std::pair<CoeffType, ExponentType>> &getTerms() const {
        return terms;
    }

    void setTerms(const std::vector<std::pair<CoeffType, ExponentType>> &terms) {
        Polynomial::terms = terms;
    }

private:

    std::vector<std::pair<CoeffType, ExponentType>> terms;

public:
    Polynomial();
    Polynomial(CoeffType leadingCoefficient, const std::map<ExponentType, CoeffType>& coeffs);
    explicit Polynomial(const std::string& str);

    // getters and setters for leadingCoefficient and coefficients

    // arithmetic operations
    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;
    Polynomial operator/(const Polynomial& other) const;

    // evaluation function
    CoeffType evaluate(CoeffType x) const;

    // differentiation function
    Polynomial<CoeffType, ExponentType> differentiate() const;

    // string representation function
    std::string toString() const;

    // utility functions for parsing input strings
    static std::string trim(const std::string& str);
    static std::vector<std::string> split(const std::string& str, char delimiter);
    static CoeffType parseCoefficient(const std::string& str);
    static ExponentType parseExponent(const std::string& str);
    void setFromString(const std::string& str);



};


























