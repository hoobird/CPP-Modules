#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(WrongAnimal const &other);
        virtual ~WrongAnimal();
        WrongAnimal & operator=(WrongAnimal const & other);

        void makeSound() const;
        std::string getType() const;

    protected:
        std::string type;
};

#endif 