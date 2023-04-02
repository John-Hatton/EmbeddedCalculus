//
// Created by John on 4/1/2023.
//
#pragma once


#include <include.h>
#include <PolyTerm.h>




template<typename Coefficient_t, typename Exponent_t>
class Polynomial {


private:
    std::vector<PolyTerm<Coefficient_t, Exponent_t>*> termsVector;
public:



public:

    Polynomial();
    ~Polynomial();
    static std::string trim(const std::string& str);
    static std::vector<std::string> split(const std::string& str, char delimiter);
    static Coefficient_t parseCoefficient(const std::string& str);
    static Exponent_t parseExponent(const std::string& str);
    void setFromString(std::string& str);

    const std::vector<PolyTerm<Coefficient_t, Exponent_t> *> &getTermsVector() const;

    void setTermsVector(const std::vector<PolyTerm<Coefficient_t, Exponent_t> *> &termsVector);

};













