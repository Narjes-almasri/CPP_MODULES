#include "WrongAnimal.hpp"

const std::string WrongAnimal::getType() const
{
	return(WrongAnimal::type);
}

void WrongAnimal::makeSound() const{
	std::cout<<"WrongAnimal sound\n";
}
WrongAnimal::WrongAnimal()
{
	std::cout<<"WrongAnimal defualt constractor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& d)
{
	std::cout<<"WrongAnimal copy constractor called\n";
	type = d.type;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal& d)
{
	std::cout<<"WrongAnimal copy assignment constructor called\n";
	if(this != &d)
	{
		type = d.type;
	}
	return (*this);
}
WrongAnimal::~WrongAnimal()
{
	std::cout<<"WrongAnimal destractor called\n";
}