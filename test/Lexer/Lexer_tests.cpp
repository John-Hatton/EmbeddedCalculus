//
// Created by John on 4/4/2023.
//

#include <gtest/gtest.h>
#include "../source/Lexer/Lexer.cpp"
#include "../source/Lexer/Token.cpp"

TEST(LexerTests, LexerTests_LexerTests__Test01) {
    Lexer lexer("5.5 - -3.5");
    std::vector<Token> expected_tokens = {
            Token(TokenType::CONSTANT, "5.5"),
            Token(TokenType::MINUS, "-"),
            Token(TokenType::MINUS, "-"),
            Token(TokenType::CONSTANT, "3.5"),
            Token(TokenType::END_OF_FILE, "")
    };
    EXPECT_EQ(expected_tokens, lexer.getTokens());
}


TEST(LexerTests, LexerTests_LexerTests__Test02) {
    Lexer lexer("2 + 3 * 4 - 2 / 1");
    std::vector<Token> expected_tokens = {
            Token(TokenType::CONSTANT, "2"),
            Token(TokenType::PLUS, "+"),
            Token(TokenType::CONSTANT, "3"),
            Token(TokenType::MULTIPLY, "*"),
            Token(TokenType::CONSTANT, "4"),
            Token(TokenType::MINUS, "-"),
            Token(TokenType::CONSTANT, "2"),
            Token(TokenType::DIVIDE, "/"),
            Token(TokenType::CONSTANT, "1"),
            Token(TokenType::END_OF_FILE, "")
    };



    EXPECT_EQ(expected_tokens, lexer.getTokens());
}

TEST(LexerTests, LexerTests_LexerTests__Test03) {
    Lexer lexer("7.5 / 0.5");
    std::vector<Token> expected_tokens = {
            Token(TokenType::CONSTANT, "7.5"),
            Token(TokenType::DIVIDE, "/"),
            Token(TokenType::CONSTANT, "0.5"),
            Token(TokenType::END_OF_FILE, "")
    };

    std::vector<Token> actual_tokens = lexer.getTokens();
    Token firstToken = lexer.getTokens()[0];
    EXPECT_EQ(expected_tokens, actual_tokens);
    EXPECT_EQ(firstToken.getType(), TokenType::CONSTANT);
}



TEST(LexerTests, LexerTests_TestAddition) {
    Lexer lexer("2 + 3");
    std::vector<Token> expected_tokens = {
            Token(TokenType::CONSTANT, "2"),
            Token(TokenType::PLUS, "+"),
            Token(TokenType::CONSTANT, "3"),
            Token(TokenType::END_OF_FILE, "")
    };
    EXPECT_EQ(expected_tokens, lexer.getTokens());
}

TEST(LexerTests, LexerTests_TestSubtraction) {
    Lexer lexer("5 - 7");
    std::vector<Token> expected_tokens = {
            Token(TokenType::CONSTANT, "5"),
            Token(TokenType::MINUS, "-"),
            Token(TokenType::CONSTANT, "7"),
            Token(TokenType::END_OF_FILE, "")
    };
    EXPECT_EQ(expected_tokens, lexer.getTokens());
}

TEST(LexerTests, LexerTests_TestMultiplication) {
    Lexer lexer("2 * 4");
    std::vector<Token> expected_tokens = {
            Token(TokenType::CONSTANT, "2"),
            Token(TokenType::MULTIPLY, "*"),
            Token(TokenType::CONSTANT, "4"),
            Token(TokenType::END_OF_FILE, "")
    };
    EXPECT_EQ(expected_tokens, lexer.getTokens());
}

TEST(LexerTests, LexerTests_TestDivision) {
    Lexer lexer("6 / 3");
    std::vector<Token> expected_tokens = {
            Token(TokenType::CONSTANT, "6"),
            Token(TokenType::DIVIDE, "/"),
            Token(TokenType::CONSTANT, "3"),
            Token(TokenType::END_OF_FILE, "")
    };
    EXPECT_EQ(expected_tokens, lexer.getTokens());
}

TEST(LexerTests, LexerTests_TestMultipleOperators) {
    Lexer lexer("2 + 3 * 4 - 5 / 6");
    std::vector<Token> expected_tokens = {
            Token(TokenType::CONSTANT, "2"),
            Token(TokenType::PLUS, "+"),
            Token(TokenType::CONSTANT, "3"),
            Token(TokenType::MULTIPLY, "*"),
            Token(TokenType::CONSTANT, "4"),
            Token(TokenType::MINUS, "-"),
            Token(TokenType::CONSTANT, "5"),
            Token(TokenType::DIVIDE, "/"),
            Token(TokenType::CONSTANT, "6"),
            Token(TokenType::END_OF_FILE, "")
    };
    EXPECT_EQ(expected_tokens, lexer.getTokens());
}