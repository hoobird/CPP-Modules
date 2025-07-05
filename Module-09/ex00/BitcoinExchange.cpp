#include "BitcoinExchange.hpp"

std::map<BitcoinExchange::errCode, std::string> BitcoinExchange::errMsg;

BitcoinExchange::BitcoinExchange(const std::string databasefile)
{
    populateErrMsg();
    parseDatabase(databasefile); // updates rates map
}

BitcoinExchange::~BitcoinExchange()
{

}

void BitcoinExchange::populateErrMsg()
{
    errMsg.clear();
    errMsg[ERR_FILE_OPEN_FAIL] = "Error: Could not open file: ";
    errMsg[ERR_DATABASE_NO_HEADER] = "Error: Database does not contain a header line";
    errMsg[ERR_HEADER_READ_FAIL] = "Error: Problem reading header line in database file";
    errMsg[ERR_DATABASE_INVALID_HEADER] = "Error: Invalid header in database file: expected first 2 column 'date,exchange_rate'";
    errMsg[ERR_DATABASE_LINE_READ_FAIL] = "Error: Problem reading line in database file => ";
    errMsg[ERR_DATABASE_INVALID_DATE_FORMAT] = "Invalid date format: expected YYYY-MM-DD";
    errMsg[ERR_DATABASE_INVALID_DATE] = "Invalid date: date does not exist or is out of range";
    errMsg[ERR_DATABASE_INVALID_EXCHANGE_RATE] = "Invalid exchange rate format: expected a non-negative number";
    errMsg[ERR_DATABASE_NO_VALID_ENTRIES] = "Error: No valid entries found in the database file. ❌";
    errMsg[ERR_INPUT_FILE_LINE_READ_FAIL] = "Error: Problem reading line in input file: ";
    errMsg[ERR_INPUT_FILE_INVALID_LINE_FORMAT] = "Invalid line format, expected 'date | value'";
    errMsg[ERR_INPUT_FILE_LINE_VALUE_INVALID] = "not a positive number (between O to 1000)";
    errMsg[ERR_INPUT_FILE_LINE_VALUE_TOO_LARGE] = "too large a number (between O to 1000)";
    errMsg[ERR_INPUT_FILE_DATE_NOT_FOUND] = "Error: No exchange rate found for date: ";
    errMsg[ERR_INPUT_FILE_INVALID_HEADER] = "Error: Invalid header in input file: expected 'date | value'";
}


void BitcoinExchange::parseDatabase(const std::string &databasefile)
{
    std::cout << "⭐⭐ Parsing database file: " << databasefile  << " ⭐⭐"<< std::endl;
    std::ifstream file(databasefile.c_str());
    if (!file)
        throw InvalidDatabaseException(errMsg[ERR_FILE_OPEN_FAIL] + databasefile);
    std::string line;
    // get the first line (header) and ignore it
    if (!std::getline(file, line)) {
        throw InvalidDatabaseException(errMsg[ERR_DATABASE_NO_HEADER]);
    }
    // check if header is 'date', 'exchange_rate'
    std::stringstream linestream(line);
    std::string header1, header2;
    if (!std::getline(linestream, header1, ',') || !std::getline(linestream, header2, ',')) {
        throw InvalidDatabaseException(errMsg[ERR_HEADER_READ_FAIL]);
    }
    trimWhitespace(header1);
    trimWhitespace(header2);

    if (header1 != "date" || header2 != "exchange_rate")
        throw InvalidDatabaseException(errMsg[ERR_DATABASE_INVALID_HEADER]);
    
    // Read the rest of the file line by line
    unsigned int count = 0;
    while (std::getline(file, line)) {
        trimWhitespace(line);
        if (line.empty()) // skip empty lines
            continue;
        std::istringstream iss(line);
        std::string date;
        std::string value;
        // Read date and value from the line comma-separated
        if (!std::getline(iss, date, ',') || !std::getline(iss, value, ','))
        {
            std::cerr << errMsg[ERR_DATABASE_LINE_READ_FAIL] << line << std::endl;
            continue; // skip this line if read fails
        }
        trimWhitespace(date);
        trimWhitespace(value);
        errCode dateErr = isValidDate(date);
        errCode valueErr = isValidExchangeRate(value);
   
        if (dateErr != OK || valueErr != OK) {
            std::cerr << "Error: Line { " << line << " } is invalid: " << std::endl;
            if (dateErr != OK)
                std::cerr << "\t- " << errMsg[dateErr] << std::endl;
            if (valueErr != OK)
                std::cerr << "\t- " << errMsg[valueErr] << std::endl;
            continue; // move on to next line if date or value is invalid
        }
        // insert into rates map
        time_t epoch = stringToEpoch(date);
        char *endptr = NULL;
        double exchangeRate = std::strtod(value.c_str(), &endptr);
        rates[epoch] = exchangeRate; // store the exchange rate for the date
        count ++;
    }
    if (rates.empty()) {
        throw InvalidDatabaseException(errMsg[ERR_DATABASE_NO_VALID_ENTRIES]);
    }
    std::cout << "Parsed " << count << " valid entries from the database. ✅" << std::endl;
    std::cout << "⭐⭐ Database loaded successfully. ⭐⭐" << std::endl;

}

BitcoinExchange::errCode BitcoinExchange::isValidDate(const std::string &date) const
{
    // make sure the date is in the format YYYY-MM-DD
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return ERR_DATABASE_INVALID_DATE_FORMAT;
    for (size_t i = 0; i < date.length(); ++i) {
        if (i == 4 || i == 7) continue; // skip dashes
        if (!isdigit(date[i])) {
            return ERR_DATABASE_INVALID_DATE_FORMAT;
        }
    }
    // Check if the date is valid by converting to epoch and back
    time_t epoch = stringToEpoch(date);
    if (epoch == -1) {
        return ERR_DATABASE_INVALID_DATE;
    }
    std::string convertedDate = epochToString(epoch);
    if (convertedDate != date) {
        return ERR_DATABASE_INVALID_DATE;
    }
    return OK;
}

time_t BitcoinExchange::stringToEpoch(const std::string &date) const 
{
    int year, month, day;
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
        return -1;

    struct tm tm_info;
    memset(&tm_info, 0, sizeof(tm_info));
    tm_info.tm_year = year - 1900;
    tm_info.tm_mon = month - 1; 
    tm_info.tm_mday = day; 
    tm_info.tm_hour = 0; 
    tm_info.tm_min = 0; 
    tm_info.tm_sec = 0; 
    tm_info.tm_isdst = -1; // let mktime determine if DST is in effect
 
    return mktime(&tm_info); 
}

std::string BitcoinExchange::epochToString(time_t epoch) const
{
    struct tm *tm_info = localtime(&epoch);
    char buffer[11]; // YYYY-MM-DD
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", tm_info);
    return std::string(buffer);
}

BitcoinExchange::errCode BitcoinExchange::isValidExchangeRate(const std::string &s) const
{
    if (s.empty())
        return ERR_DATABASE_INVALID_EXCHANGE_RATE;

    char *endptr = NULL;
    errno = 0;
    double value = std::strtod(s.c_str(), &endptr);

    // Check for conversion errors or if nothing was converted
    if (errno != 0 || endptr == s.c_str() || *endptr != '\0')
        return ERR_DATABASE_INVALID_EXCHANGE_RATE;

    // Check range
    if (value < 0.0)
        return ERR_DATABASE_INVALID_EXCHANGE_RATE;

    return OK;
}

BitcoinExchange::errCode BitcoinExchange::isValidValue(const std::string &value) const
{
    if (value.empty())
        return ERR_DATABASE_INVALID_EXCHANGE_RATE;

    char *endptr = NULL;
    errno = 0;
    double val = std::strtod(value.c_str(), &endptr);

    // Check for conversion errors or if nothing was converted
    if (errno != 0 || endptr == value.c_str() || *endptr != '\0')
        return ERR_INPUT_FILE_LINE_VALUE_INVALID;

    // Check range
    if (val <= 0.0)
        return ERR_INPUT_FILE_LINE_VALUE_INVALID;
    if (val >= 1000.0)
        return ERR_INPUT_FILE_LINE_VALUE_TOO_LARGE;

    return OK;
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

void BitcoinExchange::evaluateFile(const std::string &file) const
{
    std::ifstream inputFile(file.c_str());
    if (!inputFile)
        throw InvalidDatabaseException(errMsg[ERR_FILE_OPEN_FAIL] + file);

    std::string line;
    if (!std::getline(inputFile, line)) {
        throw InvalidDatabaseException(errMsg[ERR_HEADER_READ_FAIL]);
    }
    trimWhitespace(line);
    std::istringstream headerStream(line);
    std::string header1, header2;
    if (!std::getline(headerStream, header1, '|') || !std::getline(headerStream, header2, '|')) {
        throw InvalidDatabaseException(errMsg[ERR_INPUT_FILE_INVALID_HEADER]);
    }
    trimWhitespace(header1);
    trimWhitespace(header2);
    if (header1 != "date" || header2 != "value") {
        throw InvalidDatabaseException(errMsg[ERR_INPUT_FILE_INVALID_HEADER]);
    }
    while (std::getline(inputFile, line)) {
        trimWhitespace(line);
        if (line.empty())
            continue;
        std::istringstream iss(line);
        std::string date;
        std::string value;
        std::string leftover;
        if (!std::getline(iss, date, '|') || !std::getline(iss, value, '|')) {
            std::cerr << errMsg[ERR_INPUT_FILE_LINE_READ_FAIL] << line << std::endl;
            continue;
        }
        if (iss >> leftover) {
            std::cerr << errMsg[ERR_INPUT_FILE_INVALID_LINE_FORMAT] << line << std::endl;
            continue;
        }
        trimWhitespace(date);
        trimWhitespace(value);
        errCode dateErr = isValidDate(date);
        errCode valueErr = isValidValue(value);
        if (dateErr !=  OK ||  valueErr != OK) {
            std::cerr << "Error: Line { " << line << " } is invalid: " << std::endl;
            if (dateErr != OK) {
                std::cerr << "\t- " << errMsg[dateErr] << std::endl;
                continue;
            }
            if (valueErr != OK) {
                std::cerr << "\t- " << errMsg[valueErr] << std::endl;
                continue;
            }
        }

        // Get the exchange rate for the date
        time_t epoch = stringToEpoch(date);
        char *endptr = NULL;
        double valued = std::strtod(value.c_str(), &endptr);

        std::map<time_t, double>::const_iterator it = rates.lower_bound(epoch);
        if (it == rates.end()) {
            std::cerr << "Error: No exchange rate found for date: " << date << std::endl;
            continue;
        }
        if (it == rates.begin() && it->first > epoch) {
            std::cerr << errMsg[ERR_INPUT_FILE_DATE_NOT_FOUND] << date << std::endl;
            continue;
        }
        if (it->first != epoch) {
            --it; // get the last valid date before the requested date
        }
        double exchangeRate = it->second;
        double result = exchangeRate * valued;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }

}


double BitcoinExchange::getExchangeRate(const std::string &date) const
{
    (void) date;
    return 0.0;
}