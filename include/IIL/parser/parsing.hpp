#include <vector>
#include "ASTNode.hpp"
#include "tokens.hpp"

class numericalExprAST {
    public: 
    std::vector<ASTnode> NumExprAST(std::vector<Token> &Tokens, Precedence minPrecedence);
}; 

struct lookAheadToken {
    Precedence precedence;

    lookAheadToken(Precedence prece) {
        precedence = prece; 
    }
    lookAheadToken() : precedence(LEVEL0) {}
}; 