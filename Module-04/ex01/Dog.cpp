#include "Dog.hpp"

Dog::Dog(): Animal()
{
    std::cout << "🐶+🧠 Dog default constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(Dog const &other): Animal(other)
{
    std::cout << "🐶+🧠 Dog copy constructor called" << std::endl;
    this->brain = new Brain();
}

Dog &Dog::operator=(Dog const &other)
{
    std::cout << "🐶+🧠 Dog assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
        if (this->brain)
            delete this->brain;
        this->brain = new Brain();
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "🐶+🧠 Dog destructor called" << std::endl;
    delete this->brain;
    this->brain = NULL;
}

void Dog::makeSound() const
{
    std::cout << "🐶+🧠 Woof" << std::endl;
}

void Dog::compareDog(Dog const &other) const
{
    std::cout << "\tthis 🐶🏠 @:  " << this << std::endl;
    std::cout << "\tother 🐶🏠 @: " << &other << std::endl;
    std::cout << "\tthis 🐶🧠 @:  " << this->brain << std::endl;
    std::cout << "\tother 🐶🧠 @: " << other.brain << std::endl;
}
