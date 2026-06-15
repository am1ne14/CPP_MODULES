#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <list>

class RPN {
private:
    std::stack<int, std::list<int> > _stack;

    bool _isOperator(const std::string& token) const;
    int _performOperation(const std::string& op, int a, int b) const;

public:
    RPN();
    RPN(const RPN& src);
    RPN& operator=(const RPN& rhs);
    ~RPN();

    void calculate(const std::string& expression);
};

#endif
