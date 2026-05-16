#pragma once
#include <vector>
#include "parser/Expr.hpp"
#include "parser/parsing.hpp"
#include "lexer/tokens.hpp"

class Parser 
{
    class expressionParsing 
    {   
        bool check(TokenType type); 
        template <typename... Types> 
        bool match(Types... types) {
            return ((check(types) && (advance(), true)))
        }

        std::unique_ptr<Expr> equality(); 
        std::unique_ptr<Expr> expression(); // Unique_ptr is used because an ast node belongs to exactly one parent. 
    }; 
}; 