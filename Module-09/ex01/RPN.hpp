#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stack>

class RPN {
    public:
        static void evaluate(const std::string &exp);

        class InvalidExpressionException : public std::exception {
            public:
                InvalidExpressionException(): reason("Error: Invalid expression") {}
                InvalidExpressionException(const std::string &reason) : reason("Error: " + reason) {}
                ~InvalidExpressionException() throw() {}
                virtual const char *what() const throw() {
                    return reason.c_str();
                }
            private:
                std::string reason;
        };
    
    private:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();
};


#endif