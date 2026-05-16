#include "parser/parsing.hpp"
#include "parser/utils/helperRoutines.hpp"
#include <vector>
#include <memory>
// Example: 1 + 1. Tokens are '1' '+' and '1'

bool check(TokenType type) {
    
}

std::unique_ptr<Expr> expression()
{
    return equality();
}

std::unique_ptr<Expr> Parser::expressionParsing::equality()
{
    std::unique_ptr<Expr> expr = comparison();
    while ()
}
