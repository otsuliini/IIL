#include "parser/parse.hpp"
#include "lexer/tokens.hpp"
#include <iostream>
#include <vector> 
#include <memory>
#include <utility> 

class ExprAST{ // Expression node bass class 
    public: 
    virtual ~ExprAST() = default; // a virtual destructor with a compiler generated destructor body. Written because we specifically wan't to make the destructor virtual. 


}; 

// VariableExprAST Expression cast for referencing a variable, such as "x"
class VariableExprAST : public ExprAST {
    std::string Name; 

    public: 
    VariableExprAST(const std::string &Name) : Name(Name) {} // Take Name as a reference so that we don't have two strings in memory that are full copies of each other taking up memory. 
}; 

// NumberExprAST is an expression class for numbers. 
class NumberExprAST : public ExprAST{ // defines NumberExprAST as a subclass of ExprAST
    double Val; 


    public: 
    NumberExprAST(double Val) : Val(Val) {} // constructor with initializer list. 
}; 

//BinaryExprAST expression class for a binary operator
class BinaryExprAST : public ExprAST{ 
    char Operator; 
    std::unique_ptr<ExprAST> LHS, RHS;

    public: 
    
    BinaryExprAST(char Operator, std::unique_ptr<ExprAST> LHS, std::unique_ptr<ExprAST> RHS)
        : Operator(Operator), LHS(std::move(LHS)), RHS(std::move(RHS))  {std::cout << "created binary expression";}
}; 

// CallExprAST expression class for function calls. 
class CallExprAST : public ExprAST {
    std::string Callee; 
    std::vector<std::unique_ptr<ExprAST>> Args; 
}; 