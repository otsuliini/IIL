#include <iostream>
#include <vector>
#include "tokens.hpp"
#include "utils.hpp"


std::vector<std::string> splitString(const std::string &sourceCode) {
    std::vector<std::string> words;
    std::string word;

    for (char ch : sourceCode) {
        
        if (ch != ' ') {
            word += ch;
        } else if (!word.empty()) { //! TODO: Make it check for multi line comments
            if (word[0] == '#' && word[1] == '#'){
                words.push_back(word);
                word.clear();
            }
            word.clear();
        }
    } 

    if (!word.empty()) {
        words.push_back(word); 
    }

    return words;
}



std::vector<Token> tokenize(std::string &sourceCode){
    std::vector<Token> tokens;
    std::vector<std::string> src = splitString(sourceCode);

    while (!src.empty()){
        if (src.front() == "(") {
            tokens.emplace_back(TokenType::OpenParen, shift(src));
        }
        else if (src.front() == ")") {
            tokens.emplace_back(TokenType::CloseParen, shift(src));
        }
        else if (src.front() == ";") {
            tokens.emplace_back(TokenType::Delimiter, shift(src));
        }
        else if (src.front() == ",") {
            tokens.emplace_back(TokenType::Delimiter, shift(src));
        }
        else if (src.front() == "\"") {
            tokens.emplace_back(TokenType::Delimiter, shift(src));
        }
        else if (src.front() == "+") {
            tokens.emplace_back(TokenType::Operator, shift(src));
        }
        else if (src.front() == "-") {
            tokens.emplace_back(TokenType::Operator, shift(src));
        }
        else if (src.front() == "*") {
            tokens.emplace_back(TokenType::Operator, shift(src));
        }
        else if (src.front() == "/") {
            tokens.emplace_back(TokenType::Operator, shift(src));
        }
        else if (src.front() == "%") {
            tokens.emplace_back(TokenType::Operator, shift(src));
        }
        else if (src.front() == "<") {
            tokens.emplace_back(TokenType::Operator, shift(src));
        }
        else if (src.front() == ">") {
            tokens.emplace_back(TokenType::Operator, shift(src));
        }
        else if (src.front() == "=") {
            tokens.emplace_back(TokenType::Operator, shift(src));
        }
        else if (isalpha(src.front()[0])){// get first character of string from vector. 

        }
        else if (src.front() == "\t") {
            tokens.emplace_back(TokenType::Indent, shift(src));
        }
        else if (isSkippable(src.front()[0])){
            shift(src);
        }

    }
    return tokens;     
}