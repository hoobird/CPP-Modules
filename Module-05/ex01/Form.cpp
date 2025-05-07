#include "Form.hpp"

Form::Form(): name("default form"), isSigned(false), signGrade(1), executeGrade(1) 
{
    std::cout << "📜 Default Form created: " << this->name << ", sign grade " << this->signGrade << ", execute grade " << this->executeGrade << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade): name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade) 
{
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
    std::cout << "📜 Form created: " << this->name << ", sign grade " << this->signGrade << ", execute grade " << this->executeGrade << std::endl;
}

Form::Form(Form const &other): name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade)
{
    std::cout << "📜 Form copy constructor called: " << this->name << ", isSigned " << this->isSigned << ", sign grade " << this->signGrade << ", execute grade " << this->executeGrade << std::endl;
}

Form &Form::operator=(Form const &other)
{
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}

Form::~Form() 
{
    std::cout << "📜 Form copy destructor called: "<< this->name << std::endl;
}

const std::string Form::getName() const
{
    return this->name;
}

bool Form::getIsSigned() const
{
    return this->isSigned;
}

const int Form::getSignGrade() const
{
    return this->signGrade;
}

const int Form::getExecuteGrade() const
{
    return this->executeGrade;
}

void Form::beSigned(Bureaucrat &b)
{
    if ()
}

std::ostream &operator<<(std::ostream &o, const Form &f) 
{
    o << f.getName() << ", isSigned " << f.getIsSigned() << ", sign grade " << f.getSignGrade() << ", execute grade " << f.getExecuteGrade() << ".";
    return o;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "⚠️  Grade too high, 1 is the upper limit";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "⚠️  Grade too low, 150 is the lower limit";
}

