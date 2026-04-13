cmake_minimum_required(VERSION 3.10)

project(IIL
    VERSION 1.0
    DESCRIPTION "Interesting Interpreted Language"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(IIL
    src/main.cpp
    src/lexer/tokenization.cpp
)

add_executable(lexer_test
    tests/lexer_test.cpp
    src/lexer/tokenization.cpp
)