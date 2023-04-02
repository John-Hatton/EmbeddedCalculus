//
// Created by John on 4/1/2023.
//
#pragma once

#include <include.h>


template<typename Coefficient_t, typename Exponent_t>
class PolyTerm {


private:

    bool negativeTerm;
public:


private:
    Coefficient_t coefficient;
    Exponent_t exponent;
    std::string stringRep;


public:

    PolyTerm() = default;
    ~PolyTerm() = default;

    bool isNegativeTerm() const;

    void setNegativeTerm(bool negativeTerm);

    Coefficient_t getCoefficient() const;

    void setCoefficient(Coefficient_t coefficient);

    Exponent_t getExponent() const;

    void setExponent(Exponent_t exponent);

    const std::string &getStringRep() const;

    void setStringRep(const std::string &stringRep);

};