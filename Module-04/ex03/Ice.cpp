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

// clone() will return a new instance of the same type (i.e., if you clone an Ice Materia, you will get a new Ice Materia).
AMateria *Ice::clone() const
{
    // std::cout << "🧊 Ice clone called" << std::endl;
    return new Ice();
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

