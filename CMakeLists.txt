cmake_minimum_required(VERSION 3.25)

project(IIL
    VERSION 1.0
    DESCRIPTION "Interesting Interpreted Language"
    LANGUAGES CXX
)

if(MINGW)
    set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES OFF)
    set(CMAKE_C_USE_RESPONSE_FILE_FOR_INCLUDES OFF)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

# -----------------------------------
# MAIN: 
# -----------------------------------

file(GLOB_RECURSE IIL_SRC CONFIGURE_DEPENDS
    src/*.cpp
)

add_executable(IIL 
    ${IIL_SRC}
)

target_include_directories(IIL PRIVATE
    ${CMAKE_SOURCE_DIR}/include/IIL
    ${CMAKE_SOURCE_DIR}/src
)
# -------------------------------------
# REPL: 
# -------------------------------------

file(GLOB_RECURSE IIL_REPL_SRC CONFIGURE_DEPENDS
    stdlib/repl/*.cpp
)

file(GLOB ASCII_SRC CONFIGURE_DEPENDS
    external/ascii-art/*.cpp
)

add_library(ascii_art 
    ${ASCII_SRC}
)

target_include_directories(ascii_art PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/external/ascii-art
)

add_executable(IIL_REPL 
    ${IIL_REPL_SRC}
)

target_include_directories(IIL_REPL PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/stdlib/repl/src
)

target_link_libraries(IIL_REPL PRIVATE ascii_art)

target_link_libraries(IIL_REPL PRIVATE ascii_art) 
# ------------------------------------
# TESTING: 
# ------------------------------------

enable_testing()

add_executable(IIL_tests
    tests/lexer_test.cpp
    src/parser/utils/helperRoutines.cpp
)
target_link_libraries(IIL_tests gtest_main)
target_include_directories(IIL_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/include/IIL
    ${CMAKE_SOURCE_DIR}/src
)
add_test(NAME lexer_test COMMAND IIL_tests)