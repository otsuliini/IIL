cmake_minimum_required(VERSION 3.10)

project(IIL
    VERSION 1.0
    DESCRIPTION "Interesting Interpreted Language"
    LANGUAGES CXX
)

include_directories(include)

add_executable(IIL
    src/main.cpp
)
