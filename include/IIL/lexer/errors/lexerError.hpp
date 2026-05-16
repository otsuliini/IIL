#pragma once
#include <iostream>

struct LexerError {
  std::string message;
  unsigned int line;
  unsigned int column;
};
