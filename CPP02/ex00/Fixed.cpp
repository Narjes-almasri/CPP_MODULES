#include "Fixed.hpp"

int Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits member function called\n";
	return(fixed_num);
}

void Fixed::setRawBits(int const val)
{
	std::cout<<"setRawBits member function called\n";
	fixed_num = val;
}

Fixed::Fixed()
{
	fixed_num = 0;
	std::cout<<"Default constructor called \n";
}

Fixed::Fixed(const Fixed& g)
{
	std::cout<<"copy constructor called \n";
	fixed_num=g.getRawBits();
}

Fixed &Fixed::operator=(const Fixed& obj)
{
	std::cout<<"Copy assignment operator called \n";
	if(this != &obj)
	{
		Fixed::fixed_num=obj.getRawBits() ;
	}
	return (*this);
}	
Fixed::~Fixed()
{
	std::cout<<"Destructor called\n";
}
