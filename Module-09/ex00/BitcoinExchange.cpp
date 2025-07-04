#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string databasefile)
{
    parseDatabase(databasefile); // updates rates map
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::parseDatabase(const std::string &databasefile)
{

    std::ifstream file(databasefile.c_str());
    if (!file)
        throw InvalidDatabaseException("Could not open database file: " + databasefile);
    std::string line;
    // get the first line (header) and ignore it
    if (!std::getline(file, line)) {
        throw InvalidDatabaseException("Database does not contain a header line");
    }
    // check if header is 'date', 'exchange_rate'
    std::stringstream linestream(line);
    std::string header1, header2;
    if (!(linestream >> header1) || !(linestream >> header2) || header1 != "date" || header2 != "exchange_rate") {
        throw InvalidDatabaseException("Invalid header format in database file");
    }
    while (std::getline(file, line)) {
        trimWhitespace(line);
        if (line.empty() || line[0] == '#') // skip empty lines and comments
            continue;
        
        std::istringstream iss(line);
        std::string date;
        std::string value;
        // Read date and value from the line comma-separated
        if (!std::getline(iss, date, ',') || !std::getline(iss, value)) {
            throw std::invalid_argument("Invalid line format in database file");
        }
        
    }
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{

}

bool BitcoinExchange::isValidValue(const std::string &s) const
{
    if (s.empty()) return false;

    std::istringstream iss(s);
    float f;
    char c;

    if (!(iss >> f))
        return false;

    if (iss >> c)
        return false;

    if (f < 0 || f > 1000)
        return false;

    return true;
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
