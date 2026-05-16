Get-ChildItem -Recurse -File -Include *.cpp,*.hpp,*.h |
Where-Object { $_.FullName -notlike "*\external\*" } |
ForEach-Object {
    clang-format -i $_.FullName
}