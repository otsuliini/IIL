#pragma once
#include <vector>
#include "parser/Expr.hpp"
#include "lexer/tokens.hpp"

class Parser 
{
    class expressionParsing 
    {   
        std::unique_ptr<Expr> equality() 
        {
            std::unique_ptr<Expr> expr = comparison(); 
            while()
        }
        std::unique_ptr<Expr> expression() // Unique_ptr is used because an ast node belongs to exactly one parent. 
        {   
            return equality();
        }
    }; 
}; 