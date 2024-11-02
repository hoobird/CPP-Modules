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
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

#endif