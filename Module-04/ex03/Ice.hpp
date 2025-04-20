#ifndef ICE_HPP
# define ICE_HPP

#include "ICharacter.hpp"
#include <iostream>

class Ice : public AMateria
{
    public:
        Ice();
        Ice(Ice const &other);
        Ice &operator=(Ice const &other);
        ~Ice();

        AMateria *clone() const;
        void use(ICharacter &target);
};

#endif