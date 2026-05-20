#pragma once
#include <memory>
#include "lexer/tokens.hpp"

//These are AST nodes:

struct Expr {
    virtual ~Expr() = default;
};

struct BinaryExpr : public Expr {
    Expr* left_;
    Expr* right_;
    Token op_;

    BinaryExpr(Expr* left, Expr* right, Token op)
        : left_(left), right_(right), op_(op) {}
    BinaryExpr() : left_(nullptr), right_(nullptr), op_(nullToken) {}
};

// TODO: finish these...
// TODO: rename to UnaryExpr, and PrimaryExpr, and LiteralExpr etc.
struct UnaryExpr : public Expr {
    Token op_;
    Expr* right_;
};
struct PrimaryExpr : public Expr {
    // TODO: this def not correct fix this:
    Token op_;
    Expr* right_;
};

struct Literal : public Expr {
    Token value_;
    Literal(Token value) : value_(value) {}
    Literal() : value_(nullToken) {}
};
struct Grouping : public Expr {
};  // grouping may not need to inherit from Expr I'm not sure...
