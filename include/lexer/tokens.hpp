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
    Indent
};


struct Token{
    std::string value;
    TokenType type; 

    int line; 
    int column; 
};

inline const std::unordered_set<std::string> operators = {
    ""
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
    "exit",
    "ifor",
    "ibreak",
    "itry",
    "iexcept",
    "ifinally",
    "ifunc",
    "return",
    "true",
    "false"
};




