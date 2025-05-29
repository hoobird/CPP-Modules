#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &other) 
{
    (void) other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) 
{
    (void) other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

// Above is useless, just there to fulfill OCF
// +inff: +ve infinity (float)
// -inff: -ve infinity (float)
// nanf: not a number (float)
// +inf: +ve infinity (double)
// -inf: -ve infinity (double)
// nan: not a number (double)

void ScalarConverter::convert(std::string const &literal)
{
    // get literal in largest type (double)
    double d = std::atof(literal.c_str());

    // check char
    std::cout << "char: ";
    if (d == 0)
        std::cout << "impossible" << std::endl;
    else if (std::isprint(static_cast<char>(d)) == false)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

    // check int
    std::cout << "int: ";
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || std::isnan(d))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;

    // check float
    std::cout << "float: ";
    if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
        std::cout << "impossible" << std::endl;
    else if (d == std::numeric_limits<float>::infinity())
        std::cout << "+inff" << std::endl;
    else if (d == -std::numeric_limits<float>::infinity())
        std::cout << "-inff" << std::endl;
    else if (std::isnan(d))
        std::cout << "nanf" << std::endl;
    else
        std::cout << static_cast<float>(d) << "f" << std::endl;

    // check double
    std::cout << "double: ";
    if (d == std::numeric_limits<double>::infinity())
        std::cout << "+inf" << std::endl;
    else if (d == -std::numeric_limits<double>::infinity())
        std::cout << "-inf" << std::endl;
    else if (std::isnan(d))
        std::cout << "nan" << std::endl;
    else
        std::cout << d << std::endl;

}

