#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal
{
	public:
	Cat ();
	Cat (std::string name);
	Cat &operator=(const Cat& d);
	Cat(const Cat& d);
	void makeSound() const;
	const std::string getType();
	virtual ~Cat();
};

#endif