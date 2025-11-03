#include "ClapTrap.hpp"

// orthodox

ClapTrap::ClapTrap()
{
	std::cout<<"ClapTrap default constructor called\n";
	 Name = "defualt";
	 HitPoint = 10; 
	 EnergyPoint = 10;
	 AttackDam = 0;
}

ClapTrap::ClapTrap(const ClapTrap& d)
{
	std::cout<<"ClapTrap copy constructor called\n";
	Name = d.Name;
	HitPoint = d.HitPoint;
	AttackDam = d.AttackDam;
	EnergyPoint = d.EnergyPoint;
}
ClapTrap &ClapTrap::operator=(const ClapTrap& d)
{
	std::cout<<"ClapTrap copy assignment constructor called\n";
	if(this != &d)
	{
		Name = d.Name;
		HitPoint = d.HitPoint;
		AttackDam = d.AttackDam;
		EnergyPoint = d.EnergyPoint;
	}
	return (*this);
}
ClapTrap::~ClapTrap()
{
	std::cout<<"ClapTrap Destructor called\n";
}

////////////////

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap parameterized constructor called\n";
	Name = name;
	HitPoint = 10;
	AttackDam = 0;
	EnergyPoint = 10;
}

void ClapTrap::attack(const std::string& target)
{
	
	if(HitPoint == 0 || EnergyPoint == 0)
	{
		return;
	}
	else
	{
		EnergyPoint--;
		std::cout<<"ClapTrap " << Name << " attacks " << target << ", causing " << AttackDam << " points of damage!\n"; 
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if((amount >= 0 && HitPoint == 0) || EnergyPoint == 0)
	{
		return;
	}
	else 
	{
		HitPoint+=amount ;
		EnergyPoint--;
		std::cout<<"ClapTrap " <<Name << " is repaired and gains " <<amount << " hit points!\n";
	}	
}

void ClapTrap::takeDamage(unsigned int amount)
{
	// std::cout << " hp " << HitPoint << "\n";
	if(HitPoint == 0)
	{
		return;
	}
	else if (HitPoint > 0)
	{
		HitPoint-=amount;	
		std::cout<<"ClapTrap "<<Name<<" takes "<< amount <<  " points of damage!\n";
		if((HitPoint-=amount) <= 0 )
			HitPoint =0;
	}
}



