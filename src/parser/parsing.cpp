#include "parser/parsing.hpp"
#include <memory>
#include <variant>
#include <vector>
#include "lexer/tokens.hpp"
#include "parser/arena.hpp"
#include "parser/expr.hpp"

// Each method for parsing a grammar rule produces an AST for that rule and returns it to the
// caller. When the body of the rule contains a nonterminal (a reference to another rule). We call
// that other rule's method.
Token expressionParsing::previous() const {
    return tokens[current - 1];
}
Token expressionParsing::peek() const {
    return tokens[current];
}
bool expressionParsing::isAtEnd() const {
    return peek().type_ == TokenType::FileEnd;
}

Token expressionParsing::advance() {
    if (!isAtEnd())
        current++;
    return previous();
}
ParseError expressionParsing::error(Token token, std::string message) {
    ParseError error;
    error.message_ = message;
    error.token_ = token;

    return error;
}

Token expressionParsing::consume(TokenType type, std::string message) {
    if (check(type)) {
        return advance();
    }
    throw error(peek(), message);
}

// The rule for primary is:
// NUMBER | STRING | "true" | "false" | "null" | "(" expression ")" ;
Expr* expressionParsing::primary() {
    // TODO: fix the errors lol
    if (match(TokenType::False)) {
        Expr* expr = arena.make<Expr>("false");
        return expr;
    }
    if (match(TokenType::True)) {
        Expr* expr = arena.make<Expr>("true");
        return expr;
    }
    if (match(TokenType::NIL)) {
        Expr* expr = arena.make<Expr>("NULL");
        return expr;
    }

    if (match(TokenType::Number, TokenType::String)) {
        // TODO: FIX
        return arena.make<Expr>(previous().value_);
    }

    if (match(TokenType::OpenParen)) {
        Expr* expr = expression();
        // TODO: Implement better error handling:
        // TODO: Implement auto parenthesis insertion.
        consume(TokenType::CloseParen, "Expect ')' after expression.");
        return arena.make<Grouping>(expr);
    }
}
// The rule for unary is:
// ( "!" | "-" ) unary | primary ;
Expr* expressionParsing::unary() {
    if (match(TokenType::Bang, TokenType::Minus)) {
        Token op = previous();
        Expr* right = unary();
        return arena.make<Expr>(std::move(op), std::move(unary));
    }
    return make_unary_ptr<Expr*>(primary());
}

Expr* expressionParsing::factor() {
    // Todo: implement a "make_unary<>" function or template.
    Expr* expr = unary();
    while (match(TokenType::Slash, TokenType::Star)) {
        Token op = previous();
        Expr* right = unary();
        return arena.make<Expr>(std::move(op), std::move(right));
    }
    return expr;
}

Expr* expressionParsing::term() {
    Expr* expr = factor();

    while (match(TokenType::Minus, TokenType::Plus)) {
        Token op = previous();
        Expr* right = factor();
        expr = arena.make<Expr>(std::move(expr), op, std::move(right));
    }
    return expr;
}

// The rule for comparison is:
// term ( ( ">"| ">=" | "<" | "<=" ) term )* ;
Expr* expressionParsing::comparison() {
    Expr* expr = term();

    while (match(TokenType::Greater, TokenType::GreaterEqual, TokenType::Less,
                 TokenType::LessEqual)) {
        Token op = previous();
        Expr* right = term();
        expr = arena.make<Expr>(std::move(expr), op, std::move(right));
    }
    return expr;
}

// Check method returns true if the current token is of the given type.
bool expressionParsing::check(TokenType type) {
    if (isAtEnd()) {
        return false;
    }
    return (peek().type_ == type);
}

// The rule for equalitys is:
// Equality := comparison ( ( "!=" | "==") comparison)* ;
Expr* expressionParsing::equality() {
    // Call the first comparison as shown in the production rules.
    Expr* expr = arena.make<Expr>(comparison());

    // The (...)* loop in the rule is a while loop:
    // The rule states that we must find either a != or == token.
    // So if we don't see one of those, we are done with the sequence of equality
    // operators. We express that check using the match() method.
    while (match(TokenType::BangEqual, TokenType::EqualEqual)) {
        Token op = previous();

        auto right = comparison();
        // construct AST:
        expr = arena.make<Expr>(std::move(expr), op, std::move(right));
    }

    return expr;
}

// Expression expands to the equality rule.
// Expresson := equality;
Expr* expressionParsing::expression() {
    return equality();
}
