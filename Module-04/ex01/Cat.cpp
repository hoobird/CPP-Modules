#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "🐱 Cat default constructor called" << std::endl;
}
Cat::Cat(Cat const &other)
{
    *this = other;
    std::cout << "🐱 Cat copy constructor called" << std::endl;
}
Cat &Cat::operator=(Cat const &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout << "🐱 Cat assignment operator called" << std::endl;
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
