#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN& src) {
    *this = src;
}

RPN& RPN::operator=(const RPN& rhs) {
    if (this != &rhs) {
        this->_stack = rhs._stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::_isOperator(const std::string& token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::_performOperation(const std::string& op, int a, int b) const {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) {
            std::cerr << "Error: Division by zero." << std::endl;
            std::exit(1);
        }
        return a / b;
    }
    return 0;
}

void RPN::calculate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (_isOperator(token)) {
            if (_stack.size() < 2) {
                std::cerr << "Error" << std::endl;
                return;
            }
            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();

            int result = _performOperation(token, a, b);
            _stack.push(result);
        } else {
            // Check if token is a valid number (< 10 as per rules)
            // But wait, the subject says: "The numbers used in this operation and passed as arguments will always be less than 10."
            // So they are single digits, maybe preceded by a sign? Or just positive?
            // So we can assume numbers are 0-9. Wait, let's just parse it as int.
            bool isValid = true;
            if (token.length() > 1 && !(token.length() == 2 && (token[0] == '+' || token[0] == '-'))) {
                isValid = false;
            }
            for (size_t i = (token[0] == '+' || token[0] == '-') ? 1 : 0; i < token.length(); ++i) {
                if (!isdigit(token[i])) {
                    isValid = false;
                    break;
                }
            }

            if (!isValid) {
                std::cerr << "Error" << std::endl;
                return;
            }

            int num = std::atoi(token.c_str());
            if (num >= 10 || num <= -10) {
                std::cerr << "Error" << std::endl;
                return;
            }
            _stack.push(num);
        }
    }

    if (_stack.size() != 1) {
        std::cerr << "Error" << std::endl;
        return;
    }

    std::cout << _stack.top() << std::endl;
}
