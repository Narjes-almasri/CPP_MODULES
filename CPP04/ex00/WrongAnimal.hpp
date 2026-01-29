#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal
{
	protected:
	std::string type;

	public:

	WrongAnimal();
	WrongAnimal(const WrongAnimal& d);
	WrongAnimal &operator=(const WrongAnimal& d);
	void makeSound() const; 
	const std::string getType() const;
	virtual ~WrongAnimal();
};

#endif