#include "DiamondTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    this->type = "DiamondTrap";
    this->name = "Default DiamondTrap";
    ClapTrap::name = "Default DiamondTrap_clap_name"; // Even though there is no parameter, i set this for the sake of consistency
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    displayStatus("is constructed with default settings");
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    this->type = "DiamondTrap";
    this->name = name;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    displayStatus("is constructed");
    std::cout << this->type << " " << this->name << " is constructed with ClapTrap name: " << ClapTrap::name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    this->name = other.name;
    displayStatus("is copy constructed");
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->name = other.name;
    }
    displayStatus("is copy assigned");
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->name << " is destructed" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    if (this->hitPoints == 0)
    {
        std::cout << this->type << " " << this->name << " cannot identify itself as it is already destroyed!" << std::endl;
        return;
    }
    
    std::cout << "My Diamond name is " << this->name << " and my Clap name is " << ClapTrap::name << "!" << std::endl;
}