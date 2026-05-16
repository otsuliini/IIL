#pragma once
#include <iostream>
#include <unordered_set>

enum TokenType {
  Number,
  Identifier,
  Keyword,
  OpenParen,
  CloseParen,
  Operator,
  Delimiter,
  Indent,
  FileEnd,
  BangEqual,
  EqualEqual,
};

struct Token {
  std::optional<TokenType> type;
  std::optional<std::string> value;

  std::optional<unsigned int> line;
  std::optional<unsigned int> column;
  Token() : line(0), column(0) {}
  Token(TokenType type, std::string value, int line, int column)
      : value(value), type(type), line(line), column(column) {}
};

inline const std::unordered_set<std::string> operators = {"+", "-", "*", "/",
                                                          "%", "<", ">", "="};

inline const std::unordered_set<std::string> delimiters = {";", ",",
                                                           "\""
                                                           ":"};

inline const std::unordered_set<std::string> keywords = {
    "ivar",     "global", "NULL",    "if",   "else",   "eif",  "do",
    "iwhile",   "iend",   "iexit",   "ifor", "ibreak", "itry", "iexcept",
    "ifinally", "ifunc",  "ireturn", "True", "False"};
