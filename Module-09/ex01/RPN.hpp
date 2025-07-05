#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <Stack>

class RPN {
    public:
        RPN();
        ~RPN();
        void evaluate(const std::string &expression);
        
    private:
        std::vector<double> stack;  
        void performOperation(const std::string &operation);
        bool isOperator(const std::string &token);
        void handleError(const std::string &message);
};


#endif