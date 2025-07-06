#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: Not enough params. Need exactly 1 string of expression\nUsage: " << argv[0] << " <expression>" << std::endl;
        return 1;
    }

    try {
        RPN::evaluate(argv[1]);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}