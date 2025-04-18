#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "🐯 WrongCat default constructor called" << std::endl;
}
WrongCat::WrongCat(WrongCat const &other)
{
    *this = other;
    std::cout << "🐯 WrongCat copy constructor called" << std::endl;
}
WrongCat &WrongCat::operator=(WrongCat const &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout << "🐯 WrongCat assignment operator called" << std::endl;
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
