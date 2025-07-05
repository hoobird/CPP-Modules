#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime> // For tm, time_t, strptime, mktime
#include <cstdio>
#include <cstring>
#include <cstdlib>


class BitcoinExchange {
    public:
        BitcoinExchange(const std::string databasefile);
        ~BitcoinExchange();
        void evaluateFile(const std::string &file) const;

        // get exchange rate for given file


        // exception class for invalid database that allows for custom error messages
        class InvalidDatabaseException : public std::exception {
            public:
                InvalidDatabaseException() : msg("Invalid database format") {}
                InvalidDatabaseException(const std::string &message) : msg(message) {}
                virtual ~InvalidDatabaseException() throw() {} 
                virtual const char* what() const throw() { return msg.c_str(); }
            private:
                std::string msg;
            };
    
    private:
        // Error codes and messages
        typedef enum {
            OK = 0,
            ERR_FILE_OPEN_FAIL,
            ERR_DATABASE_NO_HEADER,
            ERR_HEADER_READ_FAIL,
            ERR_DATABASE_INVALID_HEADER,
            ERR_DATABASE_LINE_READ_FAIL,
            ERR_DATABASE_INVALID_DATE_FORMAT,
            ERR_DATABASE_INVALID_DATE,
            ERR_DATABASE_INVALID_EXCHANGE_RATE,
            ERR_DATABASE_NO_VALID_ENTRIES,
            ERR_INPUT_FILE_LINE_READ_FAIL,
            ERR_INPUT_FILE_INVALID_LINE_FORMAT,
            ERR_INPUT_FILE_LINE_VALUE_INVALID,
            ERR_INPUT_FILE_LINE_VALUE_TOO_LARGE,
            ERR_INPUT_FILE_DATE_NOT_FOUND,
            ERR_INPUT_FILE_INVALID_HEADER
        } errCode ;

        
        std::map<time_t, double> rates;
        static std::map<errCode, std::string> errMsg;
        
        void parseDatabase(const std::string &file);
        void populateErrMsg();

        errCode isValidDate(const std::string &date) const;
        time_t stringToEpoch(const std::string &date) const;
        std::string epochToString(time_t epoch) const;
        errCode isValidExchangeRate(const std::string &Value) const;
        errCode isValidValue(const std::string &value) const;
        void trimWhitespace(std::string &input) const;
        double getExchangeRate(const std::string& date) const;
        
        // Restricted OCF
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);

};


#endif
