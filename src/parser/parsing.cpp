#include "parser/parsing.hpp"
#include "parser/utils/helperRoutines.hpp"
#include <memory>
#include <vector>
// Example: 1 + 1. Tokens are '1' '+' and '1'

bool check(TokenType type) {
  if (isAtEnd()) {
    return false;
  }
  return peek().type == type;
}

std::unique_ptr<Expr> Parser::expressionParsing::equality() {
  std::unique_ptr<Expr> expr = comparison();
  while (match(TokenType::BangEqual, EqualEqual)) {
    Token operator= previous();
    auto right = comparison();
    expr = std::make_unique <
  }
}

std::unique_ptr<Expr> Parser::expressionParsing::expression() {
  // Expression expands to the equality rule.
  // Expresson := equality;
  return equality();
}
