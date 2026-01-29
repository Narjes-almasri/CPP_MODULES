#include "Dog.hpp"

Dog::Dog()
{
	std::cout<<"Dog defualt constractor called\n";
	type = "Dog";
	dog_brain = new Brain();
}

Dog::Dog(std::string n)
{
	std::cout<<"dog paramitarized constractor called\n";
	type = n;
	dog_brain = new Brain();
}

void Dog::makeSound() const
{
	std::cout<<"Dog is making sound 🐶\n";
}

const std::string Dog::getType() const 
{
	return(Animal::type);
}

Dog::~Dog()
{
	std::cout<<"dog destractor called\n";
	delete dog_brain;
}


Dog::Dog(const Dog& d)
{
	std::cout<<"dog copy constractor called\n";
	type = d.type;
	dog_brain = new Brain();
	int i = 0;
	while( i < 100)
	{
		this->dog_brain->ideas[i] = d.dog_brain->ideas[i];
		i++;
	}
	
}
Dog &Dog::operator=(const Dog& d)
{
	std::cout<<"Dog copy assignment constructor called\n";
	if(this != &d)
	{
		type = d.type;
		delete this->dog_brain;

		dog_brain = new Brain();

		int i = 0;
		while ( i < 100)
		{
			this->dog_brain->ideas[i] = d.dog_brain->ideas[i];
			i++;
		}
	}
	return (*this);
}

Brain* Dog::getBrain() const {
    return dog_brain; 
}

void Dog::setIdea(int ind,std::string idea)
{
	
	this->dog_brain->ideas[ind] = idea;
	// std::cout<<this->dog_brain->ideas[ind]<<"\n";
}