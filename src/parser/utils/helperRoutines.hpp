#pragma once
#include "parser/ast/ASTNode.hpp"
#include "lexer/tokens.hpp"
#include <type_traits>
#include <variant>
#include <vector>
#include <memory>
namespace parserUtils
{   
    class operatorBuffer {
        std::vector<Token> opBuffer;
    public:
        
        void rem_buffered_op(Token op); 
        void clearBuffer(); 
        void buffer_Op(Token token); 

        std::vector<Token> getBuffer() {
            return opBuffer; 
        }

        operatorBuffer() {
            clearBuffer(); 
        }
    }; 

    Precedence getPrecedence(ASTNode opNode);
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

    [[nodiscard]] bool isRightAssociative(Token op); 
    [[nodiscard]] Token getHighestPrecedence(std::vector<Token> token);
    [[nodiscard]] std::shared_ptr<ASTNode> to_node_op(Token token); 
    [[nodiscard]] std::unique_ptr<ASTNode> to_node_ptr_token(std::unique_ptr<Token> token); 
    [[nodiscard]] std::unique_ptr<ASTNode> to_node_value_op();
} // namespace parserUtils


