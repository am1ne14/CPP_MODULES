#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <iostream>

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_db = other._db;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::trim(std::string &s) const
{
	size_t start = s.find_first_not_of(" \t");
	size_t end = s.find_last_not_of(" \t");

	if (start == std::string::npos)
	{
		s = "";
		return;
	}
	s = s.substr(start, end - start + 1);
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.size() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;

	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;

	if (day < 1 || day > 31)
		return false;

	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return false;
	}

	if (month == 2)
	{
		bool leap = false;

		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			leap = true;

		if (leap == true)
		{
			if (day > 29)
				return false;
		}
		else
		{
			if (day > 28)
				return false;
		}
	}

	return true;
}

bool BitcoinExchange::parseValue(const std::string &str, double &value) const
{
	std::istringstream ss(str);
	ss >> value;

	if (ss.fail())
		return false;

	if (!ss.eof())
		return false;

	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}

	if (value > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}

	return true;
}

bool BitcoinExchange::loadDatabase(const std::string &file)
{
	std::ifstream in(file.c_str());

	if (!in)
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return false;
	}

	std::string line;
	std::getline(in, line);

	while (std::getline(in, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string rateStr;

		if (!std::getline(ss, date, ','))
			continue;

		if (!std::getline(ss, rateStr))
			continue;

		trim(date);
		trim(rateStr);

		double rate = std::atof(rateStr.c_str());

		_db[date] = rate;
	}

	return true;
}

void BitcoinExchange::processInput(const std::string &file) const
{
	std::ifstream in(file.c_str());

	if (!in)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(in, line);

	while (std::getline(in, line))
	{
		if (line.empty())
			continue;

		size_t pos = line.find('|');

		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, pos);
		std::string valueStr = line.substr(pos + 1);

		trim(date);
		trim(valueStr);

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		double value;

		if (!parseValue(valueStr, value))
			continue;

		std::map<std::string, double>::const_iterator it = _db.lower_bound(date);

		if (it == _db.end())
		{
			if (_db.size() > 0)
				it--;
			else
			{
				std::cerr << "Error: empty database" << std::endl;
				continue;
			}
		}
		else
		{
			if (it != _db.begin())
			{
				if (it->first != date)
					it--;
			}
		}

		double result = value * it->second;

		std::cout << date << " => " << value << " = " << result << std::endl;
	}
}
