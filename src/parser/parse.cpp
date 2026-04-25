#include "parser/parse.hpp"
#include "lexer/tokens.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <utility>
#include "parse.hpp"

const std::string &PrototypeAST::getName() const { return Name; }// Getter to get the name of the function

