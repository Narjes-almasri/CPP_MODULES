#include "Cat.hpp"


Cat::Cat()
{
	std::cout<<"cat defualt constractor called\n";
	type = "Cat";
	b = new Brain();
}
Cat::Cat(std::string n)
{
	std::cout<<"cat paramitarized constractor called\n";
	type = n;
	b = new Brain();
}

void Cat::makeSound() const
{
	std::cout<<"Meow🐱\n";
}

const std::string Cat::getType() const 
{
	return(Animal::type);
}
Cat::~Cat()
{
	std::cout<<"cat destractor called\n";
	delete b;
}

Cat::Cat(const Cat& d)
{
	std::cout<<"Cat copy constractor called\n";
	type = d.type;
	b = new Brain();
	int i = 0;
	while(i < 100)
	{
		this->b->ideas[i] = d.b->ideas[i];
		i++;
	}
}
Cat &Cat::operator=(const Cat& d)
{
	std::cout<<"Cat copy assignment constructor called\n";
	if(this != &d)
	{
		type = d.type;
		delete this->b;
		this->b = new Brain();
		int i = 0;
		while(i < 100)
		{
			this->b->ideas[i] = d.b->ideas[i];
			i++;
		}

	}
	return (*this);
}

Brain* Cat::getBrain() const {
    return b;
}