#include "parsing.hpp"
#include "ASTNode.hpp"
#include "helperRoutines.hpp"
#include <vector>
// Example: 1 + 1. Tokens are '1' '+' and '1'

std::vector<std::shared_ptr<ASTnode>> numericalExprAST::connect_nodes(std::vector<OpTok> opTokens)
{
    Token highest_precedence_op = parserUtils::getHighestPrecedence(parserUtils::opBuffer);
    std::shared_ptr<ASTnode> highest_precedence_node = parserUtils::to_node(highest_precedence_op);

    parserUtils::rem_buffered_op(highest_precedence_op);
}


std::vector<ASTnode> numericalExprAST::NumExprAST(std::vector<Token> &Tokens)
{
    parserUtils::clearBuffer();

    OpTok curTok;
    for (int i = 0; i <= Tokens.size(); i++)
    {
        curTok = Tokens[i];
        if (parserUtils::isBinary(curTok.value))
        {
            curTok.rightChild = Tokens[i - 1]; //TODO: Make Tokens a unique_ptr or something. Idk. 
            parserUtils::buffer_Op(curTok);
            curTok.leftChild = Tokens[i + 1];
        }
    }
    
}

