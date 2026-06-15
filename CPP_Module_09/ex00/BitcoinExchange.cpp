#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
    *this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
    if (this != &rhs) {
        this->_database = rhs._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return false;
    }

    std::string line;
    std::getline(file, line); // Skip header

    while (std::getline(file, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string date = line.substr(0, commaPos);
            std::string rateStr = line.substr(commaPos + 1);
            char* endPtr;
            float rate = static_cast<float>(std::strtod(rateStr.c_str(), &endPtr));
            if (*endPtr == '\0' || *endPtr == '\n' || *endPtr == '\r') {
                _database[date] = rate;
            }
        }
    }
    file.close();
    return true;
}

bool BitcoinExchange::_isValidDate(const std::string& date) const {
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;

    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i])) return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;

    if (month == 2) {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeap ? 29 : 28))
            return false;
    }

    return true;
}

bool BitcoinExchange::_isValidValue(const std::string& valueStr, float& value) const {
    if (valueStr.empty()) return false;
    char* endPtr;
    value = static_cast<float>(std::strtod(valueStr.c_str(), &endPtr));
    if (endPtr == valueStr.c_str()) return false;
    if (*endPtr != '\0' && *endPtr != 'f') return false; // Basic float check
    return true;
}

void BitcoinExchange::processInput(const std::string& filename) const {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Skip header if it is "date | value", but we should just process line by line.
    if (line != "date | value") {
        // If the first line is not the exact header, we might want to process it as data
        // Let's reset stream if it's not the header, but the subject says "date | value" is the header.
        // I will just ignore it if it equals "date | value".
    }

    while (std::getline(file, line)) {
        if (line.empty()) continue;
        if (line == "date | value") continue;

        size_t pipePos = line.find(" | ");
        if (pipePos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pipePos);
        std::string valueStr = line.substr(pipePos + 3);

        if (!_isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        float value;
        if (!_isValidValue(valueStr, value)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, float>::const_iterator it = _database.lower_bound(date);
        
        if (it != _database.end() && it->first == date) {
            std::cout << date << " => " << value << " = " << value * it->second << std::endl;
        } else {
            if (it == _database.begin()) {
                std::cerr << "Error: bad input => " << date << std::endl; // Date too early
            } else {
                --it;
                std::cout << date << " => " << value << " = " << value * it->second << std::endl;
            }
        }
    }
    file.close();
}
