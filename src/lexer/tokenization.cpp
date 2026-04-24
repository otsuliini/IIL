#include <iostream>
#include <vector>
#include "include/IIL/lexer/tokens.hpp"
#include "../src/lexer/utils/include/isSkippable.hpp"
#include "../src/lexer/utils/include/isNumber.hpp"
#include "../src/lexer/utils/include/isDelimiter.hpp"
#include "../src/lexer/utils/include/shift.hpp"
#include "IIL/lexer/lexerError.hpp"
#include <unordered_set> 
#include "IIL/lexer/tokenization.hpp"

std::string source; 
int line = 1; 
int column = 1; 


std::vector<LexerError> errors; 


std::vector<std::string> tokenizing::splitString() {
    std::vector<std::string> chunks;
    std::string buffer;
    std::string val; 

    for (int i = 0; i < source.size(); i++) {  
        char ch = source[i];

        if (utils::isDelimiter(ch)) { // split the strings based off some parameters. 
            if (!buffer.empty()){
                chunks.push_back(buffer); // push the buffer 
                buffer.clear();
            }
            chunks.push_back(std::string(1, ch)); // push the actual delimiter
        } 

        else if (ch == ' '){
            if (!buffer.empty()){
                chunks.push_back(buffer);
                buffer.clear();
            }
        }

        else if (ch == '#' && i + 1 < source.size() && source[i + 1] == '#' && i + 2 < source.size() && source[i + 2] == '#') {
            if (!buffer.empty()) {
                chunks.push_back(buffer);
                buffer.clear();
            }
            i += 3; //skip firt 3 hashtags 
            while (i + 2 < source.size() && !(source[i] == '#' && source[i + 1] == '#' && source[i + 2] == '#')) {
                i++;
            }
            if (i + 2 >= source.size()){
                errors.push_back(LexerError{"Unknown token: " + line, column});
            }
            i += 3; // skip last 3 hashtags 
        }

        else if (ch == '#' && i + 1 < source.size()  && source[i + 1] == '#') { 
            
            if (!buffer.empty()){
                chunks.push_back(buffer);
                buffer.clear();
            }
            while (i < source.size() && source[i] != '\n') {
                i++;
            }
            continue; 
        }
        
        else {
            buffer += ch;
        }
    } 

    if (!buffer.empty()) {
        chunks.push_back(buffer); 
    }

    return chunks;
}




std::vector<Token> tokenizing::tokenize(std::string &sourceCode){
    source = sourceCode;
    std::vector<Token> tokens;
    std::vector<std::string> src = splitString();
    line = 1; // Reset each function call
    column = 1; 
    

    while (!src.empty()){
        if (src.front() == "\n"){
            line++; 
            column = 1; 
            utils::shift(src); 
        }
        else if (operators.count(src.front())) {
            tokens.emplace_back(TokenType::Operator, utils::shift(src), line, column);
            column++;
        }
        else if (delimiters.count(src.front())) {
            tokens.emplace_back(TokenType::Delimiter, utils::shift(src), line, column);
            column++;
        }
        else if (src.front() == "(") {
            tokens.emplace_back(TokenType::OpenParen, utils::shift(src), line, column);
            column++;
        }
        else if (src.front() == ")") {
            tokens.emplace_back(TokenType::CloseParen, utils::shift(src), line, column);
            column++;
        }
        else if (keywords.count(src.front())){
            tokens.emplace_back(TokenType::Keyword, utils::shift(src), line, column);
        }         
        else if (src.front() == "\t") {
            tokens.emplace_back(TokenType::Indent, utils::shift(src), line, column);
            column++; 
        }
        else if (utils::isSkippable(src.front()[0])){
            utils::shift(src);
        }

        else if(utils::isNumber(src.front())){
            std::string number; 

            while(!src.empty() && utils::isNumber(src.front())){
                number += utils::shift(src); 
            }

            tokens.emplace_back(TokenType::Number, number, line, column);
        }
        else {
            tokens.emplace_back(TokenType::Identifier, utils::shift(src), line, column);
            column++; 
        }
        
    }
    tokens.emplace_back(TokenType::FileEnd, "fileEnd", line, column); 
    return tokens;     
}

