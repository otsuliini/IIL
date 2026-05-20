#include "parser/parsing.hpp"
#include "lexer/tokens.hpp"
#include "parser/arena.hpp"
#include "parser/expr.hpp"
#include <memory>
#include <variant>
#include <vector>

// Each method for parsing a grammar rule produces an AST for that rule and returns it to the
// caller. When the body of the rule contains a nonterminal (a reference to another rule). We call
// that other rule's method.
Token expressionParsing::previous() const { return tokens[current - 1]; }
Token expressionParsing::peek() const { return tokens[current]; }
auto expressionParsing::isAtEnd() const { return peek().type_ == TokenType::FileEnd; }

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
std::variant<PrimaryExpr *, Literal *, Grouping *> expressionParsing::primary() {
    // TODO: fix the errors lol
    if (match(TokenType::False)) {
        Literal *expr = arena.make<Literal>("false");
        return expr;
    }
    if (match(TokenType::True)) {
        Literal *expr = arena.make<Literal>("true");
        return expr;
    }
    if (match(TokenType::NIL)) {
        Literal *expr = arena.make<Literal>("NULL");
        return expr;
    }

    if (match(TokenType::Number, TokenType::String)) {
        // TODO: FIX
        return arena.make<Literal>(previous().value_);
    }

    if (match(TokenType::OpenParen)) {
        BinaryExpr *expr = expression();
        // TODO: Implement better error handling:
        // TODO: Implement auto parenthesis insertion.
        consume(TokenType::CloseParen, "Expect ')' after expression.");
        return arena.make<Grouping>(expr);
    }
}
// The rule for unary is:
// ( "!" | "-" ) unary | primary ;
UnaryExpr *expressionParsing::unary() {
    if (match(TokenType::Bang, TokenType::Minus)) {
        Token op = previous();
        UnaryExpr *right = unary();
        return arena.make<UnaryExpr>(std::move(op), std::move(unary));
    }
    return make_unary_ptr<UnaryExpr>(primary());
}

BinaryExpr *expressionParsing::factor() {
    // Todo: implement a "make_unary<>" function or template.
    BinaryExpr *expr = make_binary_ptr<BinaryExpr>(unary());
    while (match(TokenType::Slash, TokenType::Star)) {
        Token op = previous();
        UnaryExpr *right = unary();
        return arena.make<BinaryExpr>(std::move(op), std::move(right));
    }
    return expr;
}

BinaryExpr *expressionParsing::term() {
    BinaryExpr *expr = factor();

    while (match(TokenType::Minus, TokenType::Plus)) {
        Token op = previous();
        BinaryExpr *right = factor();
        expr = arena.make<BinaryExpr>(std::move(expr), op, std::move(right));
    }
    return expr;
}

// The rule for comparison is:
// term ( ( ">"| ">=" | "<" | "<=" ) term )* ;
BinaryExpr *expressionParsing::comparison() {
    BinaryExpr *expr = term();

    while (
        match(TokenType::Greater, TokenType::GreaterEqual, TokenType::Less, TokenType::LessEqual)) {
        Token op = previous();
        BinaryExpr *right = term();
        expr = arena.make<BinaryExpr>(std::move(expr), op, std::move(right));
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
BinaryExpr *expressionParsing::equality() {
    // Call the first comparison as shown in the production rules.
    BinaryExpr *expr = arena.make<BinaryExpr>(comparison());

    // The (...)* loop in the rule is a while loop:
    // The rule states that we must find either a != or == token.
    // So if we don't see one of those, we are done with the sequence of equality
    // operators. We express that check using the match() method.
    while (match(TokenType::BangEqual, TokenType::EqualEqual)) {
        Token op = previous();

        auto right = comparison();
        // construct AST:
        expr = arena.make<BinaryExpr>(std::move(expr), op, std::move(right));
    }

    return expr;
}

// Expression expands to the equality rule.
// Expresson := equality;
BinaryExpr *expressionParsing::expression() { return equality(); }
