#include <cassert>
#include <iostream>
#include "../include/ILL/lexer/tokenization.hpp"

void test_var_declaration() {
    tokenizing lexer;
    std::string source = "ivar x = 5";
    auto tokens = lexer.tokenize(source);
    
    assert(tokens[0].type == TokenType::Keyword && tokens[0].value == "ivar");
    assert(tokens[1].type == TokenType::Identifier && tokens[1].value == "x");
    assert(tokens[2].type == TokenType::Operator && tokens[2].value == "=");
    assert(tokens[3].type == TokenType::Number && tokens[3].value == "5");
    std::cout << "test_var_declaration passed\n";
}

void test_single_line_comment() {
    tokenizing lexer;
    std::string source = "ivar x = 5 ## this is a comment";
    auto tokens = lexer.tokenize(source);
    
    assert(tokens.size() == 4); // comment should be ignored
    std::cout << "test_single_line_comment passed\n";
}

int main() {
    test_var_declaration();
    test_single_line_comment();
    
    std::cout << "all tests passed\n";
}