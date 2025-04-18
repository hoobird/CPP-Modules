#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "🅰️  Animal default constructor called" << std::endl;
    this->type = "Animal";
}

Animal::Animal(Animal const &other)
{
    std::cout << "🅰️  Animal copy constructor called" << std::endl;
    *this = other;
}

Animal &Animal::operator=(Animal const &other)
{
    std::cout << "🅰️  Animal assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
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