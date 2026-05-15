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
    }; // Class: operatorBuffer
    template <typename T> 
    Precedence getPrecedence(T token) 
    {   
        try {
            std::string value = T.value;  //! This won't work for astnode yet idt. So fix this too. 
        } catch ( ... ) { //! This is bad pracitce (It's only temporary)
            std::cout << "template function getPrecedence() couldn't access T.value" << std::endl; 
        }
        std::string value = T.value; 
        //! Add parentheses precedence

        if (value == "**"){
            return Precedence::LEVEL3; 
        }
        else if (value == "*"){
            return Precedence::LEVEL2; 
        }
        else if (value == "/"){
            return Precedence::LEVEL2; 
        }
        else if (value == "%"){
            return Precedence::LEVEL2; 
        }
        else if (value == "+"){
            return Precedence::LEVEL1; 
        }
        else if (value == "-"){
            return Precedence::LEVEL1; 
        }
        else if (value == "="){
            return Precedence::LEVEL0; 
        }
        else {
            //! Add error handling.
        }
    }

    bool isBinary(std::string op);

    enum class PrecedenceResult
    {
        Token1,
        Token2,
        Equal
    };

    template <typename T, typename U = T> 
    PrecedenceResult comparePrecedence(const T token_1, const U token_2)
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


