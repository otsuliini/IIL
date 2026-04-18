#pragma once
#include <iostream>
#include <unordered_set> 

enum TokenType
{
    Number,
    Identifier, 
    Keyword,
    OpenParen,
    CloseParen,
    Operator,
    Delimiter,
    Indent,
    FileEnd,
};


struct Token{
    std::string value;
    TokenType type; 

    int line; 
    int column; 

    Token(TokenType type, std::string value, int line, int column)
        : type(type), value(value), line(line), column(column) {}
};

inline const std::unordered_set<std::string> operators = {
    "+", "-", "*", "/", "%", "<", ">", "="
};

inline const std::unordered_set<std::string> delimiters = {
    ";", ",", "\"" ":"
};

inline const std::unordered_set<std::string> keywords = {
    "ivar",
    "global",
    "NULL",
    "if",
    "else",
    "eif",
    "do",
    "iwhile",
    "iend",
    "iexit",
    "ifor",
    "ibreak",
    "itry",
    "iexcept",
    "ifinally",
    "ifunc",
    "ireturn",
    "True",
    "False"
};




