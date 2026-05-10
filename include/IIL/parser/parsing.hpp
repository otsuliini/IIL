#include <vector>
#include "ASTNode.hpp"
#include "tokens.hpp"
#include "helperRoutines.hpp"

class numericalExprAST
{
public:
    std::vector<std::shared_ptr<ASTnode>> connect_nodes(std::vector<OpTok> opTokens); 
    std::vector<ASTnode> NumExprAST(std::vector<Token> &Tokens);
};

struct OpTok : Token
{
    Precedence precedence;
    std::unique_ptr<Token> leftChild;
    std::unique_ptr<Token> rightChild;

    OpTok(std::unique_ptr<Token>  left_child, std::unique_ptr<Token> right_child, Token val)
    {
        std::unique_ptr<OpTok> ptrTok;
        leftChild = std::move(left_child);
        rightChild = std::move(right_child);
        value = val.value;
        Precedence precednece = Precedence::Undefined;
    }

    OpTok(std::unique_ptr<Token>  left_child, std::unique_ptr<Token> right_child)
    {
        std::unique_ptr<OpTok> ptrTok;
        leftChild = std::move(left_child);
        rightChild = std::move(right_child);
        Precedence precednece = Precedence::Undefined;
    }
    OpTok(std::unique_ptr<Token>  left_child)
    {
        std::unique_ptr<OpTok> ptrTok;
        leftChild = std::move(left_child);
        Precedence precednece = Precedence::Undefined;
    }
    OpTok(std::unique_ptr<Token> right_child)
    {
        std::unique_ptr<OpTok> ptrTok;
        rightChild = std::move(right_child);
        Precedence precednece = Precedence::Undefined;
    }
    OpTok(Token val)
    {
        value = val.value;
        leftChild->column = NULL;
        leftChild->line = NULL;
        leftChild->type = TokenType::NONE;
        leftChild->value = " ";
        rightChild->column = NULL;
        rightChild->line = NULL;
        rightChild->type = TokenType::NONE;
        rightChild->value = " ";
    }
    OpTok()
    {
        leftChild->column = NULL;
        leftChild->line = NULL;
        leftChild->type = TokenType::NONE;
        leftChild->value = " ";
        rightChild->column = NULL;
        rightChild->line = NULL;
        rightChild->type = TokenType::NONE;
        rightChild->value = " ";
    }
};