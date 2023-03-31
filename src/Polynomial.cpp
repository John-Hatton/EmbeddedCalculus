////
//// Created by John on 3/30/2023.
////
//
//#include <cstring>
//#include "Polynomial.h"
//
//Polynomial::Polynomial() {
//    termsVector = {std::make_pair(0.0,0.0)};
//
//}
//
//Polynomial::~Polynomial() {
//    termsVector = {};
//}
//
//void Polynomial::setFunction(std::string fOfX) {
//    // Perform checks on fOfX
//
//    std::vector<std::pair<float, float>> checkFcn = checkFunction(fOfX);
//
//    // for now, we shall set to fOfX;
//
//    functionRepresentation = fOfX;
//}
//
//std::vector<std::pair<float, float>> Polynomial::checkFunction(std::string inputString) {
//
//    // set values based on how many ^ we find.
//
//    for (int i = 0; i < inputString.size(); i++)
//    {
//        const char x[] = "x";
//        const char exp[] = "^";
//        if (reinterpret_cast<const char *>(inputString.at(i)) == x) //first character is x
//        {
//            if (reinterpret_cast<const char *>(inputString.at(i+1)) == exp) // Second character is ^
//            {
//                float tempTerm = 0.0;
//
//                char inputChar = inputString.at(i + 2);
//
//                tempTerm = (float) inputChar;
//                // We push 1, because we did not have a coefficient
//                termsVector.emplace_back(1.0, tempTerm);
//
//            }
//        }
//    }
//
//
//    return termsVector;
//}
//
//
//void Polynomial::printFunction() {
//
//    if (!functionRepresentation.empty())
//    {
//        std::cout << functionRepresentation;
//    }
//}
//
//float Polynomial::getHighestOrderTerm() const {
//    return highestOrderTerm;
//}
//
//void Polynomial::setHighestOrderTerm(float highestOrderTerm) {
//    Polynomial::highestOrderTerm = highestOrderTerm;
//}
//
//const std::vector<std::pair<float, float>> &Polynomial::getTermsVector() const {
//    return termsVector;
//}
//
//void Polynomial::setTermsVector(const std::vector<std::pair<float, float>> &termsVector) {
//    Polynomial::termsVector = termsVector;
//}
//
//const std::string &Polynomial::getFunctionRepresentation() const {
//    return functionRepresentation;
//}
//
//void Polynomial::setFunctionRepresentation(const std::string &functionRepresentation) {
//    Polynomial::functionRepresentation = functionRepresentation;
//}
//


#include <stdexcept>
#include <sstream>
#include "Polynomial.h"



////


//template <>
//inline double Polynomial<double, double>::parseCoefficient(const std::string& str) {
//    return std::stod(str);
//}
//
//// Template specialization for parsing coefficients as integers
//template <>
//inline int Polynomial<int, int>::parseCoefficient(const std::string& str) {
//    return std::stoi(str);
//}
//
//// Template specialization for parsing exponents as doubles
//template <>
//inline double Polynomial<double, double>::parseExponent(const std::string& str) {
//    return std::stod(str);
//}
//
//// Template specialization for parsing exponents as integers
//template <>
//inline int Polynomial<int, int>::parseExponent(const std::string& str) {
//    return std::stoi(str);
//}

//////////////// CONSTRUCTORS //////////

template<typename CoeffType, typename ExponentType>
Polynomial<CoeffType, ExponentType>::Polynomial() = default;

template<typename CoeffType, typename ExponentType>
Polynomial<CoeffType, ExponentType>::Polynomial(CoeffType lc, const std::map<ExponentType, CoeffType> &coeffs) {

}

//template<typename CoeffType, typename ExponentType>
//Polynomial<CoeffType, ExponentType>::Polynomial(const std::string &str) {
//    // Parse the input string into individual terms
//    std::vector<std::string> terms = split(trim(str), '+');
//
//    // Iterate over the terms and parse each one
//    for (const std::string& term : terms) {
//        // Split the term into coefficient and exponent parts
//        std::vector<std::string> parts = split(trim(term), '^');
//        if (parts.size() == 1) {
//            // If there is no exponent part, assume it's a constant term
//            CoeffType constant = parseCoefficient(parts[0]);
//            if (coefficients.empty()) {
//                leadingCoefficient = 1;
//            } else {
//                coefficients[0] = constant;
//            }
//        } else if (parts.size() == 2) {
//            // If there is an exponent part, parse the coefficient and exponent
//            CoeffType coeff = parseCoefficient(parts[0]);
//            ExponentType exp = parseExponent(parts[1]);
//
//            // Add the coefficient to the appropriate exponent in the coefficients map
//            coefficients[exp] += coeff;
//            if (coefficients[exp] == 0) {
//                // Remove the entry if the coefficient is zero
//                coefficients.erase(exp);
//            }
//        } else {
//            // Invalid term format
//            throw std::invalid_argument("Invalid polynomial term: " + term);
//        }
//    }
//
//    // If there are no terms, assume the polynomial is the zero polynomial
//    if (coefficients.empty()) {
//        leadingCoefficient = 0;
//    } else {
//        leadingCoefficient = coefficients.rbegin()->second;
//    }
//}


/////////////// OPERATORS ///////////

template<typename CoeffType, typename ExponentType>
Polynomial<CoeffType, ExponentType> Polynomial<CoeffType, ExponentType>::operator+(const Polynomial &other) const {

    return 0;
}

template<typename CoeffType, typename ExponentType>
Polynomial<CoeffType, ExponentType> Polynomial<CoeffType, ExponentType>::operator-(const Polynomial &other) const {
    return Polynomial();
}

template<typename CoeffType, typename ExponentType>
Polynomial<CoeffType, ExponentType> Polynomial<CoeffType, ExponentType>::operator*(const Polynomial &other) const {
    return Polynomial();
}

template<typename CoeffType, typename ExponentType>
Polynomial<CoeffType, ExponentType> Polynomial<CoeffType, ExponentType>::operator/(const Polynomial &other) const {
    return Polynomial();
}


/////////// Function Declaration ///////////

//////////////// Member Functions ///////



template<typename CoeffType, typename ExponentType>
CoeffType Polynomial<CoeffType, ExponentType>::evaluate(CoeffType x) const {
    return nullptr;
}

template<typename CoeffType, typename ExponentType>
Polynomial<CoeffType, ExponentType> Polynomial<CoeffType, ExponentType>::differentiate() const {
    return Polynomial<CoeffType, ExponentType>();
}

template<typename CoeffType, typename ExponentType>
std::string Polynomial<CoeffType, ExponentType>::toString() const {
    std::stringstream ss;

    for (const auto& term : terms) {
        CoeffType coeff = term.first;
        ExponentType exp = term.second;

        if (coeff > 0 && !ss.str().empty()) {
            ss << "+";
        } else if (coeff < 0) {
            ss << "-";
            coeff = -coeff;
        }

        if (coeff != 1 || exp == 0) {
            ss << coeff;
        }

        if (exp > 0) {
            ss << "x";
        }

        if (exp > 1) {
            ss << "^" << exp;
        }
    }

    if (ss.str().empty()) {
        ss << "0";
    }

    return ss.str();
}

template<typename CoeffType, typename ExponentType>
std::string Polynomial<CoeffType,ExponentType>::trim(const std::string& str)
{
    size_t start = str.find_first_not_of(' ');
    size_t end = str.find_last_not_of(' ');
    if (start == std::string::npos || end == std::string::npos) {
        return "";
    }
    return str.substr(start, end - start + 1);
}

template<typename CoeffType, typename ExponentType>
std::vector<std::string> Polynomial<CoeffType,ExponentType>::split(const std::string& str, char delimiter) {
    std::vector<std::string> parts;
    std::string part;
    std::istringstream stream(str);
    while (std::getline(stream, part, delimiter)) {
        if (!part.empty()) {
            parts.push_back(part);
        }
    }
    return parts;
}

template<typename CoeffType, typename ExponentType>
CoeffType Polynomial<CoeffType, ExponentType>::parseCoefficient(const std::string& str) {
    if (str.empty()) {
        // Empty string is not a valid coefficient
        throw std::invalid_argument("Invalid polynomial coefficient: " + str);
    }

    // Check if the coefficient is negative
    bool isNegative = false;
    size_t pos = 0;
    if (str[0] == '-') {
        isNegative = true;
        pos = 1;
    }

    // Parse the coefficient digits
    CoeffType coeff = 0;
    for (pos = 0; pos < str.size(); pos++)
    {
        // is the current value NOT a digit?
        if (!std::isdigit(str[pos]))
        {
            // Invalid coefficient format
            //throw std::invalid_argument("Invalid polynomial coefficient: " + str);

            //So here we want to do nothing, right?

            if (str[0] == 'x')
            {
                coeff = 1;
            }
            else if (str[0] == '-')
            {
                if (str[1] == 'x')
                {
                    coeff = 1;
                }
                else
                {
                    CoeffType tempCoeff = str[1];
                    tempCoeff -= 48;
                    coeff = tempCoeff;
                }

            }
            else
            {
                CoeffType tempCoeff = str[0];
                coeff = str[0]-48; // Taking off 48 for ASCII 0.
            }

        }
        else {
            coeff = coeff * 10 + (str[pos] - '0');
        }

    }

    // If the coefficient is negative, negate it
    if (isNegative) {
        coeff = -coeff;
    }

    return coeff;
}

template<typename CoeffType, typename ExponentType>
ExponentType Polynomial<CoeffType, ExponentType>::parseExponent(const std::string &str) {
    ExponentType exponent = 0;
    std::size_t pos = 0;

    if (str.empty()) {
        return exponent;
    }

    // check for sign
    bool negative = false;
    if (str[pos] == '-') {
        negative = true;
        ++pos;
    } else if (str[pos] == '+') {
        ++pos;
    }

    while (pos < str.length()) {
        char c = str[pos];
        if (c < '0' || c > '9') {
            break;
        }
        exponent = exponent * 10 + (c - '0');
        ++pos;
    }

    if (negative) {
        exponent = -exponent;
    }

    return exponent;
}

template <typename CoeffType, typename ExponentType>
void Polynomial<CoeffType, ExponentType>::setFromString(const std::string& str) {
    // Clear the existing polynomial
    leadingCoefficient = 0;
    coefficients.clear();

    // Parse the input string into individual terms
    std::vector<std::string> myTerms = split(trim(str), '+');

    // Iterate over the terms and parse each one
    for (const std::string& term : myTerms) {
        // Split the term into coefficient and exponent parts
        std::vector<std::string> parts = split(trim(term), '^');
        if (parts.size() == 1) {
            // If there is no exponent part, assume it's a constant term
            CoeffType constant = parseCoefficient(parts[0]);
            if (coefficients.empty()) {
                leadingCoefficient = constant;
            } else {
                coefficients[0] = constant;
            }
            if (term.contains("x"))
            {

                ExponentType myExp = parseExponent("1");
                terms.emplace_back(constant, myExp);
            }
            else
            {
                ExponentType myExp = parseExponent("0");
                terms.emplace_back(constant, myExp);
            }



        } else if (parts.size() == 2) {
            // If there is an exponent part, parse the coefficient and exponent
            CoeffType myCoeff = parseCoefficient(parts[0]);
            ExponentType myExp = parseExponent(parts[1]);

            terms.emplace_back(myCoeff, myExp);
            // Add the coefficient to the appropriate exponent in the coefficients map
            coefficients[myExp] += myCoeff;
            if (coefficients[myExp] == 0) {
                // Remove the entry if the coefficient is zero
                coefficients.erase(myExp);
            }
        } else {
            // Invalid term format
            throw std::invalid_argument("Invalid polynomial term: " + term);
        }
    }

    // If there are no terms, assume the polynomial is the zero polynomial
    if (coefficients.empty()) {
        leadingCoefficient = 0;
    } else {
        leadingCoefficient = coefficients.rbegin()->second;
    }
}


