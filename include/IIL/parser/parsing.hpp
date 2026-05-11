#include <vector>
#include "ASTNode.hpp"
#include "tokens.hpp"
#include "helperRoutines.hpp"
#include <bits/stdc++.h>

struct left_child_t
{
};
struct right_child_t
{
};
struct OpTok : Token
{
    Precedence precedence;
    std::unique_ptr<Token> leftChild;
    std::unique_ptr<Token> rightChild;

    OpTok(std::unique_ptr<Token> left_child, std::unique_ptr<Token> right_child, Token val)
    {
        std::unique_ptr<OpTok> ptrTok;
        leftChild = std::move(left_child);
        rightChild = std::move(right_child);
        value = val.value;
        Precedence precedence = Precedence::Undefined;
    }
    OpTok(std::unique_ptr<Token> left_child, std::unique_ptr<Token> right_child)
    {
        std::unique_ptr<OpTok> ptrTok;
        leftChild = std::move(left_child);
        rightChild = std::move(right_child);
        Precedence precedence = Precedence::Undefined;
    }
    OpTok(std::unique_ptr<Token> left_child, left_child_t)
    {
        std::unique_ptr<OpTok> ptrTok;
        leftChild = std::move(left_child);
        Precedence precedence = Precedence::Undefined;
    }
    OpTok(std::unique_ptr<Token> right_child, right_child_t)
    {
        std::unique_ptr<OpTok> ptrTok;
        rightChild = std::move(right_child);
        Precedence precedence = Precedence::Undefined;
    }
    OpTok(Token val)
    {
        value = val.value;
        leftChild = std::make_unique<Token>();
        
        leftChild->column = NULL;
        leftChild->line = NULL;
        leftChild->type = TokenType::NONE;
        leftChild->value = " ";

        rightChild = std::make_unique<Token>();
        rightChild->column = NULL;
        rightChild->line = NULL;
        rightChild->type = TokenType::NONE;
        rightChild->value = " ";

        Precedence precedence = Precedence::Undefined;
    }

    OpTok()
    {   
        
        leftChild = std::make_unique<Token>();
        leftChild->column = 0;
        leftChild->line = 0;
        leftChild->type = TokenType::NONE;
        leftChild->value = " ";

        rightChild = std::make_unique<Token>();
        rightChild->column = 0;
        rightChild->line = 0;
        rightChild->type = TokenType::NONE;
        rightChild->value = " ";

        Precedence precedence = Precedence::Undefined;
    }
};

class numericalExprAST
{
public:
    std::vector<std::shared_ptr<ASTnode>> connect_nodes(std::vector<OpTok> opTokens);
    std::vector<ASTnode> NumExprAST(std::vector<Token> &Tokens);
};
