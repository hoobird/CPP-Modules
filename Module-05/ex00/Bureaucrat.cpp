#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(150)
{
    std::cout << "🎩 Default Bureaucrat constructed: " << name << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    std::cout << "🎩 Bureaucrat constructed: " << name << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other): name(other.name), grade(other.grade)
{
    std::cout << "🎩 Bureaucrat copy constructor called: " << name << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    if (this != &other) {
        // name is const, copier will keep his name
        this->grade = other.grade;
    }
    std::cout << "🎩 Bureaucrat copy assignment called: " << name << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "🎩 Bureaucrat destroyed: " << name << std::endl;
}

const std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::incrementGrade()
{
    if (this->grade <= 1)
        throw GradeTooHighException();
    --grade;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade >= 150)
        throw GradeTooLowException();
    ++grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "⚠️  Grade too high, 1 is the upper limit";
}


const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "⚠️  Grade too low, 150 is the lower limit";
}

std::ostream    &operator<<(std::ostream &o, const Bureaucrat &b)
{
    o << "🎩ℹ️  " << b.getName() << ", bureaucrat grade " << b.getGrade() << "." ;
    return o;
}