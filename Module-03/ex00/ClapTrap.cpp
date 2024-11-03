# include "ClapTrap.hpp"


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

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap copy constructor is called" << std::endl;
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
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
    std::cout << "ClapTrap is destructed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    target.takeDamage(this->attackDamage);
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
    this->hitPoints -= amount;
    
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap " << this->name << " is repaired by " << amount << " points!" << std::endl;
    this->hitPoints += amount;
}
