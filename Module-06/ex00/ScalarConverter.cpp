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
    char c;
    int i;
    float f;
    double d;

    types type = getType(literal);
    std::cout << "Detected Type: ";
    if (type == CHAR)
        std::cout << "char" << std::endl;
    else if (type == INT)
        std::cout << "int" << std::endl;
    else if (type == FLOAT)
        std::cout << "float" << std::endl;
    else if (type == DOUBLE)
        std::cout << "double" << std::endl;
    else
        std::cout << "impossible" << std::endl;

    if (type == CHAR)
    {
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
        if (std::isprint(static_cast<unsigned char>(c))) {
            std::cout << "char: '" << c << "'" << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    }
    else if (type == INT)
    {
        i = std::atoi(literal.c_str());
        f = static_cast<float>(i);
        d = static_cast<double>(i);
        if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max()) {
            std::cout << "char: Impossible" << std::endl;
        } else {
            c = static_cast<char>(i);
            if (!std::isprint(static_cast<unsigned char>(c))) {
                std::cout << "char: Non displayable" << std::endl;
            } else {
                std::cout << "char: '" << c << "'" << std::endl;
            }
        }
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    }
    else if (type == FLOAT)
    {
        d = std::atof(literal.c_str());
        f = static_cast<float>(d);
        d = static_cast<double>(f);
        if (literal == "nanf") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
            return;
        }
        //handle smaller char and int first
        if (literal == "+inff" || literal == "-inff" || literal == "inff") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
        } else {
            if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max()) {
                std::cout << "char: Impossible" << std::endl;
            } else {
                c = static_cast<char>(f);
                if (!std::isprint(static_cast<unsigned char>(f))) {
                    std::cout << "char: Non displayable" << std::endl;
                } else {
                    std::cout << "char: '" << c << "'" << std::endl;
                }
            }
            if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max()) {
                std::cout << "int: Impossible" << std::endl;
            } else {
                i = static_cast<int>(f);
                std::cout << "int: " << i << std::endl;
            }
        }
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    }
    else if (type == DOUBLE)
    {
        d = std::atof(literal.c_str());
        if (literal == "nan") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
            return;
        }
        //handle smaller char and int and float
        if (literal == "+inf" || literal == "-inf" || literal == "inf") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
        } else {
            if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max()) {
                std::cout << "char: Impossible" << std::endl;
            } else {
                c = static_cast<char>(d);
                if (!std::isprint(static_cast<unsigned char>(c))) {
                    std::cout << "char: Non displayable" << std::endl;
                } else {
                    std::cout << "char: '" << c << "'" << std::endl;
                }
            }
            if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
                std::cout << "int: Impossible" << std::endl;
            } else {
                i = static_cast<int>(d);
                std::cout << "int: " << i << std::endl;
            }
        }
        if (std::isinf(d)) {
            std::cout << "float: " << (d > 0 ? "inff" : "-inff") << std::endl;
        }
        else if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max()) {
            std::cout << "float: Impossible" << std::endl;
        } else {
            f = static_cast<float>(d);
            std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        }
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    }
    else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
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
    
    if (val < -std::numeric_limits<float>::max() || val > std::numeric_limits<float>::max())
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

    if (val < -std::numeric_limits<double>::max() || val > std::numeric_limits<double>::max())
        return false;
    return true;
}