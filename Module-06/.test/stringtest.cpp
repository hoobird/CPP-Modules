#include <iostream>


int main() {
    std::string literal = "hello world";
    char *c = NULL;
    std::string *test;
    // *c = literal[0];
    *test = "test";


    std::cout << "Character: " << *c << std::endl;
    std::cout << "String: " << *test << std::endl;
    std::cout << "Literal: " << literal << std::endl;
}