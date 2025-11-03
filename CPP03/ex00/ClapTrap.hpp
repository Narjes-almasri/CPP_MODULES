#ifndef CLAP_TRAP
# define CLAP_TRAP

#include <iostream>

class ClapTrap
{
	private:
	std::string Name;
	int HitPoint ;
	int EnergyPoint ;
	int AttackDam ;

	public:
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	ClapTrap(std::string name);

	// orthodox
	ClapTrap();
	ClapTrap(const ClapTrap& d);
	ClapTrap &operator=(const ClapTrap& d);
	~ClapTrap();

};

#endif