#pragma once
#include "lexer/tokens.hpp"
#include "parser/Expr.hpp"
#include "parser/parsing.hpp"
#include <vector>

class Parser {
  class expressionParsing {
    bool check(TokenType type);

        template <typename... Types> 
        bool match(Types... types) {
            return (check(types) && (advance(), true)
        }

        std::unique_ptr<Expr> equality();
        std::unique_ptr<Expr>
        expression(); // Unique_ptr is used because an astNode belongs to
                      // exactly one parent.
  };
};
