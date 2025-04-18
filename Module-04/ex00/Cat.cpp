#include "Cat.hpp"

Cat::Cat(): Animal()
{
    std::cout << "🐱 Cat default constructor called" << std::endl;
    this->type = "Cat";
}
Cat::Cat(Cat const &other): Animal(other)
{
    std::cout << "🐱 Cat copy constructor called" << std::endl;
    *this = other;
}
Cat &Cat::operator=(Cat const &other)
{
    std::cout << "🐱 Cat assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}
Cat::~Cat()
{
    std::cout << "🐱 Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "🐱 Meow" << std::endl;
}
