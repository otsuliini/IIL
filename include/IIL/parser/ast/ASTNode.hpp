#pragma once
#include <iostream>
#include "tokens.hpp"
#include <vector>
#include <memory>

struct ASTNode
{
    std::unique_ptr<Token> NodeValue, parent;
    std::unique_ptr<ASTNode> leftChild, rightChild, extension_of_parent; 
    ASTNode()
    {
        parent->column = NULL;
        parent->line = NULL;
        parent->value = " ";
        parent->type = TokenType::NONE;
    }

    ASTNode(Token Value) : NodeValue(std::make_unique<Token>(Value)),
                           leftChild(nullptr),
                           rightChild(nullptr),
                           extension_of_parent(nullptr) {}
    ASTNode(std::unique_ptr<Token> token_right, std::unique_ptr<Token> token_left) : NodeValue()                     
    {
        leftChild->NodeValue = std::move(token_left); 
        rightChild->NodeValue = std::move(token_right); 
    }                                                                    
};

enum class Precedence
{
    // Precedence in order of least to greatest
    LEVEL0,
    LEVEL1,
    LEVEL2,
    LEVEL3,
    LEVEL4,
    Undefined = -1, 
};