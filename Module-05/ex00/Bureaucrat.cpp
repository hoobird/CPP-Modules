#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(150)
{
    std::cout << "🧑‍💼 Default Bureaucrat created "<< this << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(grade)
{
    std::cout << "🧑‍💼 Bureaucrat created " << this << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
    std::cout << "🧑‍💼 Bureaucrat copy constructor called on " << this << std::endl;

}


Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    if (this != &other) {
        this->name = other.name;
        this->grade = other.grade;

    }
}

Bureaucrat::~Bureaucrat()
{

}

std::ostream    &operator<<(std::ostream &o, Bureaucrat *b)
{
    o << b->getName() << ", bureaucrat grade " << b->getGrade() << "." ;
    
    return o;
}