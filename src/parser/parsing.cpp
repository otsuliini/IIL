#include "parser/parsing.hpp"
#include "parser/expr.hpp"
#include <memory>
#include <vector>

// The rule for comparison is:
// term ( ( ">"| ">=" | "<" | "<=" ) term )* ;
Expr Parser::expressionParsing::comparison() {
    Expr expr = term();

    while (match(Greater, GreaterEqual, Less, LessEqual)) {
        Token op = previous();
        Expr right = term();
        expr = std::make_unique
    }
}

// Each method for parsing a grammar rule produces an AST for that rule and returns it to the
// caller. When the body of the rule contains a nonterminal (a reference to another rule). We call
// that other rule's method.
Token Parser::expressionParsing::previous() const { return tokens[current - 1]; }
Token Parser::expressionParsing::peek() const { return tokens[current]; }
auto Parser::expressionParsing::isAtEnd() const { return peek().type == TokenType::FileEnd; }

Token Parser::expressionParsing::advance() {
    if (!isAtEnd())
        current++;
    return previous();
}

// Check method returns true if the current token is of the given type.
bool Parser::expressionParsing::check(TokenType type) {
    if (isAtEnd()) {
        return false;
    }
    return (peek().type == type);
}

// The rule for equalitys is:
// Equality := comparison ( ( "!=" | "==") comparison)* ;
std::unique_ptr<Expr> Parser::expressionParsing::equality() {
    // Call the first comparison as shown in the production rules.
    std::unique_ptr<Expr> expr = comparison();

    // The (...)* loop in the rule is a while loop:
    // The rule states that we must find either a != or == token.
    // So if we don't see one of those, we are done with the sequence of equality operators.
    // We express that check using the match() method.
    while (match(TokenType::BangEqual, TokenType::EqualEqual)) {
        Token op = previous();

        auto right = comparison();
        // construct AST:
        expr = std::make_unique<BinaryExpr>(std::move(expr), op, std::move(right));
    }

    return expr;
}

// Expression expands to the equality rule.
// Expresson := equality;
std::unique_ptr<Expr> Parser::expressionParsing::expression() { return equality(); }
