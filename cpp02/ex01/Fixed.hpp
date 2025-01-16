#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _rawBits;
    static const int    _fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed(const int raw);
    Fixed(const float raw);
    float toFloat( void ) const;
    int toInt( void ) const;
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
