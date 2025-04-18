#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "⚕️ Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const &other) : AMateria(other)
{
    std::cout << "⚕️ Cure copy constructor called" << std::endl;
    *this = other;
}

Cure &Cure::operator=(Cure const &other)
{
    std::cout << "⚕️ Cure assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Cure::~Cure()
{
    std::cout << "⚕️ Cure destructor called" << std::endl;
}

AMateria *Cure::clone() const
{
    std::cout << "⚕️ Cure clone called" << std::endl;
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}