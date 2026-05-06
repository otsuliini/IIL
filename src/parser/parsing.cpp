#include "parsing.hpp"
#include "ASTNode.hpp"
#include "helperRoutines.hpp"
// Example: 1 + 1. Tokens are '1' '+' and '1'

std::vector<ASTnode> numericalExprAST::NumExprAST(std::vector<Token> &Tokens, const Precedence minPrecedence)
{

    std::string op;
    Token CurTok;
    int i = 1;
    lookAheadToken lookAhead = Tokens[i];
    
    while (lookAhead.precedence >= minPrecedence && parserUtils::isBinary(lookAhead.value))
    {
        CurTok = Tokens[i];
        op = lookAhead.value;
        // Logic Here:
        
        // Move CurTok:
        i++;
    }
}
