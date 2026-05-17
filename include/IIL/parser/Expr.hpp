#pragma once
#include "lexer/tokens.hpp"
#include <memory>
struct Expr {

    virtual ~Expr() = default;
};

struct BinaryExpr : public Expr {
    Expr *left_;
    Expr *right_;

    Token op_;
    BinaryExpr(Expr *left, Expr *right, Token op) : left_(left), right_(right), op_(op) {}
    BinaryExpr() : left_(nullptr), right_(nullptr), op_(TokenType::NONE, " ", 0, 0) {}
};