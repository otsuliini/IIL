#include <iostream> 
#include <bits/stdc++.h> 
#include "utils.hpp"
namespace utils{
    bool is_number(const std::string& s)
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
    }
}