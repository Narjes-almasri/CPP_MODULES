#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal
{
	public:
	Dog();
	Dog(std::string n);
	Dog &operator=(const Dog& d);
	Dog(const Dog& d);
	void makeSound() const;
	const std::string getType();
	virtual ~Dog();
};

#endif