#include <iostream>
#include <string>
#include <cstdlib>   // for strtof, strtod
#include <iomanip>   // for setprecision
#include <limits>
#include <cmath>     // for isnan, isinf

void testLiteral(const std::string& input) {
    char* endPtr = nullptr;

    // Try converting to float
    float fVal = std::strtof(input.c_str(), &endPtr);

    std::cout << "Input: " << input << "\n";
    std::cout << std::fixed << std::setprecision(6);

    if (std::string(endPtr) == "f" || input.back() == 'f') {
        // Interpreted as float
        std::cout << "Interpreted as float:\n";
        std::cout << "  Value: " << fVal << "\n";
        std::cout << "  isinf: " << std::boolalpha << std::isinf(fVal) << "\n";
        std::cout << "  isnan: " << std::boolalpha << std::isnan(fVal) << "\n";
    } else {
        // Interpreted as double
        double dVal = std::strtod(input.c_str(), nullptr);
        std::cout << "Interpreted as double:\n";
        std::cout << "  Value: " << dVal << "\n";
        std::cout << "  isinf: " << std::boolalpha << std::isinf(dVal) << "\n";
        std::cout << "  isnan: " << std::boolalpha << std::isnan(dVal) << "\n";
    }

    std::cout << "-----------------------\n";
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Usage: ./test_literal <literal>\n";
        return 1;
    }

    std::string input = argv[1];
    testLiteral(input);

    return 0;
}
