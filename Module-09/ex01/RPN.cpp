#include "RPN.hpp"

void RPN::evaluate(const std::string &exp)
{
    std::stack<int> operands;
    std::istringstream iss(exp);
    std::string token;

    while (iss >> token) {

        if (token.size() != 1) {
            throw InvalidExpressionException("Invalid token: " + token);
        }
        if (!isdigit(token[0]) && token[0] != '+' && token[0] != '-' &&
            token[0] != '*' && token[0] != '/') {
            throw InvalidExpressionException("Invalid character: " + token);
        }
        // 1) Number just push to stack
        // 2) Operator pop two operands, apply operator, push result
        if (isdigit(token[0])) {
            operands.push(token[0] - '0');
        } else {
            if (operands.size() < 2) {
                throw InvalidExpressionException("Not enough operands to perform operation for token: " + token);
            }
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
            int result = 0;
            switch (token[0]) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    if (b == 0)
                        throw InvalidExpressionException("Division by zero occured");
                    result = a / b;
                    break;
                default:
                    throw InvalidExpressionException("Unknown operator: " + token);
                    // this should never happen due to earlier checks, but just in case
            }
            operands.push(result);
        }
    }
    if (operands.size() != 1) {
        throw InvalidExpressionException("invalid expression as more than 1 operand left in stack in the end");
    }
    int result = operands.top();
    std::cout << result << std::endl;
}

// USELESS PRIVATED OCF
RPN::RPN() {}

RPN::RPN(const RPN &other)
{
    (void) other;
}

RPN &RPN::operator=(const RPN &other)
{
    (void) other;
    return *this;
}

RPN::~RPN() {}
