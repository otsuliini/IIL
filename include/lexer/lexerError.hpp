
#include <iostream> 
#pragma once


struct LexerError {
    std::string message; 
    int line; 
    int column;
};

