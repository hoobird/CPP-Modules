#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
    std::cout << "👹 WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
    std::cout << "👹 WrongAnimal copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
    std::cout << "👹 WrongAnimal assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "👹 WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "👹 WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}