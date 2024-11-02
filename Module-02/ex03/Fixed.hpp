#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int                 fixedPointValue;
		static const int    fractionalBits = 8;

	public:
		Fixed();								// Default constructor
		Fixed(const Fixed &fixed);				// Copy constructor
		~Fixed();								// Destructor
		Fixed	&operator=(const Fixed &fixed2);	// Copy Assignment operator
		int     getRawBits(void) const;
		void    setRawBits(int const raw);

		Fixed(const int value);
		Fixed(const float value);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool operator>(const Fixed &fixed) const;
		bool operator<(const Fixed &fixed) const;
		bool operator>=(const Fixed &fixed) const;
		bool operator<=(const Fixed &fixed) const;
		bool operator==(const Fixed &fixed) const;
		bool operator!=(const Fixed &fixed) const;
		Fixed operator+(const Fixed &fixed) const;
		Fixed operator-(const Fixed &fixed) const;
		Fixed operator*(const Fixed &fixed) const;
		Fixed operator/(const Fixed &fixed) const;
		Fixed &operator++();	// pre-increment
		Fixed &operator--();	// pre-decrement
		Fixed operator++(int);	// post-increment
		Fixed operator--(int);	// post-decrement;
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

#endif