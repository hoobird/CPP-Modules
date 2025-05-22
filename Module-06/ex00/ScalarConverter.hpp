#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>


class ScalarConverter 
{
    public:
        static void convert(std::string const &literal);

    private:
        // OCF but privated so cannot be instantiated
        ScalarConverter();
        ScalarConverter(ScalarConverter const &other);
        ScalarConverter& operator=(ScalarConverter const &other);
        ~ScalarConverter();

};

#endif