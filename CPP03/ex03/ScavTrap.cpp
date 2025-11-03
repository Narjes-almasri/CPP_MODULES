#include "ScavTrap.hpp"

ScavTrap::ScavTrap() 
{
	std::cout<<"ScavTrap default constructor called\n";
	Name = "def";
	HitPoint = 100; 
	EnergyPoint = 50;
	AttackDam = 20;
}
ScavTrap::ScavTrap(const ScavTrap& d) : ClapTrap(d)
{
	std::cout<<"ScavTrap copy constructor called\n";
	Name = d.Name;
	HitPoint = d.HitPoint;
	AttackDam = d.AttackDam;
	EnergyPoint = d.EnergyPoint;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap parameterized constructor called\n";
	Name = name;
	HitPoint = 100; 
	EnergyPoint = 50;
	AttackDam = 20;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& d)
{
	std::cout<<"ScavTrap copy assignment constructor called\n";
	if(this != &d)
	{
		Name = d.Name;
		HitPoint = d.HitPoint;
		AttackDam = d.AttackDam;
		EnergyPoint = d.EnergyPoint;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout<<"ScavTrap Destructor called\n";
}
int ScavTrap::get_EnergyPoint(){
		return(HitPoint);
}
void ScavTrap::attack(const std::string& target)
{
	
	if(HitPoint == 0 || EnergyPoint == 0)
	{
		return;
	}
	else
	{
		EnergyPoint--;
		std::cout<<"ScavTrap " << Name << " attacks " << target << ", causing " << AttackDam << " points of damage!\n"; 
	}
}


void ScavTrap::guardGate()
{
	if (HitPoint <= 0)
		return;
	std::cout <<"ScavTrap " << Name <<" is now in Gate keeper mode\n";
}