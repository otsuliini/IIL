#include "lexer/tokens.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <utility>


class ExprAST
{ // Expression node bass class
public:
    virtual ~ExprAST() = default; // a virtual destructor with a compiler generated destructor body. Written because we specifically wan't to make the destructor virtual.
};

// VariableExprAST Expression cast for referencing a variable, such as "x"
class VariableExprAST : public ExprAST
{
    std::string Name;

public:
    VariableExprAST(const std::string &Name) : Name(Name) {} // Take Name as a reference so that we don't have two strings in memory that are full copies of each other taking up memory.
};

// NumberExprAST is an expression class for numbers.
class NumberExprAST : public ExprAST
{ // defines NumberExprAST as a subclass of ExprAST

public:
    NumberExprAST() {}
};

// BinaryExprAST expression class for a binary operator
class BinaryExprAST : public ExprAST
{
    char Operator;
    std::unique_ptr<ExprAST> LHS, RHS;

public:
    BinaryExprAST(char Operator, std::unique_ptr<ExprAST> LHS, std::unique_ptr<ExprAST> RHS)
        : Operator(Operator), LHS(std::move(LHS)), RHS(std::move(RHS)) {}
};

// CallExprAST expression class for function calls.
class CallExprAST : public ExprAST
{
    std::string Callee;
    std::vector<std::unique_ptr<ExprAST>> Args;

public:
    CallExprAST(const std::string &Callee, std::vector<std::unique_ptr<ExprAST>> Args)
        : Callee(Callee), Args(std::move(Args)) {}
};

// PrototypeAST - This class represents the prototype for a function,
// which captures its name, and its arguemnt names. Aswell as the number of arguments the function takes.
class PrototypeAST
{
    std::string Name;
    std::vector<std::string> Args;

public:
    PrototypeAST(const std::string &Name, std::vector<std::string> Args)
        : Name(Name), Args(std::move(Args)) {}

    const std::string &getName() const; // Getter to get the name of the function
};

// FunctionAST This class represents a function definition itself.
class FunctionAST
{
    std::unique_ptr<PrototypeAST> Proto;
    std::unique_ptr<ExprAST> Body;

public:
    FunctionAST(std::unique_ptr<PrototypeAST> Proto, std::unique_ptr<ExprAST> Body)
        : Proto(std::move(Proto)), Body(std::move(Body)) {}
};
