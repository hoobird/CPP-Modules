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
    char *c = toPrintableChar(literal);
    if (c) {
        std::cout << "char: '" << *c << "'" << std::endl;
        delete c;
    }
    else
        std::cout << "char: Not displayable" << std::endl;

    int *i = toInt(literal);
    if (i) {
        std::cout << "int: " << *i << std::endl;
        delete i;
    }
    else
        std::cout << "int: impossible" << std::endl;
    
}

// privated helpers

char *ScalarConverter::toPrintableChar(std::string const &literal)
{
    if (literal.length() == 1 && std::isprint(literal[0]))
        return new char(literal[0]);
    return NULL;
}

int *ScalarConverter::toInt(std::string const &literal)
{
    if (literal.empty() && )
}

float *ScalarConverter::toFloat(std::string const &literal)
{
    return NULL;
}

double *ScalarConverter::toDouble(std::string const &literal)
{
    return NULL;
}
