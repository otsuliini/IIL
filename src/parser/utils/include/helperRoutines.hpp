#pragma once
#include "ASTNode.hpp"
#include "tokens.hpp"
#include <type_traits>
#include <variant>

namespace parserUtils
{
    std::string right_associative_ops[10] =
        {
            "=",
            "+=",
            "-=",
            "*=",
            "/=",
            "%=",
            "**",
            "++",
            "--"};

    Precedence getPrecedence(ASTnode opNode);
    bool isBinary(std::string op);

    enum class PrecedenceResult
    {
        Token1,
        Token2,
        Equal
    };

    template <typename T, typename U = T>
    PrecedenceResult comparePrecedence(T token_1, U token_2)
    {
        Precedence p1 = getPrecedence(token_1.value);
        Precedence p2 = getPrecedence(token_2.value);

        if (p2 > p1)
            return PrecedenceResult::Token2;
        if (p2 == p1)
            return PrecedenceResult::Equal;
        return PrecedenceResult::Token1;
    }

    bool isRightAssociative(Token op); 
    
}
