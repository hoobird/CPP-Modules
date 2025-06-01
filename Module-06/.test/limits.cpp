#include <iostream>
#include <limits>
#include <iomanip>
#include <string>

int main() {
    // Set output formatting
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    
    // Create a table with aligned columns
    const int nameWidth = 15;
    const int valueWidth = 30;
    
    std::cout << std::setw(nameWidth) << std::left << "Type"
              << std::setw(valueWidth) << std::left << "Minimum Value"
              << "Maximum Value" << std::endl;
    
    std::string separator(nameWidth + valueWidth * 2, '-');
    std::cout << separator << std::endl;
    
    // Character type
    std::cout << std::setw(nameWidth) << std::left << "char"
              << std::setw(valueWidth) << std::left << static_cast<int>(std::numeric_limits<char>::min())
              << static_cast<int>(std::numeric_limits<char>::max()) << std::endl;
    
    // Integer type
    std::cout << std::setw(nameWidth) << std::left << "int"
              << std::setw(valueWidth) << std::left << std::numeric_limits<int>::min()
              << std::numeric_limits<int>::max() << std::endl;
    
    // Floating point types
    std::cout << std::setw(nameWidth) << std::left << "float"
              << std::setw(valueWidth) << std::left << std::numeric_limits<float>::min()
              << std::numeric_limits<float>::max() << std::endl;
    
    std::cout << std::setprecision(1);
    std::cout << std::setw(nameWidth) << std::left << "float (neg)"
              << std::setw(valueWidth) << std::left << -std::numeric_limits<float>::max()
              << std::endl;
    
    std::cout << std::setw(nameWidth) << std::left << "double"
              << std::setw(valueWidth) << std::left << std::numeric_limits<double>::min()
              << std::numeric_limits<double>::max() << std::endl;
    
    std::cout << std::setw(nameWidth) << std::left << "double (neg)"
              << std::setw(valueWidth) << std::left << -std::numeric_limits<double>::max()
              << std::endl;
    
    return 0;
}