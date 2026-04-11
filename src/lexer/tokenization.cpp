#include <iostream>
#include <vector>
#include "tokens.hpp"
#include "utils.hpp"
#include "lexerError.hpp"

class tokenizing{
    std::string source; 
    size_t pos = 0; 
    int line = 1; 
    int column = 1; 

    std::vector<std::string> splitString() {
        std::vector<std::string> words;
        std::string word;

        for (char ch : source) {
            
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


    public: 

    std::vector<LexerError> errors;  //! Todo implement line and column tracking. 

    std::vector<Token> tokenize(std::string &sourceCode){
        std::vector<Token> tokens;
        std::vector<std::string> src = splitString();

        while (!src.empty()){
            if (src.front() == "(") {
                tokens.emplace_back(TokenType::OpenParen, utils::shift(src));
            }
            else if (src.front() == ")") {
                tokens.emplace_back(TokenType::CloseParen, utils::shift(src));
            }
            else if (src.front() == ";") {
                tokens.emplace_back(TokenType::Delimiter, utils::shift(src));
            }
            else if (src.front() == ",") {
                tokens.emplace_back(TokenType::Delimiter, utils::shift(src));
            }
            else if (src.front() == "\"") {
                tokens.emplace_back(TokenType::Delimiter, utils::shift(src));
            }
            else if (src.front() == "+") {
                tokens.emplace_back(TokenType::Operator, utils::shift(src));
            }
            else if (src.front() == "-") {
                tokens.emplace_back(TokenType::Operator, utils::shift(src));
            }
            else if (src.front() == "*") {
                tokens.emplace_back(TokenType::Operator, utils::shift(src));
            }
            else if (src.front() == "/") {
                tokens.emplace_back(TokenType::Operator, utils::shift(src));
            }
            else if (src.front() == "%") {
                tokens.emplace_back(TokenType::Operator, utils::shift(src));
            }
            else if (src.front() == "<") {
                tokens.emplace_back(TokenType::Operator, utils::shift(src));
            }
            else if (src.front() == ">") {
                tokens.emplace_back(TokenType::Operator, utils::shift(src));
            }
            else if (src.front() == "=") {
                tokens.emplace_back(TokenType::Operator, utils::shift(src));
            }
            else if (isalpha(src.front()[0])){// get first character of string from vector. 
                std::string word = utils::shift(src);
                if (word[0] == 'd' && word[1] == 'o'){  
                    try {
                        if(word.at(2) == ':'){
                            try {
                                if (word.at(3) == ' '){
                                    tokens.emplace_back(TokenType::Operator, utils::shift(src));
                                }
                            } 
                            catch (const std::out_of_range& e ) {
                                std::cout << "expression is longer then 4 characters. It's not a do: expression\n";
                            }
                        }
                        else {
                            errors.push_back({"Expected '}'", )  //! Todo: write the correct error, after i finnish the line and column tracking. 
                        }
                    }
                    catch (const std::out_of_range& e){
                        std::cout << "Index out of range\n";
                    }  
                    
                }
                else if(word == "iwhile"){
                    tokens.emplace_back(TokenType::Keyword, utils::shift(src));
                }
                else if(word == "iFor"){
                    tokens.emplace_back(TokenType::Keyword, utils::shift(src));
                }
                else if(word == "exit"){
                    tokens.emplace_back(TokenType::Keyword, utils::shift(src)); 
                }
                else if(word == "end"){
                    tokens.emplace_back(TokenType::Keyword, utils::shift(src));
                }
            }
            else if (src.front() == "\t") {
                tokens.emplace_back(TokenType::Indent, utils::shift(src));
            }
            else if (utils::isSkippable(src.front()[0])){
                utils::shift(src);
            }

            

        }
        return tokens;     
    }
};