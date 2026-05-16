#pragma once
#include "lexer/tokens.hpp"
#include <memory> 
struct Expr 
{
    std::unique_ptr<Expr> leftChild; 
    std::unique_ptr<Expr> rightChild; 

    std::unique_ptr<Expr> parent; 
    Token value; 

    Expr() : leftChild(nullptr), rightChild(nullptr), parent(nullptr) 
    {
        value.value = " "; 
        value.column;
        value.line; 
        value.type = TokenType::UNKNOWN; 
    }

    
}; 
