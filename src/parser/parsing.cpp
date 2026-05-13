#include "parser/parsing.hpp"
#include "parser/ast/ASTNode.hpp"
#include "parser/utils/helperRoutines.hpp"
#include <vector>
#include <memory> 
// Example: 1 + 1. Tokens are '1' '+' and '1'

std::vector<std::shared_ptr<ASTNode>> numericalExprAST::connect_nodes(std::vector<OpTok> opTokens)
{
    OpTok highest_precedence_op = parserUtils::getHighestPrecedence(parserUtils::opBuffer);
    std::shared_ptr<ASTNode> highest_precedence_node = parserUtils::to_node_op(highest_precedence_op);

    parserUtils::rem_buffered_op(highest_precedence_op);
}


std::vector<ASTNode> numericalExprAST::NumExprAST(std::vector<Token> &Tokens)
{
    parserUtils::clearBuffer();

    OpTok curTok; 
    for (int i = 0; i <= Tokens.size(); i++)
    {
        curTok = Tokens[i];
        if (parserUtils::isBinary(curTok.value))
        {
            std::unique_ptr<Token> unique_ptr_left = std::make_unique<Token>(Tokens[i - 1]); 
            std::unique_ptr<Token> unique_ptr_right = std::make_unique<Token>(Tokens[i + 1]); 

            curTok.rightChild = std::make_unique<OpTok>(unique_ptr_left, left_child_t{}); // Heap allocation
            curTok.rightChild = std::make_unique<OpTok>(unique_ptr_left, left_child_t{});
            parserUtils::buffer_Op(curTok);
        }
    }
}