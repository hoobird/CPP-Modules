#include <iostream>
#include <fstream>

int main() {
    std::ofstream outfile("example.txt");
    if (!outfile) {
        std::cerr << "Failed to open file for writing. Check if you have write permissions." << std::endl;
        return 1;
    }

    outfile << "Writing to the file." << std::endl;

    outfile.close();
    return 0;
}
