#ifndef TOKENS_HPP
#define TOKENS_HPP
#include <iostream>

enum TokenType
{
    Number,
    String,
    Identifier, 
    ivar,
    Keyword,
    OpenParen,
    CloseParen,
    Operator,
    Delimiter,
    Indent
};

struct Token{
    std::string value;
    TokenType type; 
};

#endif