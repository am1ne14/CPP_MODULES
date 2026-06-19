#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cctype>

class BitcoinExchange
{
private:
	std::map<std::string, double> _db;

	bool	isValidDate(const std::string &date) const;
	bool	parseValue(const std::string &str, double &value) const;
	void	trim(std::string &s) const;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	bool	loadDatabase(const std::string &file);
	void	processInput(const std::string &file) const;
};

#endif
