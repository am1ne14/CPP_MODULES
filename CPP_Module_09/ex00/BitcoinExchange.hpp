#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>

class BitcoinExchange {
private:
    std::map<std::string, float> _database;

    bool _isValidDate(const std::string& date) const;
    bool _isValidValue(const std::string& valueStr, float& value) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& src);
    BitcoinExchange& operator=(const BitcoinExchange& rhs);
    ~BitcoinExchange();

    bool loadDatabase(const std::string& filename);
    void processInput(const std::string& filename) const;
};

#endif
