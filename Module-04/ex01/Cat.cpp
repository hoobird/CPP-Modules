#include "Cat.hpp"

Cat::Cat(): Animal()
{
    std::cout << "🐱+🧠 Cat default constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(Cat const &other): Animal(other)
{
    std::cout << "🐱+🧠 Cat copy constructor called" << std::endl;
    this->brain = new Brain();
}

Cat &Cat::operator=(Cat const &other)
{
    std::cout << "🐱+🧠 Cat assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
        if (this->brain)
            delete this->brain;
        this->brain = new Brain();
    }
    compareCat(other); // To prove that no shallow copy occurs
    return *this;
}

Cat::~Cat()
{
    std::cout << "🐱+🧠 Cat destructor called" << std::endl;
    delete this->brain;
    this->brain = NULL;
}

void Cat::makeSound() const
{
    std::cout << "🐱+🧠 Meow" << std::endl;
}

void Cat::compareCat(Cat const &other) const
{
    std::cout << "\tthis 🐱🏠 @:  " << this << std::endl;
    std::cout << "\tother 🐱🏠 @: " << &other << std::endl;
    std::cout << "\tthis 🐱🧠 @:  " << this->brain << std::endl;
    std::cout << "\tother 🐱🧠 @: " << other.brain << std::endl;
}