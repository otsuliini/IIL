#pragma once
#include <iostream>
#include <vector>
#include "lexerError.hpp"
#include "tokens.hpp"

class tokenizing
{
public:
    std::vector<LexerError> errors;

private:
    std::string source;
    int line = 1;
    int column = 1;

    std::vector<std::string> splitString();

public:
    std::vector<Token> tokenize(std::string &sourceCode);
};