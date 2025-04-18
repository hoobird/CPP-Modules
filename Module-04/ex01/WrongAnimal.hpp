#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(WrongAnimal const & src);
        WrongAnimal & operator=(WrongAnimal const & other);
        virtual ~WrongAnimal();

        void makeSound() const;
        std::string getType() const;

    protected:
        std::string type;
};

#endif 