#include <iostream>
#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;     // 0
    std::cout << ++a << std::endl;   // pre-increment
    std::cout << a << std::endl;     // same value
    std::cout << a++ << std::endl;   // post-increment
    std::cout << a << std::endl;     // value after post-inc
    std::cout << b << std::endl;     // multiplication result
    std::cout << Fixed::max(a, b) << std::endl; // max value

    return 0;
}

