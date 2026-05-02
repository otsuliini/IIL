cmake_minimum_required(VERSION 4.2.3)

project(IIL
    VERSION 1.0
    DESCRIPTION "Interesting Interpreted Language"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(IIL
    src/main.cpp
    src/lexer/tokenization.cpp
    src/lexer/utils/isDelimiter.cpp
    src/lexer/utils/isNumber.cpp
    src/lexer/utils/isSkippable.cpp
    src/lexer/utils/shift.cpp
    src/parser/errors/errorRoutines.cpp
    src/parser/errors/parserError.cpp
    src/parser/utils/helperRoutines.cpp
    src/parser/AST.cpp
)

target_include_directories(IIL PRIVATE
    ${CMAKE_SOURCE_DIR}/include/IIL
    ${CMAKE_SOURCE_DIR}/src/lexer/utils/include
    ${CMAKE_SOURCE_DIR}/src/parser/errors/include
    ${CMAKE_SOURCE_DIR}/src/parser/utils/include
)

# Tests
enable_testing()

add_executable(IIL_tests
    tests/lexer_test.cpp
)
target_link_libraries(IIL_tests gtest_main)
target_include_directories(IIL_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/include/IIL
    ${CMAKE_SOURCE_DIR}/src/lexer/utils/include
    ${CMAKE_SOURCE_DIR}/src/parser/errors/include
    ${CMAKE_SOURCE_DIR}/src/parser/utils/include
)
add_test(NAME lexer_test COMMAND IIL_tests)