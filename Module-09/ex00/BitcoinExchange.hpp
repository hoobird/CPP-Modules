#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <sstream>

class BitcoinExchange {
    public:
        BitcoinExchange(const std::string databasefile);
        ~BitcoinExchange();

        // exception class for invalid database that allows for custom error messages
        class InvalidDatabaseException : public std::exception {
            public:
                InvalidDatabaseException() : msg("Invalid database format") {}
                InvalidDatabaseException(const std::string &message) : msg(message) {}
                virtual const char* what() const throw() {
                    return msg.c_str();
                }
            private:
                std::string msg;
        };
    
    private:
        std::map<std::string, float> rates;
        
        void parseDatabase(const std::string &file);

        bool isValidDate(const std::string &date) const; // Year-Month-Date
        bool isValidValue(const std::string &Value) const; // float/int (0 to 1000)
        double getExchangeRate(const std::string& date) const;
        void trimWhitespace(std::string &input) const;
        
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
};

#endif
