#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "🧊 Ice default constructor called" << std::endl;
}

Ice::Ice(Ice const &other) : AMateria(other)
{
    std::cout << "🧊 Ice copy constructor called" << std::endl;
    *this = other;
}

Ice &Ice::operator=(Ice const &other)
{
    std::cout << "🧊 Ice assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Ice::~Ice()
{
    std::cout << "🧊 Ice destructor called" << std::endl;
}

AMateria *Ice::clone() const
{
    std::cout << "🧊 Ice clone called" << std::endl;
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

