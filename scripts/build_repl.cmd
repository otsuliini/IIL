echo "building REPL"

:: -S . means the source directory is the current folder
:: -B  means put the generated build files the build/ folder

cmake -S .. -B build 
cmake --build build --target IIL_REPL