#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <iostream>

class ScalarConverter
{
public:
	static void convert(const std::string &literal);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();
};

#endif