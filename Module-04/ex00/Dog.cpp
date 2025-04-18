#include "Dog.hpp"

Dog::Dog(): Animal()
{
    std::cout << "🐶 Dog default constructor called" << std::endl;
    this->type = "Dog";
}
Dog::Dog(Dog const &other): Animal(other)
{
    std::cout << "🐶 Dog copy constructor called" << std::endl;
    *this = other;
}
Dog &Dog::operator=(Dog const &other)
{
    std::cout << "🐶 Dog assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
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
