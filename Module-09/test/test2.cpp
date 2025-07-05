#include <sstream>
#include <ctime>
#include <iostream>
#include <cstdio>


time_t stringToEpoch(const std::string &date) 
{
   
}

std::string epochToString(time_t epoch) 
{
    struct tm *tm_info = localtime(&epoch);
    char buffer[11]; // YYYY-MM-DD
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", tm_info);
    return std::string(buffer);
}


int main() {
    std::string date = "2023-10-01";
    time_t epoch = stringToEpoch(date);
    if (epoch != -1) {
        std::cout << "Epoch time for " << date << " is: " << epoch << std::endl;
        std::cout << "Converted back to string: " << epochToString(epoch) << std::endl;
    } else {
        std::cerr << "Invalid date format." << std::endl;
    }
    return 0;
}
// This code converts a date string in the format YYYY-MM-DD to epoch time and back,