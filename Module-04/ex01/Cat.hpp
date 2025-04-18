#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(Cat const &other);
        Cat & operator=(Cat const &other);
        ~Cat();

        void makeSound() const;
        void compareCat(Cat const &other) const;

    private:
        Brain *brain;

};

#endif 