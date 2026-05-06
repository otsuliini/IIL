#include <vector>
#include "ASTNode.hpp"
#include "tokens.hpp"

class numericalExprAST
{
public:
    std::vector<ASTnode> NumExprAST(std::vector<Token> &Tokens, Precedence minPrecedence);
};

struct lookAheadToken : Token
{
    Precedence precedence;

    lookAheadToken(Token token) : precedence(LEVEL0), Token(token.type, token.value, token.line, token.column) {}
   
    lookAheadToken(Precedence prece) : precedence(prece) {}
    
    lookAheadToken() : precedence(LEVEL0) {}
};