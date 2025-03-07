#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->type = "ScavTrap";
    this->name = "Default ScavTrap";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    displayStatus("is constructed with default settings");
}


ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->type = "ScavTrap";
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    displayStatus("is constructed");
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    
}

ScavTrap::~ScavTrap()
{
    std::cout << this->type << " " << this->name << " destroyed." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        this->type = other.type;
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    displayStatus("is copy assigned");
    return *this;
}

// Guard Gate Mode
void ScavTrap::guardGate()
{
    if (this->hitPoints == 0)
    {
        std::cout << this->type << " " << this->name << " cannot enter Gate keeper mode as it is already destroyed!" << std::endl;
        return;
    }
    std::cout << this->type << " " << this->name << " is now in Gate keeper mode." << std::endl;
}
