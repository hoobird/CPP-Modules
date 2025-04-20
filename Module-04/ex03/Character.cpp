#include "Character.hpp"

Character::Character() : name("NAMELESS")
{
    // std::cout << "🧑 Character default constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        inventory[i] = NULL;
}

Character::Character(std::string const &name) : name(name)
{
    // std::cout << "🧑 Character constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        inventory[i] = NULL;
}

Character::Character(Character const &other): name(other.name)
{
    // std::cout << "🧑 Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        inventory[i] = NULL;
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();           
    }
}

Character &Character::operator=(Character const &other)
{
    // std::cout << "🧑 Character assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        for (int i = 0; i < 4; ++i)
        {
            delete inventory[i];
            inventory[i] = NULL;
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
        }
    }
    return *this;
}

Character::~Character()
{
    // std::cout << "🧑 Character destructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        if (inventory[i])
        {
            delete inventory[i];
            inventory[i] = NULL;
        }
    }
}

std::string const &Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            std::cout << "🧑 " << this->name << " equipped " << m->getType() << std::endl;
            return;
        }
    }
    std::cout << "🧑 " << this->name << "'s inventory is full" << std::endl;
}

void Character::unequip(int index)
{
    if (index < 0 || index >= 4)
    {
        std::cout << "🧑 " << this->name << ": Invalid Index " << index << std::endl;
        return;
    }
    if (!inventory[index])
    {
        std::cout << "🧑 " << this->name << ": Nothing in inventory slot " << index << std::endl;
        return;
    }
    std::cout << "🧑 " << this->name << " unequipped " << inventory[index]->getType() << std::endl;
    delete inventory[index];
    inventory[index] = NULL;
}

void Character::use(int index, ICharacter& target)
{
    if (index < 0 || index >= 4)
    {
        std::cout << "🧑 " << this->name << ": Invalid Index " << index << std::endl;
        return;
    }
    if (!inventory[index])
    {
        std::cout << "🧑 " << this->name << ": Nothing in inventory slot " << index << std::endl;
        return;
    }
    inventory[index]->use(target);
}