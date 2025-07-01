#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string databasefile)
{
    
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    return false;
}

bool BitcoinExchange::isValidValue(const std::string &Value) const
{
    return false;
}

double BitcoinExchange::getExchangeRate(const std::string &date) const
{
    return 0.0;
}

void BitcoinExchange::trimWhitespace(std::string &input) const
{
    size_t start = input.find_first_not_of(" \t");
    size_t end = input.find_last_not_of(" \t");
    if (start == std::string::npos)
        input = "";
    else
        input = input.substr(start, end - start + 1);
}
