#pragma once
#include "lexer/tokens.hpp"
#include <memory>
struct Expr {

  virtual ~Expr() = default;
};

struct BinaryExpr : public Expr {
  std::unique_ptr<Expr> left;
  std::unique_ptr<Expr> right;

  Token op;
  BinaryExpr() : left(nullptr), right(nullptr) {}
};