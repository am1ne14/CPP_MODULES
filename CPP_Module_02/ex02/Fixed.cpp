#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() {
    _rawBits = 0;
}

Fixed::Fixed(const int n) {
    _rawBits = n << _fractionalBits;
}

Fixed::Fixed(const float f) {
    _rawBits = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
    _rawBits = other._rawBits;
}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        _rawBits = other._rawBits;
    }
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
    return _rawBits;
}

void Fixed::setRawBits(int const raw) {
    _rawBits = raw;
}

float Fixed::toFloat(void) const {
    return (float)_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _rawBits >> _fractionalBits;
}

bool Fixed::operator>(const Fixed &other) const {
    return _rawBits > other._rawBits;
}

bool Fixed::operator<(const Fixed &other) const {
    return _rawBits < other._rawBits;
}

bool Fixed::operator>=(const Fixed &other) const {
    return _rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed &other) const {
    return _rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed &other) const {
    return _rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed &other) const {
    return _rawBits != other._rawBits;
}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result._rawBits = _rawBits + other._rawBits;
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result._rawBits = _rawBits - other._rawBits;
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    long temp = (long)_rawBits * (long)other._rawBits;
    result._rawBits = temp >> _fractionalBits;
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;
    long temp = ((long)_rawBits << _fractionalBits) / other._rawBits;
    result._rawBits = temp;
    return result;
}

Fixed &Fixed::operator++() {
    _rawBits++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    _rawBits++;
    return temp;
}

Fixed &Fixed::operator--() {
    _rawBits--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    _rawBits--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a._rawBits < b._rawBits)
        return a;
    else
        return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a._rawBits < b._rawBits)
        return a;
    else
        return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a._rawBits > b._rawBits)
        return a;
    else
        return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a._rawBits > b._rawBits)
        return a;
    else
        return b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f) {
    out << f.toFloat();
    return out;
}
