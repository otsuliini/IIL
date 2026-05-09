#include <vector>
#include "ASTNode.hpp"
#include "tokens.hpp"
#include "helperRoutines.hpp"

class numericalExprAST
{
    std::shared_ptr<ASTnode> numericalExprAST::parseRHS(const Token number, const Token Oper);

public:
    std::vector<ASTnode> NumExprAST(std::vector<Token> &Tokens);
};

struct OpTok : Token
{
    Precedence precedence;
    Token leftChild;
    Token rightChild;

    OpTok(Token left_child, Token right_child, Token val)
    {
        std::unique_ptr<OpTok> ptrTok;
        leftChild = left_child;
        rightChild = right_child;
        value = val.value;
        Precedence precednece = Precedence::Undefined;
    }

    OpTok(Token left_child, Token right_child)
    {
        std::unique_ptr<OpTok> ptrTok;
        leftChild = left_child;
        rightChild = right_child;
        Precedence precednece = Precedence::Undefined;
    }
    OpTok(Token val)
    {
        value = val.value;
        leftChild.column = NULL;
        leftChild.line = NULL;
        leftChild.type = TokenType::NONE;
        leftChild.value = " ";
        rightChild.column = NULL;
        rightChild.line = NULL;
        rightChild.type = TokenType::NONE;
        rightChild.value = " ";
    }
    OpTok()
    {
        leftChild.column = NULL;
        leftChild.line = NULL;
        leftChild.type = TokenType::NONE;
        leftChild.value = " ";
        rightChild.column = NULL;
        rightChild.line = NULL;
        rightChild.type = TokenType::NONE;
        rightChild.value = " ";
    }
};