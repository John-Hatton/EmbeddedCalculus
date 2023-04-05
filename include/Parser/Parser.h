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





    /*
     *
     * See https://www.youtube.com/watch?v=SToUyjAsaFk&t=754s
     *
     * Recursive Descent Parsing, by hhp3
     *
     * One key thing to note here is that we will not be doing either
     * a parser generator or a parser combinator. We will instead be
     * doing a hand-written recursive descent parser. This means that
     * the errors will be easy to catch, and we will ensure the code
     * does not become overwhelmed with unnecessary complexity.
     *
     *
     * So the problem is that we cannot have infinte recursion in our
     * grammar.
     *
     * E := E + T | E - T will end up in a recursive loop, and is
     * called left recursive, because the parser could go expression
     * equals expression forever.
     *
     * So can switch the grammar to say:
     *
     * E := T + E
     *
     * However this makes our parser logic different. This is
     * considered right recursive, and is a bit more difficult to
     * implement.
     *
     *
     * See the following code. I've changed the terminology, so it more
     * closely matches what I have in my library, specifically in this
     * parser class.
     *          ////////////////////////
     *          //// WRONG WAY!!! //////
     *          ////////////////////////
     * std::unique_ptr<ASTNode> expression() {
     *      a = expression();
     *      // If Next Token == "+"
     *      if (tokens[current+1].toString() == "+")
     *      {
     *          match();
     *          b = term();
     *
     *          return factory->createNode(new AddNode(a,b));
     *      }
     *      else if
     *      ...
     * }
     *
     *
     *
     * Please also note that we can rearrange our grammar like so:
     *
     * E := T { + | - T }
     *
     * Now we have a new Parse algorithm. This is going to be the "Right way" to do this
     *
     *
     * std::unique_ptr<ASTNode> expression()
     * {
     *          // The term function parses the next term, iirc
     *      a = term();
     *
     *      // If we have a+b, or 5 + 5, 5 is stored in a, we then check
     *      // the next value below to see if the next token is a plus sign
     *
     *      while (true)
     *      {   // Note that we increment current each time we find a plus
     *          // so that the next term will not be the plus sign.
     *          if (tokens[current+1].getType() == TokenType::PLUS)
     *          {
     *              current++;
     *              // The match function is the same as his scanToken function
     *              // It's purpose is to advance the value of current integer
     *              // member value. This position marker helps us keep track
     *              // of what value we're currently parsing. Sort of like the
     *              // instruction pointer, in assembly.
     *              match();
     *
     *              // Similarly we get the next valid term, and assign it to b.
     *              // In this case, we
     *              b = term();
     *              a = factory->createNode(new AddNode(a,b));
     *          }
     *          else if (tokens[current+1].getType() == TokenType::MINUS)
     *          {
     *              //... Similar
     *
     *              // Also!
     *              // Check for errors throughout!!!
     *
     *              // I like the idea of having an ErrorHandler function, that takes
     *              // Some components as input, and returns a convenient string,
     *              // that we can print to debug console.
     *              ///
     *          }
     *          else {
     *              // Be sure to return the right kind of object.
*                   return a;
     *          }
     *      } // End while
     * }
     */








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

