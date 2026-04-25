#include "errorRoutines.hpp"
#include <memory>
#include <iostream>
#include "parser/parse.hpp"

// Log error

std::unique_ptr<ExprAST> LogError(const char *Str)
{
    fprintf(stderr, "Error: %s\n", Str);
    return nullptr; 
} 
