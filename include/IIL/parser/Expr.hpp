#pragma once
#include "lexer/tokens.hpp"
#include <memory>
struct Expr {

    virtual ~Expr() = default;
};

struct BinaryExpr : public Expr {
    std::unique_ptr<Expr> left_;
    std::unique_ptr<Expr> right_;

    Token op;
    BinaryExpr() : left_(nullptr), right_(nullptr), op(TokenType::NONE, " ", 0, 0) {}
};