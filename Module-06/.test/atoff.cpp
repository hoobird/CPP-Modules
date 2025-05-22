#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <number1> [number2] ...\n";
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        double value = std::atof(argv[i]);
        std::cout << "Argument " << i << ": " << argv[i] << " -> " << value << std::endl;
        if (value > 0) {
            std::cout << "yay" << std::endl;
        }
    }


    return 0;
}