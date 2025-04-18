#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void clapTest();
void scavTest();

int main(void)
{
    // clapTest();
    scavTest();
    return 0;
}

void clapTest()
{
    std::cout << "Testing ClapTrap" << std::endl;

    // Test default, copy constructors
    std::cout << "\n(Testing constructors)\n" << std::endl;
    ClapTrap dClaptrap;
    ClapTrap claptrap("clap1");
    ClapTrap cClaptrap(claptrap);

    std::cout << "---" << std::endl;

    // Test assignment
    std::cout << "\n(Testing Assignment)\n" << std::endl;
    ClapTrap assignTrap;
    assignTrap = claptrap;

    std::cout << "---" << std::endl;

    // Test attack and energy points depletion
    std::cout << "\n(Testing Attack & Energy Points)\n" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        claptrap.attack("Handsome Jack");
    }
    claptrap.attack("Handsome Jack"); // Should fail due to no energy

    std::cout << "---" << std::endl;

    // Test damage taking and death
    std::cout << "\n(Testing Damage & Death)\n" << std::endl;
    ClapTrap damageTrap("clap2");
    damageTrap.takeDamage(5);  // 5 hp left
    damageTrap.takeDamage(5);  // die 0 hp
    damageTrap.takeDamage(5);  // already dead bro
    damageTrap.attack("Skag"); // fail due to death
    damageTrap.beRepaired(5);  // fail due to death

    std::cout << "---" << std::endl;

    // Test repair functionality
    std::cout << "\n(Testing Repair)\n" << std::endl;
    ClapTrap repairTrap("clap3");
    repairTrap.takeDamage(5); // 5hp left
    repairTrap.beRepaired(2); // 7 hp
    repairTrap.beRepaired(3); // 10hp

    std::cout << "---" << std::endl;

    // Test energy point depletion with repairs
    std::cout << "\n(Testing Repairs when no more energy)\n" << std::endl;
    ClapTrap energyTrap("clap4");
    for (int i = 0; i < 10; i++)
    {
        energyTrap.beRepaired(1);
    }
    energyTrap.beRepaired(1); // Should fail due to no energy

    std::cout << "---\n" << std::endl;
}

void scavTest()
{
    std::cout << "Testing ScavTrap" << std::endl;

    // Test default, copy constructors
    std::cout << "\n(Testing constructors)\n" << std::endl;
    ScavTrap dScavtrap;
    ScavTrap scavtrap("scav1");
    ScavTrap cScavtrap(scavtrap);

    std::cout << "---" << std::endl;

    // Test assignment
    std::cout << "\n(Testing Assignment)\n" << std::endl;
    ScavTrap assignTrap;
    assignTrap = scavtrap;

    std::cout << "---" << std::endl;

    // Test attack and energy points depletion
    std::cout << "\n(Testing Attack & Energy Points)\n" << std::endl;
    for (int i = 0; i < 50; i++)
    {
        scavtrap.attack("Handsome Jack");
    }
    scavtrap.attack("Handsome Jack"); // Should fail due to no energy

    std::cout << "---" << std::endl;

    // Test damage taking and death
    std::cout << "\n(Testing Damage & Death)\n" << std::endl;
    ScavTrap damageTrap("scav2");
    damageTrap.takeDamage(50);  // 50 hp left
    damageTrap.takeDamage(50);  // die 0 hp
    damageTrap.takeDamage(50);  // already dead bro

    std::cout << "---" << std::endl;

    // Test repair functionality
    std::cout << "\n(Testing Repair)\n" << std::endl;
    ScavTrap repairTrap("scav3");
    repairTrap.takeDamage(50); // 50hp left
    repairTrap.beRepaired(20); // 70 hp
    repairTrap.beRepaired(30); // 100hp
    repairTrap.beRepaired(20); // 100hp

    std::cout << "---" << std::endl;

    // Test energy point depletion with repairs
    std::cout << "\n(Testing Repairs when no more energy)\n" << std::endl;
    ScavTrap energyTrap("scav4");
    for (int i = 0; i < 50; i++)
    {
        energyTrap.beRepaired(1);
    }
    energyTrap.beRepaired(1); // Should fail due to no energy
    std::cout << "---\n" << std::endl;

    // Test guard gate mode
    std::cout << "\n(Testing Guard Gate Mode)\n" << std::endl;
    ScavTrap guardTrap("scav5");
    guardTrap.guardGate(); // Should enter gate keeper mode
    guardTrap.takeDamage(100); // 0hp left, die
    guardTrap.guardGate(); // Should fail due to death

    std::cout << "---\n" << std::endl;
    

}
