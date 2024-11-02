
#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    // this->fixedPointValue = other.getRawBits();
    *this = other;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) // not self-assignment
        this->setRawBits(other.getRawBits());
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPointValue = raw;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = value << this->fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = (int)roundf(value * (1 << this->fractionalBits)); // multiplying by 2^8, shift left by 8 bits
}

float Fixed::toFloat(void) const
{
    float   output;

    output = (float)this->fixedPointValue / (1 << this->fractionalBits); // dividing by 2^8, shift right by 8 bits
    return output;
}

int Fixed::toInt(void) const
{
    return this->fixedPointValue >> this->fractionalBits; // shift right by 8 bits, ignore fractional part
}

std::ostream& operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}
