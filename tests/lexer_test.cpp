#include <gtest/gtest.h>
#include "../include/IIL/lexer/tokenization.hpp"

TEST(lexerTests, HandlesOperators)
{
    char op = '+';                    
    EXPECT_EQ(tokenize(op), Operator);  
}