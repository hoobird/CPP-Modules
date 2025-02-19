#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap is constructed with default settings" << std::endl;
    this->name = "Default";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap is constructed" << std::endl;
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other):
    name(other.name),
    hitPoints(other.hitPoints), 
    energyPoints(other.energyPoints), 
    attackDamage(other.attackDamage)
{
    std::cout << "ClapTrap copy constructor is called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap assignment operator is called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name <<" is destructed" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->hitPoints == 0) {
        std::cout << "ClapTrap " << this->name << " cannot attack as it is already destroyed! (0 HP)" << std::endl;
        return;
    }
    if (this->energyPoints == 0) {
        std::cout << "ClapTrap " << this->name << " has run out of energy points! :(" << std::endl;
        return;
    }
    this->energyPoints -= 1;
    std::cout << "ClapTrap " << this->name << " attacks " << target << " for " << this->attackDamage << " damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints == 0) {
        std::cout << "ClapTrap " << this->name << " cannot take more damage as it is already destroyed! (0 HP)" << std::endl;
        return;
    }
    if (amount >= this->hitPoints) {
        std::cout << "ClapTrap " << this->name << " takes " << amount << " damage and has been destroyed! (0 HP remaining)" << std::endl;
        this->hitPoints = 0;
        return;
    }
    this->hitPoints -= amount;
    std::cout << "ClapTrap " << this->name << " takes " << amount << " damage! (" << this->hitPoints << " HP remaining)" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energyPoints == 0) {
        std::cout << "ClapTrap " << this->name << " cannot be repaired due to lack of energy!" << std::endl;
        return;
    }
    if (this->hitPoints == 0) {
        std::cout << "ClapTrap " << this->name << " cannot be repaired as it is already destroyed!" << std::endl;
        return;
    }
    this->energyPoints -= 1;
    this->hitPoints += amount;
    std::cout << "ClapTrap " << this->name << " healed up by " << amount << " HP! (" << this->hitPoints << " HP now)" << std::endl;
}
