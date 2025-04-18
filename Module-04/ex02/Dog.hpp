#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(Dog const &other);
        Dog & operator=(Dog const & other);
        ~Dog();

        void makeSound() const;
        void compareDog(Dog const &other) const;

    private:
        Brain *brain;

};

#endif 