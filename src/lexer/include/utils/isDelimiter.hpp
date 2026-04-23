#pragma once
#include <iostream> 
#include "ILL/lexer/tokens.hpp"

namespace utils {
    bool isDelimiter(char ch){
        return delimiters.count(std::string(1, ch));  // converts the input into a string and checks if input is delimiter using count() 
    }
}