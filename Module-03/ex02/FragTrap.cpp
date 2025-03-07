#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->type = "FragTrap";
    this->name = "Default FragTrap";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    displayStatus("is constructed with default settings");
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->type = "FragTrap";
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    displayStatus("is constructed");
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    
}

FragTrap &FragTrap::operator=(const FragTrap &other)
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

FragTrap::~FragTrap()
{
    std::cout << this->type << " " << this->name << " destroyed." << std::endl;
}


void FragTrap::highFivesGuys()
{
    if (this->hitPoints == 0)
    {
        std::cout << this->type << " " << this->name << " cannot high five as it is already destroyed!" << std::endl;
        return;
    }
    std::cout << this->type << " " << this->name << " is requesting a high five!" << std::endl;
}