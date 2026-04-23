#pragma once

#include <iostream> 
namespace utils{
    bool isNumber(const std::string& s);

    std::string shift(std::vector<std::string, std::allocator<std::string>>& src);

    bool isSkippable(char token);
    
    bool isDelimiter(char c); 
    
    
}

    