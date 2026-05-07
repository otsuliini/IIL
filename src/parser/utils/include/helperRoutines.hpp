#pragma once
#include "ASTNode.hpp"
#include "tokens.hpp"
#include <type_traits> 
namespace parserUtils {
    Precedence getPrecedence(ASTnode opNode); 
    bool isBinary(std::string op); 
    
    template <typename T, typename U = T> T comparePrecedence(T token_1, U token_2 = T) {
        Precedence token_1_precedence = getPrecedence(token_1.value); 
        Precedence token_2_precedence = getPrecedence(token_2.value); 

        if (token_2_precedence > token_1_precedence) {
            return token_2; 
        }
        else if (token_2_precedence == token_1_precedence) {
            return NULL; 
        }
        else {
            return token_1; 
        }
    }
}