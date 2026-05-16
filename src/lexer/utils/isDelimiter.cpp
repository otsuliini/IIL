#include "lexer/utils/isDelimiter.hpp"
#include "lexer/tokens.hpp"

bool utils::isDelimiter(char ch) {
  return delimiters.count(
      std::string(1, ch)); // converts the input into a string and checks if
                           // input is delimiter using count()
}
