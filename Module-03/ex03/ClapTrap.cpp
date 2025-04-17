#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->type = "ClapTrap";
    this->name = "Default ClapTrap";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    displayStatus("is constructed with default settings");
}

ClapTrap::ClapTrap(std::string name)
{
    this->type = "ClapTrap";
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    displayStatus("is constructed");
}

ClapTrap::ClapTrap(const ClapTrap &other):
    type(other.type),
    name(other.name),
    hitPoints(other.hitPoints), 
    energyPoints(other.energyPoints), 
    attackDamage(other.attackDamage)
{
    displayStatus("is copy constructed");
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other) {
        this->type = other.type;
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    displayStatus("is copy assigned");
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name <<" is destructed" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->hitPoints == 0) {
        displayStatus("cannot attack as it is already destroyed!");
        return;
    }
    if (this->energyPoints == 0) {
        displayStatus("has run out of energy points!");
        return;
    }
    this->energyPoints -= 1;
    std::cout << this->type << " " << this->name << " attacks " << target << " for " 
              << this->attackDamage << " damage!";
    displayStatus("");
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints == 0) {
        displayStatus("cannot take more damage as it is already destroyed!");
        return;
    }
    if (amount >= this->hitPoints) {
        this->hitPoints = 0;
        displayStatus("has been destroyed!");
        return;
    }
    this->hitPoints -= amount;
    std::cout << this->type << " " << this->name << " takes " << amount << " damage!";
    displayStatus("");
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energyPoints == 0) {
        displayStatus("cannot be repaired due to lack of energy!");
        return;
    }
    if (this->hitPoints == 0) {
        displayStatus("cannot be repaired as it is already destroyed!");
        return;
    }
    this->energyPoints -= 1;
    this->hitPoints += amount;
    std::cout << this->type << " " << this->name << " healed up by " << amount << " HP!";
    displayStatus("");
}

// Display the status of ClapTrap HP and EP
void ClapTrap::displayStatus(const std::string& action) const
{
    if (!action.empty())
       std::cout << this->type << " " << this->name << " ";
    std::cout << action << " [HP: " << this->hitPoints << ", EP: " << this->energyPoints << "]" << std::endl;
}
