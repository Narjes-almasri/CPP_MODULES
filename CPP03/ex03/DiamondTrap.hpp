#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

//But → both ScavTrap and FragTrap inherit from ClapTrap, so without care, you get two ClapTrap instances.
// for virtual ==> https://chatgpt.com/share/690799e9-4c7c-8009-ade5-3235dd76a5cb
class DiamondTrap : public ScavTrap , public FragTrap
{
	private:
	std::string Name;
	std::string clap_name;
	
	public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap& d);
	
	void attack(const std::string& target);
	void whoAmI();
    ~DiamondTrap();
};

#endif