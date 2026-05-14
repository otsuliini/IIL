#include <iostream>
#include "Ascii.h"

int main() {
    ascii::Ascii font(ascii::starwar);
    font.print("IIL");
    std::cout << "Interesting Interpreted Programming Language" << std::endl; 

    while (true) {
        std::string input; 
        std::cout << "IIL>"; 
        std::cin >> input; 
    }
}