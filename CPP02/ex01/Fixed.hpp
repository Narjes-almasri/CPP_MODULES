#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>


#include <cmath>

class Fixed
{
	private:
	int fixed_num;
	static const int fractional_bits = 8;
	
	public:
	Fixed();
	Fixed(const Fixed& g);
	Fixed &operator=(const Fixed& obj);

	Fixed(const int val);
	Fixed(const float value);
	~Fixed();
	float toFloat( void ) const;
	int toInt( void ) const;
	
	int getRawBits() const;
	void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif