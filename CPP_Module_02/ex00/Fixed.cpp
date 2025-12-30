#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignmnt operator called\n";
	if (this != &other)
		this->_rawBits = other._rawBits;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member fution called\n";
	return this->_rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}
