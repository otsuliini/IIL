#include "ASTNode.hpp"
#include "helperRoutines.hpp"
#include "parserError.hpp"
#include "parsing.hpp"
#include <exception>
#include "tokens.hpp"
#include <iostream>
#include <algorithm>

Precedence parserUtils::getPrecedence(const Token token) {
    std::string value = token.value; 
    //! Add parentheses precedence

    if (value == "**"){
        return LEVEL3; 
    }
    else if (value == "*"){
        return LEVEL2; 
    }
    else if (value == "/"){
        return LEVEL2; 
    }
    else if (value == "%"){
        return LEVEL2; 
    }
    else if (value == "+"){
        return LEVEL1; 
    }
    else if (value == "-"){
        return LEVEL1; 
    }
    else if (value == "="){
        return LEVEL0; 
    }
    else {
        //! Add error handling.
    }
}


bool parserUtils::isBinary(std::string op) {
    
    auto iterator = std::find(operators.begin(), operators.end(), op); 
    if (iterator != operators.end()) {
        return true; 
    }
    else {
        return false; 
    }
}