#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <csv_file>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << argv[1] << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string value;
        int columnCount = 0;

        while (std::getline(ss, value, ',')) {
            std::cout << "Value " << ++columnCount << ": " << value << std::endl;
        }

        if (columnCount != 3) {
            std::cerr << "Error: Expected 3 values per line, but got " << columnCount << std::endl;
        }
    }

    file.close();
    return 0;
}