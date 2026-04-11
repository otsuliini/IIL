#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream> 

bool is_number(const std::string& s);

std::string shift(std::vector<std::string, std::allocator<std::string>>& src);

bool isSkippable(char token);


#endif 

