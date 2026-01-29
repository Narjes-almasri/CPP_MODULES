#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
	Brain* b;
	
	public:
	Cat ();
	Cat (std::string name);
	Cat &operator=(const Cat& d);
	Brain* getBrain() const;
	Cat(const Cat& d);
	void makeSound() const;
	const std::string getType() const;  
	virtual ~Cat();
};

#endif