#include "parsing.hpp"
#include "ASTNode.hpp"
#include "helperRoutines.hpp"
// Example: 1 + 1. Tokens are '1' '+' and '1'

std::vector<ASTnode> numericalExprAST::NumExprAST(std::vector<Token> &Tokens, Precedence minPrecedence)
{
    lookAheadToken lookAhead;
    std::string op; 

    for (int i; i <= Tokens.size(); i++) {
        lookAhead.precedence = parserUtils::getPrecedence(Tokens[i + 1]);
    }

    while (lookAhead.precedence >= minPrecedence) {
        op = lookAhead
    }
        
}

