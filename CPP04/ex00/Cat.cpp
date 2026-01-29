#include "Cat.hpp"


Cat::Cat()
{
	std::cout<<"cat defualt constractor called\n";
	type = "Cat";
}
Cat::Cat(std::string n)
{
	std::cout<<"cat paramitarized constractor called\n";
	type = n;
}

void Cat::makeSound() const
{
	std::cout<<"Meow🐱\n";
}

const std::string Cat::getType()
{
	return(Animal::type);
}
Cat::~Cat()
{
	std::cout<<"cat destractor called\n";
}

Cat::Cat(const Cat& d)
{
	std::cout<<"Cat copy constractor called\n";
	type = d.type;
}
Cat &Cat::operator=(const Cat& d)
{
	std::cout<<"Cat copy assignment constructor called\n";
	if(this != &d)
	{
		type = d.type;
	}
	return (*this);
}