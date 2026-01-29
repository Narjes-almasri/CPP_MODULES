#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"


class Dog : public Animal
{
	private:
	Brain* dog_brain;

	public:
	Dog();
	Dog(std::string n);
	Dog(const Dog& d);
	Dog &operator=(const Dog& d);
	Brain* getBrain() const;
	void	setIdea(int ind,std::string idea);
	void makeSound() const;
	const std::string getType() const;  
	virtual ~Dog();
};

#endif