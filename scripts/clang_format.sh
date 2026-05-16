find . -type f \( -name "*.cpp" -o -name "*.hpp" -o -name "*.h" \) \
-not -path "./external/*" \
-exec clang-format -i {} +