#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
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
    for (int i = 0; i < 11; i++) {
        claptrap.attack("Handsome Jack");
    }

    std::cout << "---" << std::endl;

    // Test damage taking and death
    std::cout << "\n(Testing Damage & Death)\n" << std::endl;
    ClapTrap damage_trap("clap2");
    damage_trap.takeDamage(5);    // 5 hp left
    damage_trap.takeDamage(5);    // die 0 hp
    damage_trap.takeDamage(5);    // already dead bro
    damage_trap.attack("Skag");  // fail due to death
    damage_trap.beRepaired(5);    // fail due to death

    std::cout << "---" << std::endl;

    // Test repair functionality
    std::cout << "\n(Testing Repair)\n" << std::endl;
    ClapTrap repair_trap("clap3");
    repair_trap.takeDamage(5);    // 5hp left
    repair_trap.beRepaired(2);    // 7 hp
    repair_trap.beRepaired(3);    // 10hp

    std::cout << "---" << std::endl;

    // Test energy point depletion with repairs
    std::cout << "\n(Testing Repairs when no more energy)\n" << std::endl;
    ClapTrap energy_trap("clap4");
    for (int i = 0; i < 10; i++) {
        energy_trap.beRepaired(1);
    }
    energy_trap.beRepaired(1);    // Should fail due to no energy

    std::cout << "---\n" << std::endl;

    return 0;
}