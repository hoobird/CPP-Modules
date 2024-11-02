#ifndef FIXED_H
#define FIXED_H

#include <iostream>

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
};

#endif