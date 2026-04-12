#ifndef TOKENS_HPP
#define TOKENS_HPP
#include <iostream>
#pragma once

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

bool isDelimiter(char c){
    return c == '(' || c == ')' || c == ',' || c == ';'
}

struct Token{
    std::string value;
    TokenType type; 

    int line; 
    int column; 
};



#endif