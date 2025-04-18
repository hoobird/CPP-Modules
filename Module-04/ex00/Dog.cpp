#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "🐶 Dog default constructor called" << std::endl;
}
Dog::Dog(Dog const &other)
{
    *this = other;
    std::cout << "🐶 Dog copy constructor called" << std::endl;
}
Dog &Dog::operator=(Dog const &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout << "🐶 Dog assignment operator called" << std::endl;
    return *this;
}
Dog::~Dog()
{
    std::cout << "🐶 Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "🐶 Woof" << std::endl;
}
