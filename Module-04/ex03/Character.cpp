#include "Character.hpp"

Character::Character() : name("NAMELESS")
{
    std::cout << "👤 Character default constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        inventory[i] = NULL;
}

Character::Character(std::string const &name) : name(name)
{
    std::cout << "👤 Character constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        inventory[i] = NULL;
}

Character::Character(Character const &other)
{
    std::cout << "👤 Character copy constructor called" << std::endl;
    *this = other;
}




