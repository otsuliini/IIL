#pragma once
#include <iostream>
#include <vector>
#include "tokens.hpp"
#include "errors/lexerError.hpp"
class tokenizing
{
public:
    std::vector<LexerError> errors;

private:
    std::string source;
    std::optional<unsigned int> line = 1;
    std::optional<unsigned int> column = 1;

    [[nodiscard]] std::vector<std::string> splitString();

public:
    [[nodiscard]] std::vector<Token> tokenize(std::string &sourceCode);
};