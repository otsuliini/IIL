#include "ASTNode.hpp"
#include "helperRoutines.hpp"
#include "parserError.hpp"
#include "parsing.hpp"
#include <exception>
#include "tokens.hpp"
#include <iostream>
#include <algorithm>

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

bool parserUtils::isRightAssociative(Token op)
{
    std::string *find_ops = std::find(std::begin(right_associative_ops), std::end(right_associative_ops), op);
    if (find_ops != std::end(right_associative_ops))
    {
        return true;
    }
    return false;
}

void parserUtils::buffer_Op(Token op){
    parserUtils::opBuffer.emplace_back(op); 
    return; 
}

void parserUtils::clearBuffer(){
    opBuffer.clear(); 
    return; 
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

void parserUtils::rem_buffered_op(Token op) {
    std::vector<Token>::iterator iter = std::find(opBuffer.begin(), opBuffer.end(), op); 
    opBuffer.erase(iter); 
    return; 
}

std::unique_ptr<ASTnode> parserUtils::to_node_op(OpTok token) {
    std::unique_ptr<ASTnode> node;
    node->NodeValue = token;
    node->leftChild = token.leftChild; 
    node->rightChild = token.rightChild;
    return node; 
}

std::unique_ptr<ASTnode> parserUtils::to_node_ptr_token(std::unique_ptr<Token> token) {
    std::unique_ptr<ASTnode> node; 
    
    return node; 
}