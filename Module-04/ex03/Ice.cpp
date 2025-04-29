#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    // std::cout << "🧊 Ice default constructor called" << std::endl;
}

Ice::Ice(Ice const &other) : AMateria(other)
{
    // std::cout << "🧊 Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(Ice const &other)
{
    // std::cout << "🧊 Ice assignment operator called but DOES NOTHING" << std::endl;
    (void) other;
    return *this;
}

Ice::~Ice()
{
    // std::cout << "🧊 Ice destructor called" << std::endl;
}

AMateria *Ice::clone() const
{
    // std::cout << "🧊 Ice clone called" << std::endl;
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

