#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return *this;
}

RPN::~RPN() {}

static bool isOperator(const std::string &c)
{
	return (c == "+" || c == "-" || c == "*" || c == "/");
}

bool RPN::evaluate(const std::string &expr)
{
	std::stack<int> st;
	std::istringstream ss(expr);
	std::string token;
	int	a;
	int	b;
	int	res;

	while (ss >> token)
	{
		if (token.size() == 1 && isdigit(token[0]))
		{
			st.push(token[0] - '0');
		}
		else if (isOperator(token))
		{
			if (st.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return false;
			}

			b = st.top();
			st.pop();
			a = st.top();
			st.pop();

			if (token == "+")
				res = a + b;
			else if (token == "-")
				res = a - b;
			else if (token == "*")
				res = a * b;
			else if (token == "/" && b == 0)
			{
				std::cerr << "Error \n";
				return false;
			}
			else
			{
				res = a / b;
			}
			st.push(res);
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return false;
		}
	}
	if (st.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return false;
	}
	std::cout << st.top() << std::endl;
	return true;
}
