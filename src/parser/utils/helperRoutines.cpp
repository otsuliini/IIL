#include "ASTNode.hpp"
#include "helperRoutines.hpp"
#include "parserError.hpp"
#include "parsing.hpp"
#include <exception>
#include "tokens.hpp"

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