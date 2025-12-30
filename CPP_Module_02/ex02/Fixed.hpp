#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _rawBits;
    static const int _fractionalBits = 8;

public:
    // Constructors / Destructor
    Fixed();
    Fixed(const int n);
    Fixed(const float f);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    // Getters / Setters
    int getRawBits(void) const;
    void setRawBits(int const raw);

    // Conversion
    float toFloat(void) const;
    int toInt(void) const;

    // Comparison operators
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // Arithmetic operators
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Increment / Decrement
    Fixed &operator++();   // pre-increment
    Fixed operator++(int); // post-increment
    Fixed &operator--();   // pre-decrement
    Fixed operator--(int); // post-decrement

    // Min / Max
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

// Insertion operator
std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif

