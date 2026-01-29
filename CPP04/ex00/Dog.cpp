#include "Dog.hpp"

Dog::Dog()
{
	std::cout<<"Dog defualt constractor called\n";
	type = "Dog";
}

Dog::Dog(std::string n)
{
	type = n;
}

void Dog::makeSound() const
{
	std::cout<<"Dog is making sound 🐶\n";
}

const std::string Dog::getType()
{
	return(Animal::type);
}

Dog::~Dog()
{
	std::cout<<"dog destractor called\n";
}


Dog::Dog(const Dog& d)
{
	std::cout<<"Cat copy constractor called\n";
	type = d.type;
}
Dog &Dog::operator=(const Dog& d)
{
	std::cout<<"Dog copy assignment constructor called\n";
	if(this != &d)
	{
		type = d.type;
	}
	return (*this);
}