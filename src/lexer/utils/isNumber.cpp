#include "../src/lexer/utils/include/isNumber.hpp"
#include <string>
#include <iostream>
#include <algorithm>  

bool utils::isNumber(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(), // return true if the string is not empty and if "find_if() == s.end" returns true. 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end(); // find_if takes the parameters of where to start searching (iterator), where to stop searching (iterator). As well as the condition (lambda function in this case) to check on each element.
        /*
        this lambda function is basically the same as:  
        bool isNotDigit(unsigned char c){
            return !std::isdigit(c);  
        }
        */ 
        // If the condition is met find_if returns an iterator to the character of the string, and then we compare that to s.end() which is a position that marks the end of the string. 
        // If they match it returns true, which means find_if reached the end of the string (meaning it's a digit). 
        // in simple terms we are checking if the point where find_if exited is the end of the string. 
}
