#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter 
{
    public:
        static void convert(const std::string& literal);

    private:
        ScalarConverter();  // Private constructor to prevent instantiation
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);

        static bool isChar(const std::string& literal);
        static bool isInt(const std::string& literal);
        static bool isFloat(const std::string& literal);
        static bool isDouble(const std::string& literal);
};

#endif