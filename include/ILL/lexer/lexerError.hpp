#pragma once
#include <iostream> 

struct LexerError {
    std::string message; 
    int line; 
    int column;
};

