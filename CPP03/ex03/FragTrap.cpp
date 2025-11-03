#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout<<"FragTrap defualt constructor called\n";
	Name = "def";
	HitPoint = 100;
	EnergyPoint = 100;
	AttackDam = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap parameterized constructor called\n";
	Name = name;
	HitPoint = 100;
	EnergyPoint = 100;
	AttackDam = 30;
}
FragTrap::FragTrap(const FragTrap& d) : ClapTrap(d)
{
	std::cout<<"FragTrap copy constructor called\n";
	Name = d.Name;
	HitPoint = d.HitPoint;
	AttackDam = d.AttackDam;
	EnergyPoint = d.EnergyPoint;
}
FragTrap &FragTrap::operator=(const FragTrap& d)
{
	std::cout<<"FragTrap copy assignment constructor called\n";
	if(this != &d)
	{
		Name = d.Name;
		HitPoint = d.HitPoint;
		AttackDam = d.AttackDam;
		EnergyPoint = d.EnergyPoint;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout<<"FragTrap Destractor called\n";
}

void FragTrap::attack(const std::string& target)
{
	
	if(HitPoint == 0 || EnergyPoint == 0)
	{
		return;
	}
	else
	{
		EnergyPoint--;
		std::cout<<"FragTrap " << Name << " attacks " << target << ", causing " << AttackDam << " points of damage!\n"; 
	}
}


void FragTrap::highFivesGuys()
{
	if (HitPoint <= 0)
		return;
	std::cout <<"FragTrap " << Name <<" gives a high five!\n";
}