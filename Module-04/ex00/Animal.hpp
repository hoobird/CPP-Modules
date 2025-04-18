#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
    public:
        Animal();
        Animal(Animal const & src);
        virtual ~Animal();
        Animal & operator=(Animal const & other);

        virtual void makeSound() const;
        virtual std::string getType() const;

    protected:
        std::string type;
};

#endif 