#include "parser/ast/ASTNode.hpp"
#include "parser/utils/helperRoutines.hpp"
#include "parser/errors/parserError.hpp"
#include "parser/parsing.hpp"
#include "lexer/tokens.hpp"
#include <exception>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory>
Precedence parserUtils::getPrecedence(const OpTok token) {
    std::string value = token.value; 
    //! Add parentheses precedence

    if (value == "**"){
        return Precedence::LEVEL3; 
    }
    else if (value == "*"){
        return Precedence::LEVEL2; 
    }
    else if (value == "/"){
        return Precedence::LEVEL2; 
    }
    else if (value == "%"){
        return Precedence::LEVEL2; 
    }
    else if (value == "+"){
        return Precedence::LEVEL1; 
    }
    else if (value == "-"){
        return Precedence::LEVEL1; 
    }
    else if (value == "="){
        return Precedence::LEVEL0; 
    }
    else {
        //! Add error handling.
    }
}


bool parserUtils::isBinary(Token op) {
    
    auto iterator = std::find(operators.begin(), operators.end(), op.value); 
    if (iterator != operators.end()) {
        return true; 
    }
    else {
        return false; 
    }
}


void parserUtils::operatorBuffer::buffer_Op(Token op){
    parserUtils::operatorBuffer::opBuffer.emplace_back(op);
}

void parserUtils::operatorBuffer::clearBuffer(){
    opBuffer.clear();
}

Token parserUtils::getHighestPrecedence(std::vector<Token> tokenBuffer){
    Token compTok = tokenBuffer[0]; 

    for (int i = 1; i <= tokenBuffer.size(); i++) {
        Token curTok = tokenBuffer[i]; 
        if (comparePrecedence<Token>(compTok, curTok) == PrecedenceResult::Token2) {
            compTok = curTok;
        }
    }
    return compTok; 
}

void parserUtils::operatorBuffer::rem_buffered_op(Token op) {
    std::vector<Token>::iterator iter = std::find(opBuffer.begin(), opBuffer.end(), op); 
    opBuffer.erase(iter);
}

std::unique_ptr<ASTNode> parserUtils::to_node_op(OpTok token) {
    std::unique_ptr<ASTNode> node; 
    node->NodeValue->column = token.column;
    node->NodeValue->line = token.line;
    node->NodeValue->value = token.value;
    node->NodeValue->type = token.type; 
    node->leftChild = std::make_unique<ASTNode>(token.leftChild); 
    node->rightChild = std::make_unique<ASTNode>(token.rightChild); 
    return node; 
}