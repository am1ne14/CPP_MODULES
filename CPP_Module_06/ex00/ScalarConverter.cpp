#include "ScalarConverter.hpp"

#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

enum LiteralType
{
	TYPE_INVALID,
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_PSEUDO_FLOAT,
	TYPE_PSEUDO_DOUBLE
};

static bool	isPseudoFloat(const std::string &s)
{
	return (s == "nanf" || s == "+inff" || s == "-inff");
}

static bool	isPseudoDouble(const std::string &s)
{
	return (s == "nan" || s == "+inf" || s == "-inf");
}

static bool	isIntLiteral(const std::string &s)
{
	std::size_t	i;

	if (s.empty())
		return (false);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		++i;
	if (i == s.size())
		return (false);
	while (i < s.size())
	{
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return (false);
		++i;
	}
	return (true);
}

static bool	isDecimalCore(const std::string &s)
{
	std::size_t	i;
	bool		hasDot;
	bool		hasDigit;

	if (s.empty())
		return (false);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		++i;
	if (i == s.size())
		return (false);
	hasDot = false;
	hasDigit = false;
	while (i < s.size())
	{
		if (std::isdigit(static_cast<unsigned char>(s[i])))
			hasDigit = true;
		else if (s[i] == '.' && !hasDot)
			hasDot = true;
		else
			return (false);
		++i;
	}
	return (hasDot && hasDigit);
}

static bool	isFloatLiteral(const std::string &s)
{
	if (s.size() < 2 || s[s.size() - 1] != 'f')
		return (false);
	return (isDecimalCore(s.substr(0, s.size() - 1)));
}

static bool	isDoubleLiteral(const std::string &s)
{
	return (isDecimalCore(s));
}

static LiteralType	detectType(const std::string &literal)
{
	if (literal.size() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))
		return (TYPE_CHAR);
	if (isPseudoFloat(literal))
		return (TYPE_PSEUDO_FLOAT);
	if (isPseudoDouble(literal))
		return (TYPE_PSEUDO_DOUBLE);
	if (isIntLiteral(literal))
		return (TYPE_INT);
	if (isFloatLiteral(literal))
		return (TYPE_FLOAT);
	if (isDoubleLiteral(literal))
		return (TYPE_DOUBLE);
	return (TYPE_INVALID);
}

static bool	parseInt(const std::string &s, int &value)
{
	char	*end;
	long	raw;

	raw = std::strtol(s.c_str(), &end, 10);
	if (*end != '\0' || raw < INT_MIN || raw > INT_MAX)
		return (false);
	value = static_cast<int>(raw);
	return (true);
}

static bool	parseDouble(const std::string &s, double &value)
{
	char	*end;

	value = std::strtod(s.c_str(), &end);
	return (*end == '\0');
}

static bool	parseFloat(const std::string &s, float &value)
{
	double		raw;
	char		*end;
	std::string	core;

	core = s.substr(0, s.size() - 1);
	raw = std::strtod(core.c_str(), &end);
	if (*end != '\0')
		return (false);
	value = static_cast<float>(raw);
	return (true);
}

static std::string	formatFinite(double value, int precision)
{
	std::ostringstream	oss;
	std::string			out;

	oss << std::setprecision(precision) << value;
	out = oss.str();
	if (out.find('.') == std::string::npos
		&& out.find('e') == std::string::npos
		&& out.find('E') == std::string::npos)
		out += ".0";
	return (out);
}

static void	printImpossibleAll(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static void	printChar(double value)
{
	char	c;

	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value) || value < 0.0 || value > 127.0)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	c = static_cast<char>(value);
	if (!std::isprint(static_cast<unsigned char>(c)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

static void	printInt(double value)
{
	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value)
		|| value < static_cast<double>(INT_MIN)
		|| value > static_cast<double>(INT_MAX))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << static_cast<int>(value) << std::endl;
}

static void	printFloat(double value)
{
	float	f;

	std::cout << "float: ";
	if (std::isnan(value))
	{
		std::cout << "nanf" << std::endl;
		return ;
	}
	if (std::isinf(value))
	{
		if (value < 0.0)
			std::cout << "-inff" << std::endl;
		else
			std::cout << "+inff" << std::endl;
		return ;
	}
	if (value > std::numeric_limits<float>::max()
		|| value < -std::numeric_limits<float>::max())
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	f = static_cast<float>(value);
	std::cout << formatFinite(static_cast<double>(f), 7) << "f" << std::endl;
}

static void	printDouble(double value)
{
	std::cout << "double: ";
	if (std::isnan(value))
	{
		std::cout << "nan" << std::endl;
		return ;
	}
	if (std::isinf(value))
	{
		if (value < 0.0)
			std::cout << "-inf" << std::endl;
		else
			std::cout << "+inf" << std::endl;
		return ;
	}
	std::cout << formatFinite(value, 15) << std::endl;
}

void	ScalarConverter::convert(const std::string &literal)
{
	LiteralType	type;
	double		value;
	int			intValue;
	float		floatValue;

	type = detectType(literal);
	if (type == TYPE_INVALID)
	{
		printImpossibleAll();
		return ;
	}
	if (type == TYPE_CHAR)
		value = static_cast<double>(literal[0]);
	else if (type == TYPE_INT)
	{
		if (!parseInt(literal, intValue))
		{
			printImpossibleAll();
			return ;
		}
		value = static_cast<double>(intValue);
	}
	else if (type == TYPE_FLOAT)
	{
		if (!parseFloat(literal, floatValue))
		{
			printImpossibleAll();
			return ;
		}
		value = static_cast<double>(floatValue);
	}
	else if (type == TYPE_DOUBLE)
	{
		if (!parseDouble(literal, value))
		{
			printImpossibleAll();
			return ;
		}
	}
	else if (type == TYPE_PSEUDO_FLOAT)
	{
		if (literal == "nanf")
			value = std::numeric_limits<float>::quiet_NaN();
		else if (literal == "+inff")
			value = std::numeric_limits<float>::infinity();
		else
			value = -std::numeric_limits<float>::infinity();
	}
	else
	{
		if (literal == "nan")
			value = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "+inf")
			value = std::numeric_limits<double>::infinity();
		else
			value = -std::numeric_limits<double>::infinity();
	}
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
