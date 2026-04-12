#include <iostream>
#include <vector>
#include "tokens.hpp"
#include "utils.hpp"
#include "lexerError.hpp"

class tokenizing{
    std::string source; 
    

    std::vector<std::string> splitString() {
        std::vector<std::string> chunks;
        std::string buffer;

        for (int i = 0 < source.size(); i++;) {  
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
            else if (!buffer.empty()) { //! TODO: Make it check for multi line comments
                
                if (ch == '#' && i + 1 < source.size()  && source[i + 1] == '#'){
                    if (!buffer.empty()){
                        chunks.push_back(buffer);
                        buffer.clear();
                    }
                    while (ch < source.size() && source[i] != '\n') {
                        i++;
                    }
                    continue; 
                }
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


    public: 

    std::vector<LexerError> errors;  //! Todo implement line and column tracking. 

    std::vector<Token> tokenize(std::string &sourceCode){
        std::vector<Token> tokens;
        std::vector<std::string> src = splitString();
        int line = 1; 
        int column = 1; 

        while (!src.empty()){
            if (src.front() == "\n"){
                line++; 
                column = 1; 
            }
            else if (src.front() == "(") {
                tokens.emplace_back(TokenType::OpenParen, utils::shift(src), line, column);
                column++; 
            }
            else if (src.front() == ")") {
                tokens.emplace_back(TokenType::CloseParen, utils::shift(src), line, column);
                column++; 
            }
            else if (src.front() == ";") {
                tokens.emplace_back(TokenType::Delimiter, utils::shift(src), line, column);
                column++; 
            }
            else if (src.front() == ",") {
                tokens.emplace_back(TokenType::Delimiter, utils::shift(src), line, column);
                column++; 
            }
            else if (src.front() == "\"") {
                tokens.emplace_back(TokenType::Delimiter, utils::shift(src), line, column);
                column++; 
            }
            else if (src.front() == "+") {
                tokens.emplace_back(TokenType::Operator, utils::shift(src), line, column);
                column++; 
            }
            else if (src.front() == "-") {
                tokens.emplace_back(TokenType::Operator, utils::shift(src), line, column);
                column++; 
            }
            else if (src.front() == "*") {
                tokens.emplace_back(TokenType::Operator, utils::shift(src), line, column);
                column++; 
            }
            else if (src.front() == "/") {
                tokens.emplace_back(TokenType::Operator, utils::shift(src), line, column);
                column++; 
            }
            else if (src.front() == "%") {
                tokens.emplace_back(TokenType::Operator, utils::shift(src), line, column);
                column++; 
            }
            else if (src.front() == "<") {
                tokens.emplace_back(TokenType::Operator, utils::shift(src), line, column);
                column++; 
            }
            else if (src.front() == ">") {
                tokens.emplace_back(TokenType::Operator, utils::shift(src), line, column);
                column++; 
            }
            else if (src.front() == "=") {
                tokens.emplace_back(TokenType::Operator, utils::shift(src), line, column);
                column++; 
            }
            else if (isalpha(src.front()[0])){// get first character of string from vector. 
                std::string word = utils::shift(src);
                if (word[0] == 'd' && word[1] == 'o'){  
                    try {
                        if(word.at(2) == ':'){
                            try {
                                if (word.at(3) == ' '){
                                    tokens.emplace_back(TokenType::Operator, utils::shift(src), line, column);
                                    column++; 
                                }
                            } 
                            catch (const std::out_of_range& e ) {
                                std::cout << "expression is longer then 4 characters. It's not a do: expression\n";
                            }
                        }
                        else {
                            errors.push_back({"Expected '}'", line, column}); 
                        }
                    }
                    catch (const std::out_of_range& e){
                        std::cout << "Index out of range\n";
                    }  
                    
                }
                else if(word == "iwhile"){
                    tokens.emplace_back(TokenType::Keyword, utils::shift(src), line, column);
                    column++; 
                }
                else if(word == "iFor"){
                    tokens.emplace_back(TokenType::Keyword, utils::shift(src), line, column);
                    column++; 
                }
                else if(word == "exit"){
                    tokens.emplace_back(TokenType::Keyword, utils::shift(src), line, column); 
                    column++; 
                }
                else if(word == "iend"){
                    tokens.emplace_back(TokenType::Keyword, utils::shift(src), line, column);
                    column++; 
                }
                else if(word == "ifor"){
                    tokens.emplace_back(TokenType::Keyword, utils::shift(src), line, column);
                    column++;
                }
                else if(word == "ibreak"){
                    tokens.emplace_back(TokenType::Keyword, utils::shift(src), line, column);
                    column++;
                }
                else if(word == "itry"){
                    tokens.emplace_back(TokenType::Keyword, utils::shift(src), line, column); 
                }
                else if(word == "ixcept"){
                    tokens.emplace_back(TokenType::Keyword, utils::shift(src), line, column);
                }
                else if(word == "ifinally do:"){
                    tokens.emplace_back(TokenType::Keyword, utils::shift(src), line, column);
                }
                
            }
            else if (src.front() == "\t") {
                tokens.emplace_back(TokenType::Indent, utils::shift(src), line, column);
                column++; 
            }
            else if (utils::isSkippable(src.front()[0])){
                utils::shift(src);
            }

            else if(utils::is_number(src.front())){
                std::string number; 

                while(!src.empty() && utils::is_number(src.front())){
                    number += utils::shift(src); 
                }

                tokens.emplace_back(TokenType::Number, TokenType::Number);
            }
            
        }
        return tokens;     
    }
};