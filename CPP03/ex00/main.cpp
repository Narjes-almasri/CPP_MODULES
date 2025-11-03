#include "ClapTrap.hpp"

// int main()
// {
//     // ClapTrap p;
//     // ClapTrap v(p);
//     // v = p;
// 	ClapTrap a("sara");
// 	ClapTrap b("bob");
// 	b = a;
// 	a.attack("bob");
// 	a.takeDamage(2);
// 	a.beRepaired(2);

// // ClapTrap c("Sara");
// // c.attack("Bob");        // should work (EP=10 → 9, AD=0)
// // c.takeDamage(1);        // HP=10 → 5, print one message
// // c.beRepaired(3);        // HP=5 → 8, EP=9 → 8

// // c.takeDamage(10);       // HP=8 → 0 (not negative)
// // c.beRepaired(3); //no rebare after death
// // c.attack("Bob");        // should do nothing (HP=0)

// }



// #include "ClapTrap.hpp"

// int main()
// {
//     // === Test 1: Default constructor (OCF) ===
//     ClapTrap defaultBot;

//     // === Test 2: Parameterized constructor ===
//     ClapTrap c("Clappy");

//     // === Test 3: Copy constructor (OCF) ===
//     ClapTrap copyBot(c);

//     // === Test 4: Copy assignment operator (OCF) ===
//     ClapTrap assignBot;
//     assignBot = c;

//     // === Test 5: Normal behavior ===
//     std::cout << "\n--- Normal Actions ---\n";
//     c.attack("Target");
//     c.takeDamage(5);
//     c.beRepaired(3);

//     // === Test 6: After death (HP = 0) ===
//     std::cout << "\n--- After Death ---\n";
//     c.takeDamage(10);        // HP becomes 0
//     c.attack("Target");      // should do nothing
//     c.beRepaired(5);         // should do nothing

//     // === Test 7: Energy depletion (HP > 0, EP = 0) ===
//     std::cout << "\n--- Energy Depletion ---\n";
//     ClapTrap lowE("LowEnergy");
//     for (int i = 0; i < 10; ++i)
//         lowE.attack("Dummy");  // drains all 10 energy
//     lowE.beRepaired(5);        // should do nothing (no energy)
//     lowE.attack("Dummy");      // should do nothing

//     return 0;
// }


/*
 Object Creation — ClapTrap c("Sara");
What happens:

The parameterized constructor is called with "Sara".
Memory is allocated for one ClapTrap object.
Its private attributes are set:
Name = "Sara"
HitPoint = 10
EnergyPoint = 10
AttackDam = 0

[ ClapTrap "Sara" ]
│
├── Name: "Sara"
├── HitPoint: 10   ← alive!
├── EnergyPoint: 10
└── AttackDam: 0

////////////
 c.attack("Bob");
Checks:

Is HitPoint > 0? → Yes (10)
Is EnergyPoint > 0? → Yes (10)
Action:

EnergyPoint decreases by 1 → now 9
Prints:
ClapTrap Sara attacks Bob, causing 0 points of damage!

the new status:
[ ClapTrap "Sara" ]
│
├── HitPoint: 10
├── EnergyPoint: 9   ← used 1
└── AttackDam: 0
//////////
💥 Step 3: c.takeDamage(5);
Checks:

Is HitPoint > 0? → Yes (10) → proceed
Action:

Reduce HitPoint by 5 → 10 – 5 = 5
Prints:
ClapTrap Sara takes 5 points of damage!
🔸 Note: takeDamage does not use energy. It’s something done to the robot, not done by it. 

new status:
[ ClapTrap "Sara" ]
│
├── HitPoint: 5    ← hurt!
├── EnergyPoint: 9
└── AttackDam: 0
/////////////////
 c.beRepaired(3);
Checks:

HitPoint > 0? → Yes (5)
EnergyPoint > 0? → Yes (9)
Action:

Add 3 to HitPoint → 5 + 3 = 8
Decrease EnergyPoint by 1 → 8
Prints:
ClapTrap Sara is repaired and gains 3 hit points!
[ ClapTrap "Sara" ]
│
├── HitPoint: 8    ← healed!
├── EnergyPoint: 8
└── AttackDam: 0
/////////////////
💀 Step 5: c.takeDamage(10);
Checks:

HitPoint > 0? → Yes (8) → proceed
Action:

Reduce HitPoint by 10 → 8 – 10 = -2 → but HP can’t go below 0
So set HitPoint = 0
Prints:
ClapTrap Sara takes 10 points of damage!

[ ClapTrap "Sara" ]
│
├── HitPoint: 0    ← DESTROYED!
├── EnergyPoint: 8
└── AttackDam: 0

/////////////////

🚫 Step 6: c.attack("Bob"); (again)
Checks (inside attack function):

Is HitPoint > 0? → No (0) → ❌ Abort immediately
Do not check energy
Do not print anything
Do not change any values
✅ Silent failure — as required.

[ ClapTrap "Sara" ]
│
├── HitPoint: 0
├── EnergyPoint: 8
└── AttackDam: 0
////////
🔚 Step 7: End of main() → Destructor
Object c goes out of scope
~ClapTrap() is called
Prints: Destructor called
Memory is freed.
*/
//////////////////////////////////////////
/*
#include "ClapTrap.hpp"

int main()
{
    // === Test 1: Default constructor (OCF) ===
    ClapTrap defaultBot;
    
    // === Test 2: Parameterized constructor ===
    ClapTrap c("Sara");

    // === Test 3: Copy constructor (OCF) ===
    ClapTrap copyBot(c);

    // === Test 4: Copy assignment operator (OCF) ===
    ClapTrap assignBot;
    assignBot = c;

    // === Test 5: Normal behavior ===
    std::cout << "\n--- Normal Actions ---\n";
    c.attack("Bob");
    c.takeDamage(5);
    c.beRepaired(3);

    // === Test 6: Action when HP = 0 (should do nothing) ===
    std::cout << "\n--- After Death ---\n";
    c.takeDamage(10);        // HP becomes 0
    c.attack("Bob");         // should print nothing
    c.beRepaired(5);         // should print nothing

    // === Test 7: Action when EP = 0 but HP > 0 ===
    std::cout << "\n--- Energy Depletion Test ---\n";
    ClapTrap lowEnergy("LowE");
    // Drain energy
    for (int i = 0; i < 10; ++i)
        lowEnergy.attack("Dummy");
    // Now EP = 0, HP = 10
    lowEnergy.beRepaired(5); // should do nothing (no energy)
    lowEnergy.attack("Dummy"); // should do nothing

    // Destructors will auto-call at end of scope
    return 0;
}*/



/////////////////////////////////

#include "ClapTrap.hpp"

int main()
{
    ClapTrap c("Clappy");
    c.attack("Target");
    c.takeDamage(5);
    c.beRepaired(3);
    c.takeDamage(10); // HP = 0
    c.attack("Target"); // should do nothing
    return 0;
}

/*

ClapTrap parameterized constructor called
ClapTrap Clappy attacks Target, causing 0 points of damage!
ClapTrap Clappy takes 5 points of damage!
ClapTrap Clappy is repaired and gains 3 hit points!
ClapTrap Clappy takes 10 points of damage!
ClapTrap destructor called

*/