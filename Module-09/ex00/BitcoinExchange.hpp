#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
    public:
        BitcoinExchange(const std::string databasefile);
        ~BitcoinExchange();
    
    private:
        std::map<std::string, double> rates;
    
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        bool isValidDate(const std::string &date) const; // Year-Month-Date
        bool isValidValue(const std::string &Value) const; // float/int (0 to 1000)
        double getExchangeRate(const std::string& date) const;
        void trimWhitespace(std::string &input) const;


};

#endif
