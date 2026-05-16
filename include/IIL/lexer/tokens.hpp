#pragma once
#include <iostream>
#include <unordered_set>

enum TokenType {
    Number,
    Identifier,
    Keyword,
    OpenParen,
    CloseParen,
    Operator,
    Delimiter,
    Indent,
    FileEnd,
    BangEqual,
    EqualEqual,
    NONE,
};

struct Token {
    TokenType type;
    std::string value;
    unsigned int line;
    unsigned int column;

    Token(TokenType type, std::string value, unsigned int line, unsigned int column)
        : type(type), value(std::move(value)), line(line), column(column) {}
};

inline const std::unordered_set<std::string> operators = {"+", "-", "*", "/", "%", "<", ">", "="};

inline const std::unordered_set<std::string> delimiters = {";", ",",
                                                           "\""
                                                           ":"};

inline const std::unordered_set<std::string> keywords = {
    "ivar", "global", "NULL", "if",      "else",     "eif",   "do",      "iwhile", "iend", "iexit",
    "ifor", "ibreak", "itry", "iexcept", "ifinally", "ifunc", "ireturn", "True",   "False"};
