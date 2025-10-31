#include "Fixed.hpp"

int Fixed::getRawBits() const
{
	std::cout<<"getRawBits member function called\n";
	return(fixed_num);
}

void Fixed::setRawBits(int const val)
{
	this->fixed_num= val;
	std::cout<<"setRawBits member function called\n";
}

Fixed::Fixed()
{
	fixed_num = 0;
	std::cout<<"Default constructor called \n";
}

Fixed::Fixed(const Fixed& g)
{
	std::cout<<"copy constructor called \n";
		fixed_num=g.fixed_num;
}

Fixed &Fixed::operator=(const Fixed& obj)
{
	std::cout<<"Copy assignment operator called \n";
	if(this != &obj)
	{
		Fixed::fixed_num= obj.fixed_num;
	}
	return (*this);
}

Fixed::Fixed(const int val)
{
	std::cout<<"Int constructor called\n";
	fixed_num = val * 256;
}
Fixed::Fixed(const float value)
{
	std::cout<<"Float constructor called\n";
	fixed_num = static_cast<int>(roundf(value * 256));
}

float Fixed::toFloat()const
{
	return(fixed_num/256.0f);
}

int Fixed::toInt()const
{
	return(fixed_num/256);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called\n";
}

	