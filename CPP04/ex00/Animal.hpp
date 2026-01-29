#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
	std::string type;

	public:
	// void makeSound() const;
	Animal();
	Animal(const Animal& d);
	Animal &operator=(const Animal& d);
	virtual void makeSound() const; 
	const std::string getType() const;
	virtual ~Animal();
};

#endif