#include "ASTNode.hpp"
#include "helperRoutines.hpp"
#include "parserError.hpp"
#include <exception>

Precedence parserUtils::analyzePrecedence(ASTnode opNode) {
    std::string value = opNode.NodeValue.value; 

    if (value == "**"){
        return Expo; 
    }
    else if (value == "*"){
        return Multi; 
    }
    else if (value == "/"){
        return Divis; 
    }
    else if (value == "%"){
        return Modulus; 
    }
    else if (value == "+"){
        return Addition; 
    }
    else if (value == "-"){
        return Subtract; 
    }
    else {
        //! Add error handling.
    }
}