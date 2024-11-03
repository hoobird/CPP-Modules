
#include "Fixed.hpp"

Fixed::Fixed()
{
    // std::cout << "Default constructor called" << std::endl;
    this->fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &other)
{
    // std::cout << "Copy constructor called" << std::endl;
    // this->fixedPointValue = other.getRawBits();
    *this = other;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) // not self-assignment
        this->setRawBits(other.getRawBits());
    return *this;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPointValue = raw;
}

Fixed::Fixed(const int value)
{
    // std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = value << this->fractionalBits;
}

Fixed::Fixed(const float value)
{
    // std::cout << "Float constructor called" << std::endl;
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

bool Fixed::operator>(const Fixed &fixed) const
{
    if (this->toFloat() > fixed.toFloat())
        return true;
    return false;    
}

bool Fixed::operator<(const Fixed &fixed) const
{
    if (this->toFloat() < fixed.toFloat())
        return true;
    return false;    
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    if (this->toFloat() >= fixed.toFloat())
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    if (this->toFloat() <= fixed.toFloat())
        return true;
    return false;
}

bool Fixed::operator==(const Fixed &fixed) const
{
    if (this->toFloat() == fixed.toFloat())
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    if (this->toFloat() != fixed.toFloat())
        return true;
    return false;
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
    float   result;

    result = this->toFloat() + fixed.toFloat();
    return Fixed(result);
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    float   result;

    result = this->toFloat() - fixed.toFloat();
    return Fixed(result);
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    float  result;

    result = this->toFloat() * fixed.toFloat();
    return Fixed(result);

}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    float  result;

    result = this->toFloat() / fixed.toFloat();
    return Fixed(result);
}

Fixed& Fixed::operator++()  // pre-increment ++f
{
    this->fixedPointValue++;
    return *this;
}

Fixed& Fixed::operator--()  // pre-decrement --f
{
    this->fixedPointValue--;
    return *this;
}

Fixed Fixed::operator++(int)    // post-increment f++
{
    Fixed   temp(*this);

    this->fixedPointValue++;
    return temp;
}

Fixed Fixed::operator--(int)    // post-decrement f--
{
    Fixed   temp(*this);

    this->fixedPointValue--;
    return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

std::ostream& operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}
