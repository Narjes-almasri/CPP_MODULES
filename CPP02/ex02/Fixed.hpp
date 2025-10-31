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
	Fixed(int const val);
	Fixed(float const value);
	~Fixed();
	float toFloat( void ) const;
	int toInt( void ) const;
	
	bool operator>(const Fixed &obj)const;
	bool operator<(const Fixed &obj)const;
	bool operator>=(const Fixed &obj)const;
	bool operator<=(const Fixed &obj)const;
	bool operator==(const Fixed &obj)const;
	bool operator!=(const Fixed &obj)const;
	
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	Fixed operator++(int);//x++
	Fixed& operator++();//++x
	Fixed operator--(int);//x-- post
	Fixed& operator--();//--x pre


	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

	int getRawBits() const;
	void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif