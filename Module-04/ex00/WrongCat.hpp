#ifndef WrongCat_HPP
# define WrongCat_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(WrongCat const &other);
        ~WrongCat();
        WrongCat & operator=(WrongCat const &other);

        void makeSound() const;

};

#endif 