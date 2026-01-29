#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
	WrongCat ();
	WrongCat (std::string name);
	WrongCat &operator=(const WrongCat& d);
	WrongCat(const WrongCat& d);
	void makeSound() const;
	const std::string getType()const;
	virtual ~WrongCat();
};

#endif