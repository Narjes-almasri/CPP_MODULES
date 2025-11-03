#include "ScavTrap.hpp"

int main()
{
    ScavTrap s("Serena");
    s.attack("Target");
    s.guardGate();
    s.takeDamage(100); // HP = 0
    s.guardGate(); // silent
    return 0;
}

/*
ClapTrap parameterized constructor called
ScavTrap parameterized constructor called
ScavTrap Serena attacks Target, causing 20 points of damage!
ScavTrap Serena is now in Gate keeper mode.
ClapTrap Serena takes 100 points of damage!
ScavTrap destructor called
ClapTrap destructor called
*/