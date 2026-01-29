#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout<<"WrongCat defualt constractor called\n";
	type = "WrongCat";
}
WrongCat::WrongCat(std::string n)
{
	std::cout<<"WrongCat paramitarized constractor called\n";
	type = n;
}

void WrongCat::makeSound() const
{
	std::cout<<"WrongCat sound\n";
}

const std::string WrongCat::getType() const
{
	return(WrongAnimal::type);
}
WrongCat::~WrongCat()
{
	std::cout<<"WrongCat destractor called\n";
}

WrongCat::WrongCat(const WrongCat& d)
{
	std::cout<<"WrongCat copy constractor called\n";
	type = d.type;
}
WrongCat &WrongCat::operator=(const WrongCat& d)
{
	std::cout<<"WrongCat copy assignment constructor called\n";
	if(this != &d)
	{
		type = d.type;
	}
	return (*this);
}