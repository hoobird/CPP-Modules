#ifndef WrongCat_HPP
# define WrongCat_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(WrongCat const & src);
        WrongCat & operator=(WrongCat const & other);
        ~WrongCat();

        void makeSound() const;

};

#endif 