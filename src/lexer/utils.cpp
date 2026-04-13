#include <iostream> 
#include <bits/stdc++.h> 
#include "lexer/utils.hpp"
#include "lexer/tokens.hpp"
namespace utils{
    bool isNumber(const std::string& s)
    {
        return !s.empty() && std::find_if(s.begin(), 
            s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
    }

    std::string shift(std::vector<std::string, std::allocator<std::string>>& src) {
        std::string c = src.front(); //saves first element of vector
        src.erase(src.begin()); // removes the first character
        return c;
    }

    bool isSkippable(char token){
        if (token == ' '){
            return true;       
        }
        return false; 
    }

    bool isDelimiter(char ch){
        return delimiters.count(std::string(1, ch));
    }

}