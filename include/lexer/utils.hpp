#ifndef UTILS_HPP
#define UTILS_HPP
#pragma once

#include <iostream> 
namespace utils{
    bool is_number(const std::string& s);

    std::string shift(std::vector<std::string, std::allocator<std::string>>& src);

    bool isSkippable(char token);

    bool isDelimiter(char c); 

}


#endif 

