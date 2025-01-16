#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
    _rawBits = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int raw)
{
    std::cout << "Int constructor called" << std::endl;
    _rawBits = raw << _fractionalBits;
}

Fixed::Fixed(const float raw)
{
    float temp;
    std::cout << "Float constructor called" << std::endl;
    temp = raw * (1 << _fractionalBits);
    _rawBits = roundf(temp);
}

float Fixed::toFloat(void) const
{
    return ((float)_rawBits / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
    return _rawBits >> _fractionalBits;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _rawBits = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
    _rawBits = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
