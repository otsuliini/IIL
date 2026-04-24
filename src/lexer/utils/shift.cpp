#include "../src/lexer/utils/include/shift.hpp"
#include <bits/stdc++.h>
#include <vector> 

std::string utils::shift(std::vector<std::string, std::allocator<std::string>>& src) {
    std::string c = src.front(); //saves front element of the vector
    src.erase(src.begin()); // removes the first element using erase(begin())           
    return c;    
}
