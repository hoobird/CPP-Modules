#include <iostream>
#include <string>

int main() {
    std::string s = "Hello, World!";
    
    size_t i = s.find("Worsld");
    std::cout << "index: " << i << std::endl;
    if (i == std::string::npos)
        std::cout << "not found" << std::endl;
    else
        std::cout << "found" << std::endl;
    return (0);
}