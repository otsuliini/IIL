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

    ~BinaryExpr() {
        delete left_;
        delete right_;
    }
};
// TODO: finish these...
// TODO: rename to UnaryExpr, and PrimaryExpr, and LiteralExpr etc.
struct Unary : public Expr {
    Token op;
    Unary *right_;
};
struct Primary : public Expr {
    // TODO: this def not correct fix this:
    Token op;
    Unary *right_;
};
struct Literal : public Expr {};
struct Grouping : public Expr {}; // grouping may not need to inherit from Expr I'm not sure...