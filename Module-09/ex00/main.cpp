#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: need to provide 1 param for file input" << std::endl;
        return 1;
    }
    // Database file, can change if tester have different file
    const std::string databasefile = "./data.csv";
    try {
        BitcoinExchange exchange(databasefile);
        std::cout << "\n" << std::endl;
        exchange.evaluateFile(argv[1]);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}