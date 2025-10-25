#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>


class Weapon
{
	private:
	std::string type;

	public:
	Weapon(std::string d);
	const std::string &getType()const;
	void setType(std::string setw);
};


#endif