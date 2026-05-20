#pragma once
#include <cstddef>
#include <memory>
#include <new>
#include <vector>
#include "lexer/tokens.hpp"
#include "parser/expr.hpp"
#include "parser/parsing.hpp"

struct ParseError {
    Token token_;
    std::string message_;

    ParseError() : token_(nullToken), message_(" ") {}
    ParseError(Token token, std::string message)
        : token_(token), message_(message) {}
};

class Parser {
   protected:
    Arena arena;

   private:
   public:
    virtual Token advance();
    virtual Token peek() const;
    virtual bool isAtEnd() const;
    void synchronize();
    virtual ~Parser() = default;
};  // Class: Parser

class expressionParsing : public Parser {
    unsigned int current = 0;

    // Check if the current token has any of the given types. If it does we consume the token
    // and reutrn true. Else it returns false and leaves the token alone. The match() method is
    // defined in terms of two ore more fundemental operations
    template <typename... Types>
    bool match(Types... types) const {
        return ((check(types) && (advance(), true)) || ...);
        //     ^ If this is true we evaluate this^
    }

    ParseError error(Token token, std::string message);
    Token consume(TokenType type, std::string message);
    Token previous() const;
    Token peek() const override;
    bool isAtEnd() const override;
    std::variant<PrimaryExpr*, Literal*, Grouping*> primary();
    Expr* unary();

    Expr* factor();
    Expr* term();
    Expr* comparison();
    std::vector<Token> tokens;
    Token advance() override;
    bool check(TokenType type);

    Expr* equality();
    Expr* expression();  // Unique_ptr is used because an astNode belongs
                         // to exactly one parent.

    // move tokens so we don't have to make copy:
   public:
    expressionParsing(std::vector<Token> Tokens) : tokens(std::move(Tokens)) {}
};  // Class: expressionParsing