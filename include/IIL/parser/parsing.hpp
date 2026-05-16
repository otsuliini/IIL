#pragma once
#include "lexer/tokens.hpp"
#include "parser/Expr.hpp"
#include "parser/parsing.hpp"
#include <vector>

class Parser {
    class expressionParsing {
        unsigned int current = 0;
        std::vector<Token> tokens;
        Token previous() const;
        Token peek() const;
        bool isAtEnd() const;
        Token advance();
        bool check(TokenType type);

        // Check if the current token has any of the given types. If it does we consume the token
        // and reutrn true. Else it returns false and leaves the token alone. The match() method is
        // defined in terms of two ore more fundemental operations
        template <typename... Types> bool match(Types... types) const {
            return ((check(types) && (advance(), true)) || ...);
            //     ^ If this is true we evaluate this^
        }

        std::unique_ptr<Expr> equality();
        std::unique_ptr<Expr> expression(); // Unique_ptr is used because an astNode belongs
                                            // to exactly one parent.

        // move tokens so we don't have to make copy:
        expressionParsing(std::vector<Token> Tokens) : tokens(std::move(tokens)) {}
    }; // Class: expressionParsing
}; // Class: Parser
