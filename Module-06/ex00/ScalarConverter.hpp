#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <cerrno>


class ScalarConverter 
{
    public:
        static void convert(std::string const &literal);
                
        enum types {
            CHAR,
            INT,
            FLOAT,
            DOUBLE,
            IMPOSSIBLE
        };

    private:
        // OCF but privated so cannot be instantiated
        ScalarConverter();
        ScalarConverter(ScalarConverter const &other);
        ScalarConverter& operator=(ScalarConverter const &other);
        ~ScalarConverter();



};

// write a function prototype to get the type of the literal
ScalarConverter::types getType(std::string const &literal);
bool isInt(const std::string& str);
bool isFloat(const std::string& str);
bool isDouble(const std::string& str);

#endif