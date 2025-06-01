#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " \"<your string here>\"" << std::endl;
        return 1;
    }

    std::string input = argv[1];
    std::stringstream ss(input);

    std::string token;
    while (ss >> token) {
        std::cout << "Extracted: '" << token << "'";

        std::streampos pos = ss.tellg();
        if (pos != -1) {
            std::string remaining = ss.str().substr(static_cast<size_t>(pos));
            std::cout << " | Remaining: \"" << remaining << "\"";
        } else {
            std::cout << " | Remaining: \"\"";
        }

        std::cout << std::endl;
    }

    return 0;
}
