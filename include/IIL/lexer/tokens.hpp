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
    Greater,
    GreaterEqual,
    Less,
    LessEqual,
    Minus,
    Plus,
    Slash,
    Star,
    Bang,
    Minus,
    False,
    True,
    NIL,
    String,
};

struct Token {
    TokenType type_;
    std::string value_;
    unsigned int line_;
    unsigned int column_;

    Token(TokenType type, std::string value, unsigned int line, unsigned int column)
        : type_(type), value_(std::move(value)), line_(line), column_(column) {}
    virtual ~Token() = default;

    static Token make_token(TokenType type, std::string value, unsigned int line,
                            unsigned int column) {
        Token token(type, value, line, column);
        return token;
    }
};

Token nullToken{Token::make_token(TokenType::NONE, " ", 0, 0)};

inline const std::unordered_set<std::string> operators = {"+", "-", "*", "/", "%", "<", ">", "="};

inline const std::unordered_set<std::string> delimiters = {";", ",",
                                                           "\""
                                                           ":"};

inline const std::unordered_set<std::string> keywords = {
    "ivar", "global", "NULL", "if",      "else",     "eif",   "do",      "iwhile", "iend", "iexit",
    "ifor", "ibreak", "itry", "iexcept", "ifinally", "ifunc", "ireturn", "True",   "False"};
