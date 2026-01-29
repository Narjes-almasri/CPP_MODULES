#include "Animal.hpp"

const std::string Animal::getType() const
{
	return(Animal::type);
}

Animal::Animal()
{
	std::cout<<"animal defualt constractor called\n";
}

Animal::Animal(const Animal& d)
{
	std::cout<<"animal copy constractor called\n";
	type = d.type;
}
Animal &Animal::operator=(const Animal& d)
{
	std::cout<<"Animal copy assignment constructor called\n";
	if(this != &d)
	{
		type = d.type;
	}
	return (*this);
}
Animal::~Animal()
{
	std::cout<<"animal destractor called\n";
}