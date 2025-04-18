#include "Animal.hpp"

Animal::Animal()
{
    this->type = "Animal";
    std::cout << "🅰️  Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const &other)
{
    *this = other;
    std::cout << "🅰️  Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout << "🅰️  Animal assignment operator called" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "🅰️  Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "🅰️  Animal sound" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}