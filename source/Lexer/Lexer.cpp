#include <Lexer/Lexer.h>
#include <Lexer/Token.h>
#include <cctype>
#include <stdexcept>

Lexer::Lexer(std::string input) : input(std::move(input)), current(0), start(0) {}

std::vector<Token> Lexer::getTokens() {
    while (!isAtEnd()) {
        start = current;
        tokenize();
    }

    tokens.emplace_back(Token(TokenType::END_OF_FILE, ""));
    return tokens;
}

void Lexer::tokenize() {
    const char c = advance();
    switch (c) {
        case '(':
            addToken(TokenType::LEFT_PAREN, "");
            break;
        case ')':
            addToken(TokenType::RIGHT_PAREN, "");
            break;
        case '+':
            addToken(TokenType::PLUS, "");
            break;
        case '-':
            addToken(TokenType::MINUS, "");
            break;
        case '*':
            addToken(TokenType::MULTIPLY, "");
            break;
        case '/':
            addToken(TokenType::DIVIDE, "");
            break;
        case ' ':
        case '\t':
        case '\r':
            break; // Ignore whitespace
        case '\n':
            line++;
            break;
        default:
            if (isdigit(c)) {
                number();
            } else if (isalpha(c)) {
                identifier();
            } else {
                throw std::runtime_error("Unexpected character");
            }
    }
}

void Lexer::number() {
    while (isdigit(peek())) advance();

    if (peek() == '.' && isdigit(peekNext())) {
        advance(); // Consume the '.'
        while (isdigit(peek())) advance();
    }

    addToken(TokenType::CONSTANT, input.substr(start, current - start));
}

void Lexer::identifier() {
    while (isalnum(peek())) advance();

    const std::string text = input.substr(start, current - start);
    if (text == "sin") {
        addToken(TokenType::SIN, text);
    } else if (text == "cos") {
        addToken(TokenType::COS, text);
    } else {
        addToken(TokenType::IDENTIFIER, text);
    }
}

bool Lexer::isAtEnd() const {
    return current >= input.size();
}

char Lexer::advance() {
    return input[current++];
}

char Lexer::peek() const {
    return isAtEnd() ? '\0' : input[current];
}

char Lexer::peekNext() const {
    return current + 1 >= input.size() ? '\0' : input[current + 1];
}

void Lexer::error(const std::string& message) const {
    throw std::runtime_error(message);
}

void Lexer::addToken(TokenType type, const std::string &literal) {
    std::string lexeme = input.substr(start, current - start);
    tokens.emplace_back(Token(type, lexeme));
}