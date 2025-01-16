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
    std::cout << "Float constructor calledd" << std::endl;
    temp = raw * (1 << _fractionalBits);
    _rawBits = roundf(temp);
}

float   Fixed::toFloat(void) const
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

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return _rawBits;
}

void Fixed::setRawBits(int const raw) {
    _rawBits = raw;
}

bool Fixed::operator>(const Fixed &other)
{
    if (this->_rawBits > other._rawBits)
        return true;
    return false;
}

bool Fixed::operator<(const Fixed &other)
{
    if (this->_rawBits < other._rawBits)
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed &other)
{
    if (this->_rawBits >= other._rawBits)
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed &other)
{
    if (this->_rawBits <= other._rawBits)
        return true;
    return false;
}

bool Fixed::operator==(const Fixed &other)
{
    if (this->_rawBits == other._rawBits)
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed &other)
{
    if (this->_rawBits != other._rawBits)
        return true;
    return false;
}

Fixed Fixed::operator+(const Fixed &other)
{
    Fixed temp;
    temp._rawBits = this->_rawBits + other._rawBits;
    return temp;
}

Fixed Fixed::operator-(const Fixed &other)
{
    Fixed temp;
    temp._rawBits = this->_rawBits - other._rawBits;
    return temp;
}

Fixed Fixed::operator*(const Fixed &other)
{
    Fixed temp;
    temp._rawBits = (this->_rawBits * other._rawBits) / (1 << _fractionalBits);
    return temp;
}

Fixed Fixed::operator/(const Fixed &other)
{
    Fixed temp;
    temp._rawBits = (this->_rawBits * (1 << _fractionalBits)) / other._rawBits;
    return temp;
}

// Pre-increment
Fixed& Fixed::operator++(void) {
    this->_rawBits++;
    return *this;    
}

// Pre-decrement
Fixed& Fixed::operator--(void) {
    this->_rawBits--;
    return *this;    
}

// Post-increment
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->_rawBits++;  
    return temp;       
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->_rawBits--;  
    return temp;       
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a._rawBits > b._rawBits)
        return b;
    return a;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a._rawBits > b._rawBits)
        return b;
    return a;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a._rawBits < b._rawBits)
        return b;
    return a;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a._rawBits < b._rawBits)
        return b;
    return a;
}
