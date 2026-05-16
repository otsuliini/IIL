#include "lexer/utils/isSkippable.hpp"

bool utils::isSkippable(char token) {
  if (token == ' ') { // checks for spaces.
    return true;
  }
  return false;
}
