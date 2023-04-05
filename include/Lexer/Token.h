//
// Created by John on 4/4/2023.
//

#ifndef EMBEDEDCALCULUS_TOKEN_H
#define EMBEDEDCALCULUS_TOKEN_H

#include <string>


/**
 * TokenType: An enumeration of all possible token types in our Embedded Calculus programming language.
 */
enum class TokenType {
    // Single-character tokens
    LEFT_PAREN, RIGHT_PAREN, PLUS, MINUS, MULTIPLY, DIVIDE,

    // Literals
    CONSTANT,

    // Keywords
    VARIABLE, EQUAL, IDENTIFIER,

    // TRIG
    SIN, COS, TAN,

    // End-of-file token
    END_OF_FILE
};

/**
 * Token: A class that represents a single token in our Embedded Calculus programming language. Each token has a type and a
 * lexeme (the actual characters that make up the token in the input string).
 */
class Token {
public:
    /**
     * Token Constructor: Creates a new Token object with a given type and lexeme.
     * @param type The type of the token.
     * @param lexeme The lexeme of the token.
     */
    Token(TokenType type, std::string lexeme);


    Token(std::string lexeme);

    /**
     * GetType Function: Returns the type of the token.
     * @return Returns the TokenType of the token.
     */
    TokenType getType() const;

    /**
     * GetLexeme Function: Returns the lexeme of the token.
     * @return Returns the lexeme (as a string) of the token.
     */
    std::string getLexeme() const;

    /**
     * ToString Function: Returns a string representation of the token.
     * @return Returns a string representation of the token in the form "Token(type=TYPE, lexeme=LEXEME)".
     */
    std::string toString() const;



    bool operator==(const Token& other) const;

private:
    TokenType type; // The type of the token
    std::string lexeme; // The lexeme (actual characters) of the token
};

#endif //EMBEDEDCALCULUS_TOKEN_H