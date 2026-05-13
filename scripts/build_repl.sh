echo "building REPL"

# -S . means source directory
# -B build means build directory

cmake -S .. -B build
cmake --build build --target IIL_REPL