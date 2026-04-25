#pragma once
#include <iostream>

class ExprAST
{
public:
    virtual ~ExprAST() = default;
};

class VariableExprAST : public ExprAST
{
    std::string Name;

public:
    VariableExprAST(const std::string &Name) : Name(Name) {}
};


