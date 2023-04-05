//
// Created by John on 4/4/2023.
//

#ifndef EMBEDEDCALCULUS_PARSER_H
#define EMBEDEDCALCULUS_PARSER_H

#include "Lexer/Lexer.h"
#include "ASTNode/ASTNode.h"
#include <NodeFactory/NodeFactory.h>
#include "Lexer/Token.h"
#include <memory>

/**
 * Class Description Parser: a class that serves as the parser for our Embedded Calculus programming language. This class
 * takes a stream of tokens from the lexer and constructs an abstract syntax tree (AST) according to the grammar of our programming language.
 */
class Parser {
public:
    /**
     * Parser Constructor: Creates a Parser object with a given Lexer object and NodeFactory object.
     * @param lexer A pointer to the Lexer object used to tokenize the input string.
     * @param factory A pointer to the NodeFactory object used to create ASTNode objects.
     */
    Parser(std::unique_ptr<Lexer> lexer, std::unique_ptr<NodeFactory> factory);

    /**
     * Parse Function: Parses the input tokens and returns the root node of the abstract syntax tree.
     * @return Returns a unique_ptr to the root node of the abstract syntax tree.
     */
    std::unique_ptr<ASTNode> parse();

private:
    std::unique_ptr<Lexer> lexer; // A pointer to the Lexer object used to tokenize the input string
    std::unique_ptr<NodeFactory> factory; // A pointer to the NodeFactory object used to create ASTNode objects
    std::vector<Token> tokens; // The vector of tokens returned by the Lexer
    int current; // The current position in the vector of tokens

    /**
     * Match Function: Matches the current token with a given token type and advances to the next token.
     * If the current token does not match the given token type, an error is thrown.
     * @param type The token type to match with the current token.
     */
    void match(const std::string& type);

    /**
     * Factor Function: Parses a factor in the input tokens and returns a unique_ptr to the corresponding AST node.
     * A factor can be a number, a variable, a function call, or a sub-expression in parentheses.
     * @return Returns a unique_ptr to the corresponding AST node.
     */
    std::unique_ptr<ASTNode> factor();

    /**
     * Term Function: Parses a term in the input tokens and returns a unique_ptr to the corresponding AST node.
     * A term can be a factor, or a product or division of factors.
     * @return Returns a unique_ptr to the corresponding AST node.
     */
    std::unique_ptr<ASTNode> term();

    /**
     * Expression Function: Parses an expression in the input tokens and returns a unique_ptr to the corresponding AST node.
     * An expression can be a term, or a sum or subtraction of terms.
     * @return Returns a unique_ptr to the corresponding AST node.
     */
    std::unique_ptr<ASTNode> expression();
};

#endif //EMBEDEDCALCULUS_PARSER_H

