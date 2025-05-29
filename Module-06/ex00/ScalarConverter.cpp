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
    char *c = NULL;
    int *i = NULL;
    float *f = NULL;
    double *d = NULL;

    types type = getType(literal);


    if (type == CHAR)
    {
        c = literal[0];
        i 
    }
    else if (type == INT)
    {
        i = std::atoi(literal.c_str());
    }
    else if (type == FLOAT || type == DOUBLE)
    {
        f = std::atof(literal.c_str());
    }
    else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // get literal in largest type (double)
    // double d = std::atof(literal.c_str());

    // check char
    // std::cout << "char: ";
    // if (type == CHAR)
    // {
    //     if (std::isprint(static_cast<unsigned char>(d))) {
    //         std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    //     }
    //     else {
    //         std::cout << "Non displayable" << std::endl;
    //     }
    // } else if (type == INT && literal.length() == 1 && std::isdigit(literal[0])) {
    //     std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    // }
    // else {
    //     std::cout << "impossible" << std::endl;
    // }
    
    // // check int
    // std::cout << "int: ";
    // if (type == IMPOSSIBLE)
    //     std::cout << "impossible" << std::endl;
    
    // // check float
    // std::cout << "float: ";
    // if (type == IMPOSSIBLE)
    //     std::cout << "impossible" << std::endl;
    
    // // check double
    // std::cout << "double: ";
    // if (type == IMPOSSIBLE)
    //     std::cout << "impossible" << std::endl;
}

ScalarConverter::types getType(std::string const &literal)
{
    if (literal.length() == 1 && !std::isdigit(literal[0]))
        return ScalarConverter::CHAR;
    if (isInt(literal))
        return ScalarConverter::INT;
    if (isFloat(literal))
        return ScalarConverter::FLOAT;
    if (isDouble(literal))
        return ScalarConverter::DOUBLE;
    return ScalarConverter::IMPOSSIBLE;
}

bool isInt(const std::string& str) {
    char* endptr = 0;
    errno = 0;
    long val = std::strtol(str.c_str(), &endptr, 10);

    if (endptr == str.c_str() || *endptr != '\0' || errno == ERANGE)
        return false;

    if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
        return false;

    return true;
}

bool isFloat(const std::string& str) {
    char* endptr = 0;
    errno = 0;
    float val = std::strtof(str.c_str(), &endptr);

    if (str == "inff" || str == "-inff" || str == "+inff")
        return true;

    if (endptr == str.c_str() || *endptr != 'f' || *(endptr + 1) != '\0' || errno == ERANGE)
        return false;
    
    if (val < std::numeric_limits<float>::min() || val > std::numeric_limits<float>::max())
        return false;

    return true;
}

bool isDouble(const std::string& str) {
    char* endptr = 0;
    errno = 0;
    double val = std::strtod(str.c_str(), &endptr);

    if (str == "inf" || str == "-inf" || str == "+inf")
        return true;

    if (endptr == str.c_str() || *endptr != '\0' || errno == ERANGE)
        return false;

    if (val < std::numeric_limits<double>::min() || val > std::numeric_limits<double>::max())
        return false;
    return true;
}