#include "FragTrap.hpp"

int main()
{
    FragTrap f("Fragger");
    f.attack("Target");
    f.highFivesGuys();
    f.takeDamage(100); // HP = 0
    f.highFivesGuys(); // silent
    return 0;
}

/*
ClapTrap parameterized constructor called
FragTrap parameterized constructor called
FragTrap Fragger attacks Target, causing 30 points of damage!
FragTrap Fragger gives a high five!
ClapTrap Fragger takes 100 points of damage!
FragTrap destructor called
ClapTrap destructor called
*/