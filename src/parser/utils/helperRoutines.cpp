#include "helperRoutines.hpp"
#include "../include/IIL/lexer/tokens.hpp"
#include <iostream>
#include <vector> 


class helperRoutines {
    // CurtTok/getNextToken Provide a simple token buffer. Curtok is the current token the parser is looking at. 
    // getNextToken reads another token from the lexer and updates CurTok with its results. 
    Token CurTok; //CurTok = current Token. A token buffer. 

    public: 
    
    Token getNextToken(std::vector<Token> tokens) {
        return CurTok = tokens.front(); 
    }
}; 


