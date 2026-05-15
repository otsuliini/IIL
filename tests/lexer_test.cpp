#include <gtest/gtest.h>
#include "lexer/tokenization.hpp"
#include "lexer/tokens.hpp"
TEST(lexerTests, HandlesOperators)
{
    std::string op = "+";
    int expected_line = 1;
    int expected_column = 1;
    std::vector<Token> expectedOutput = {Token{TokenType::Operator, op, expected_line, expected_column}};

    tokenizing lexer;
    EXPECT_EQ(lexer.tokenize(op), expectedOutput);
}
