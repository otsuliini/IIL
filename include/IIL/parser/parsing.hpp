#pragma once
#include "lexer/tokens.hpp"
#include "parser/expr.hpp"
#include "parser/parsing.hpp"
#include <cstddef>
#include <memory>
#include <new>
#include <vector>

struct ParseError {
    Token token_;
    std::string message_;

    ParseError() : token_(TokenType::NONE, " ", 0, 0), message_(" ") {}
    ParseError(Token token, std::string message) : token_(token), message_(message) {}
};

class Parser {
  protected:
    Arena arena;
    virtual ~Parser() = default;
}; // Class: Parser

class expressionParsing : public Parser {
    unsigned int current = 0;

    // Check if the current token has any of the given types. If it does we consume the token
    // and reutrn true. Else it returns false and leaves the token alone. The match() method is
    // defined in terms of two ore more fundemental operations
    template <typename... Types> bool match(Types... types) const {
        return ((check(types) && (advance(), true)) || ...);
        //     ^ If this is true we evaluate this^
    }

    template <typename T> T make_unary_ptr(Primary *type) {
        T *expr;
        expr->op = type->op;
        expr->right_ = type->right_;
        return expr;
    }
    template <typename T> T *make_binary_ptr(Unary *type) {
        T *expr;
        expr->op = type->op;
        expr->right_ = type->right_;
        return expr;
    }

    ParseError error(Token token, std::string message);
    Token consume(TokenType type, std::string message);
    Token previous() const;
    Token peek() const;
    auto isAtEnd() const;
    Primary *primary();
    Unary *unary();

    BinaryExpr *factor();
    BinaryExpr *term();
    BinaryExpr *comparison();
    std::vector<Token> tokens;
    Token advance();
    bool check(TokenType type);

    BinaryExpr *equality();
    BinaryExpr *expression(); // Unique_ptr is used because an astNode belongs
                              // to exactly one parent.

    // move tokens so we don't have to make copy:
    expressionParsing(std::vector<Token> Tokens) : tokens(std::move(Tokens)) {}
}; // Class: expressionParsing