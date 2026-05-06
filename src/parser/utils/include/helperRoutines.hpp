#pragma once
#include "ASTNode.hpp"

namespace parserUtils {
    Precedence getPrecedence(ASTnode opNode); 
    bool isBinary(std::string op); 
}