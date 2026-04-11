#ifndef LEXERERROR_HPP
#define LEXERERRO_HPP
#include <iostream> 
#pragma once


struct LexerError {
    std::string message; 
    int line; 
    int column;
};

#endif

