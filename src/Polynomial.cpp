//
// Created by John on 4/1/2023.
//

#include "Polynomial.h"
#include "PolyTerm.cpp"


template<typename Coefficient_t, typename Exponent_t>
Polynomial<Coefficient_t, Exponent_t>::Polynomial() {
    termsVector = {};
}

template<typename Coefficient_t, typename Exponent_t>
Polynomial<Coefficient_t, Exponent_t>::~Polynomial() {
    termsVector = {};
}

template<typename Coefficient_t, typename Exponent_t>
const std::vector<PolyTerm<Coefficient_t, Exponent_t> *> &
Polynomial<Coefficient_t, Exponent_t>::getTermsVector() const {
    return termsVector;
}


template<typename Coefficient_t, typename Exponent_t>
void Polynomial<Coefficient_t, Exponent_t>::setTermsVector(
        const std::vector<PolyTerm<Coefficient_t, Exponent_t> *> &termsVector) {
    Polynomial::termsVector = termsVector;
}

template<typename Coefficient_t, typename Exponent_t>
std::string Polynomial<Coefficient_t, Exponent_t>::trim(const std::string &str) {
    size_t start = str.find_first_not_of(' ');
    size_t end = str.find_last_not_of(' ');
    if (start == std::string::npos || end == std::string::npos) {
        return "";
    }
    return str.substr(start, end - start + 1);
}

template<typename Coefficient_t, typename Exponent_t>
std::vector<std::string> Polynomial<Coefficient_t, Exponent_t>::split(const std::string &str, char delimiter) {
    std::vector<std::string> parts;
    std::string part;
    std::istringstream stream(str);
    while (std::getline(stream, part, delimiter)) // getline fcn splits by delimiter
    {
        if (!part.empty()) {
            parts.push_back(part);
        }
    }
    return parts;
}

template<typename Coefficient_t, typename Exponent_t>
Coefficient_t Polynomial<Coefficient_t, Exponent_t>::parseCoefficient(const std::string &str) {
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
    Coefficient_t coeff = 0;
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
                    Coefficient_t tempCoeff = str[1];
                    tempCoeff -= 48;
                    coeff = tempCoeff;
                }

            }
            else
            {
                Coefficient_t tempCoeff = str[0];
                coeff = str[0]-48; // Taking off 48 for ASCII 0.
            }

        }
        else {
            //coeff = coeff * 10 + (str[pos] - '0');
        }

    }

    // If the coefficient is negative, negate it
    if (isNegative) {
        coeff = -coeff;
    }

    return coeff;
}

template<typename Coefficient_t, typename Exponent_t>
Exponent_t Polynomial<Coefficient_t, Exponent_t>::parseExponent(const std::string &str) {
    Exponent_t exponent = 0;


    if (str.empty()) {
        return exponent;
    }

    // check for sign=


    if (str.contains('^'))
    {
        std::vector<std::string> strParts = split(str, '^');

        // Go through exponent
        Exponent_t temp;
        std::stringstream ss;
        ss << strParts[1];
        ss >> temp;

        exponent = temp;
    }
    else if (str.contains('x') && !str.contains('^'))
    {
        // exponent is equal to 1
        exponent = 1;
    }
    else
    {
        // exponent is equal to 0!
        exponent = 0;
    }

    return exponent;
}

template<typename Coefficient_t, typename Exponent_t>
void Polynomial<Coefficient_t, Exponent_t>::setFromString(std::string &str) {

    // Second we check each value of the plusses (strings for now) to see if there are any minuses

    // Actually, we want to check for minuses first. If it's the very first character, we handle that case.

    // If it's any other character in the string, we simply append a + before it.

    bool hasMinus = false;

    if (str.contains('-'))
    {
        hasMinus = true;
    }

    if (hasMinus)  // TODO: SHOULD ONLY WORK FOR ONE MINUS SIGN!!!
    {
        std::vector<std::string> negativeSplit = split(str, '-');
        std::stringstream ss;
        ss << negativeSplit[0];
        for (int i = 1; i < negativeSplit.size(); i++) // Want values after split, not before
        {
            ss << "+-";
            ss << negativeSplit[i];
        }
        str = ss.str(); // Set str to our new value
    }


    std::cout << str << std::endl;

    // First we split by plusses... then we add to a map. At the very end, we will sort by exponent Largest->Smallest

    // After we've split and gotten out each unique term, we parse each term for coefficients and exponents
    // With these extracted values, we formulate our finished PolyTerms

    std::vector<std::string> myTerms = split(trim(str), '+');

    for (int x = 0; x < myTerms.size(); x++)
    {
        termsVector.push_back(new PolyTerm<Coefficient_t, Exponent_t>); // Should issue a new memory address each time

        // Shallow Copy!
        termsVector[x]->setCoefficient(parseCoefficient(myTerms[x]));
        termsVector[x]->setExponent(parseExponent(myTerms[x]));
        termsVector[x]->setStringRep(myTerms[x]);
        if(termsVector[x]->getCoefficient() < 0)
        {
            termsVector[x]->setNegativeTerm(true);
        }
        else
        {
            termsVector[x]->setNegativeTerm(false);
        }

    }



    std::cout << "Servus!" << std::endl;

}