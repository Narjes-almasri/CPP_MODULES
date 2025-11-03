#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{	
	Name = "def";
	clap_name = "def";
    HitPoint = 100;
    EnergyPoint = 50;
    AttackDam = 30;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

DiamondTrap::DiamondTrap(std::string name):ClapTrap(name),ScavTrap(name),FragTrap(name),Name(name),clap_name(name + "_clap_name")
{
	std::cout << "DiamondTrap parameterized constructor called\n";
	HitPoint = 100;
	EnergyPoint = 50;
	AttackDam = 30;
}

void DiamondTrap::whoAmI()
{
	std::cout<<"DiamondTrap name is = " << Name  << "\n";
	std::cout<<"ClapTrap name is = " << clap_name <<"\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), ScavTrap(other),FragTrap(other),Name(other.Name),clap_name(other.clap_name)
{
	std::cout<<"DiamondTrap copy const called\n";
	Name = other.Name;
	HitPoint = other.HitPoint;
	AttackDam = other.AttackDam;
	EnergyPoint = other.EnergyPoint;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& d)
{
	std::cout<<"DiamondTrap copy assignment const called\n";
	if(this != &d)
	{
		Name = d.Name;
		HitPoint = d.HitPoint;
		AttackDam = d.AttackDam;
		EnergyPoint = d.EnergyPoint;
	}
	return (*this);
}
DiamondTrap:: ~DiamondTrap()
{
	std::cout<<"DiamondTrap destractor called\n";
}