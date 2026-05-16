#include <iostream>

class parserException : public std::exception {

  std::string errorMsg;

public:
  parserException(const char *errorMsg) : errorMsg(errorMsg) {}

  const char *what() const noexcept { return errorMsg.c_str(); }
};
