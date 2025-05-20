#include <iostream>
#include <string>
#include <cstring>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <string>" << std::endl;
        return 1;
    }
    std::string input = argv[1];
    std::cout << "Length (std::string): " << input.length() << std::endl;
    std::cout << "Length (char*): " << std::strlen(argv[1]) << std::endl;
    return 0;
}