#pragma once
#include "ASTNode.hpp"
#include "tokens.hpp"
#include <type_traits>
#include <variant>
#include <vector> 
#include <memory>
namespace parserUtils
{
    std::vector<Token> opBuffer;

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

    Precedence getPrecedence(ASTNode opNode);
    bool isBinary(std::string op);

    enum class PrecedenceResult
    {
        Token1,
        Token2,
        Equal
    };

    template <typename T, typename U = T>
    PrecedenceResult comparePrecedence(T token_1, U token_2) //! make specialized template 
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
    void buffer_Op(Token token); 
    void clearBuffer(); 
    Token getHighestPrecedence(std::vector<Token> token);
    void rem_buffered_op(Token op); 
    std::shared_ptr<ASTNode> to_node_op(Token token); 
    std::unique_ptr<ASTNode> to_node_ptr_token(std::unique_ptr<Token> token); 
    std::unique_ptr<ASTNode> to_node_value_op()
}


