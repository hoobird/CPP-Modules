#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void diamondTest();

int main(void)
{
    diamondTest();
    return 0;
}

void diamondTest()
{
    std::cout << "Testing DiamondTrap" << std::endl;

    // Test default, copy constructors
    std::cout << "\n(Testing constructors)\n" << std::endl;
    DiamondTrap dDiamondTrap;
    DiamondTrap diamondTrap("diamond1");
    DiamondTrap cDiamondTrap(diamondTrap);
    
    std::cout << "---" << std::endl;

    // Test assignment
    std::cout << "\n(Testing Assignment)\n" << std::endl;
    DiamondTrap assignTrap;
    assignTrap = diamondTrap;

    std::cout << "---" << std::endl;

    // Test attack (inherited from ScavTrap) Damage should be 30
    std::cout << "\n(Testing Attack inherited from ScavTrap)\n" << std::endl;
    diamondTrap.attack("Handsome Jack");

    std::cout << "---" << std::endl;

    // Test whoAmI
    std::cout << "\n(Testing whoAmI)\n" << std::endl;
    diamondTrap.whoAmI();

    std::cout << "---" << std::endl;

    // Test inherited ScavTrap guradGate()
    std::cout << "\n(Testing guardGate from ScavTrap)\n" << std::endl;
    diamondTrap.guardGate();
    return ;
    std::cout << "---" << std::endl;

    // Test inherited FragTrap function
    std::cout << "\n(Testing highFive from FragTrap)\n" << std::endl;
    diamondTrap.highFivesGuys();

    std::cout << "---" << std::endl;

    // Test damage taking and death
    std::cout << "\n(Testing Damage & Death)\n" << std::endl;
    DiamondTrap damageTrap("SuicidalClap");
    damageTrap.takeDamage(50);  // 50 hp left
    damageTrap.takeDamage(50);  // die 0 hp
    damageTrap.attack("Enemy"); // Should fail due to death
    damageTrap.whoAmI();        // Should fail due to death
    damageTrap.guardGate();     // Should fail due to death
    damageTrap.highFivesGuys(); // Should fail due to death

    std::cout << "---\n" << std::endl;
}
