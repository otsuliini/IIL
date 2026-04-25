#pragma once
#include <iostream>
#include <vector>

struct ASTNode
{
    ASTNode *parent;
    std::vector<ASTNode *> children;
    std::string value;
};
