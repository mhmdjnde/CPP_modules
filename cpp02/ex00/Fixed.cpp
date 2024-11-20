#include <iostream>
#include "Fixed.hpp"

//normal constructor it initialise the _rawBits to 0
Fixed::Fixed()
{
	_rawBits = 0;
    std::cout << "Default constructor called" << std::endl;
}

//a second constructor that will take a referance to another
//object of Fixed type and will  copy the value of the other object
Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

//this will change the Fixed class operator, when we use the "="
//operator it just change the  value of the _rawBits to the value of the
//other object(passed after the = by reference)
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _rawBits = other.getRawBits();
    }
    return *this;
}

//a normal destructor that will be called after that the variable be out of bounds
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

//this will return the current value of _rawBits
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

// Set the raw fixed-point value
void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    _rawBits = raw;
}
