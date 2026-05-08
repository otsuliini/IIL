#include "parsing.hpp"
#include "ASTNode.hpp"
#include "helperRoutines.hpp"
// Example: 1 + 1. Tokens are '1' '+' and '1'

std::vector<ASTnode> numericalExprAST::NumExprAST(std::vector<Token> &Tokens, const Precedence minPrecedence)
{

    /* PSEUDOCODE TO FOLLOW:
    parse_expression_1(lhs, min_precedence)
    lookahead := peek next token
    while lookahead is a binary operator whose precedence is >= min_precedence
        op := lookahead
        advance to next token
        rhs := parse_primary ()
        lookahead := peek next token
        while lookahead is a binary operator whose precedence is greater
                 than op's, or a right-associative operator
                 whose precedence is equal to op's
            rhs := parse_expression_1 (rhs, precedence of op + (1 if lookahead precedence is greater, else 0))
            lookahead := peek next token
        lhs := the result of applying op with operands lhs and rhs
    return lhs
    */

    Token op;
    Token CurTok;
    int i = 1;
    lookAheadToken lookAhead = Tokens[i + 1];

    while (lookAhead.precedence >= minPrecedence && parserUtils::isBinary(lookAhead.value))
    {
        CurTok = Tokens[i];
        lookAhead = Tokens[i + 1];
        op = lookAhead;
        i++;

        parseRHS(CurTok, op);
        auto result = parserUtils::comparePrecedence<lookAheadToken, Token>(lookAhead, op);

        while ((parserUtils::isBinary(lookAhead.value) &&
                parserUtils::comparePrecedence(lookAhead, op) == parserUtils::PrecedenceResult::Token2) ||
               (parserUtils::isRightAssociative(op) && parserUtils::comparePrecedence(lookAhead, op) == parserUtils::PrecedenceResult::Equal))
        {
        }
    }
}

std::shared_ptr<ASTnode> numericalExprAST::parseRHS(const Token number, const Token Oper)
{
    struct std::shared_ptr<ASTnode> num;
    num->NodeValue = number;

    struct std::shared_ptr<ASTnode> op;
    op->leftChild = num;
}