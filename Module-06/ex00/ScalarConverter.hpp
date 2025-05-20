#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

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

        // returns NULL if cannot convert, meaning i have to memory manage also
        static char *toPrintableChar(std::string const &literal);
        static int *toInt(std::string const &literal);
        static float *toFloat(std::string const &literal);
        static double *toDouble(std::string const &literal);
};

#endif