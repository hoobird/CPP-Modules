#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "🐯 WrongCat default constructor called" << std::endl;
    this->type = "WrongCat";
}
WrongCat::WrongCat(WrongCat const &other)
{
    std::cout << "🐯 WrongCat copy constructor called" << std::endl;
    *this = other;
}
WrongCat &WrongCat::operator=(WrongCat const &other)
{
    std::cout << "🐯 WrongCat assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}
WrongCat::~WrongCat()
{
    std::cout << "🐯 WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "🐯 Rawr" << std::endl;
}
