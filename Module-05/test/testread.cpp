#include <iostream>
#include <fstream>

// This helps detect:

// Missing file (for reading).

// No permission to access the file.

// Invalid path or hardware issue.



int main() {
    std::ifstream infile("example.txt");
    if (!infile) {
        std::cerr << "Failed to open file for reading. Check if the file exists and you have read permissions." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::cout << line << std::endl;
    }

    infile.close();
    return 0;
}
