//
// Created by John on 4/1/2023.
//

#include "PolyTerm.h"

template<typename Coefficient_t, typename Exponent_t>
bool PolyTerm<Coefficient_t, Exponent_t>::isNegativeTerm() const {
    return negativeTerm;
}

template<typename Coefficient_t, typename Exponent_t>
void PolyTerm<Coefficient_t, Exponent_t>::setNegativeTerm(bool negativeTerm) {
    PolyTerm::negativeTerm = negativeTerm;
}

template<typename Coefficient_t, typename Exponent_t>
Coefficient_t PolyTerm<Coefficient_t, Exponent_t>::getCoefficient() const {
    return coefficient;
}

template<typename Coefficient_t, typename Exponent_t>
void PolyTerm<Coefficient_t, Exponent_t>::setCoefficient(Coefficient_t coefficient) {
    PolyTerm::coefficient = coefficient;
}

template<typename Coefficient_t, typename Exponent_t>
Exponent_t PolyTerm<Coefficient_t, Exponent_t>::getExponent() const {
    return exponent;
}


template<typename Coefficient_t, typename Exponent_t>
void PolyTerm<Coefficient_t, Exponent_t>::setExponent(Exponent_t exponent) {
    PolyTerm::exponent = exponent;
}

template<typename Coefficient_t, typename Exponent_t>
const std::string &PolyTerm<Coefficient_t, Exponent_t>::getStringRep() const {
    return stringRep;
}

template<typename Coefficient_t, typename Exponent_t>
void PolyTerm<Coefficient_t, Exponent_t>::setStringRep(const std::string &stringRep) {
    PolyTerm::stringRep = stringRep;
}