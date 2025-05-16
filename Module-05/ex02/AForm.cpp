#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name("default"), isSigned(false), signGrade(1), executeGrade(1) 
{
    std::cout << "📜 Default Form constructed: " << this->name << std::endl;
}

AForm::AForm(std::string const &name, int signGrade, int executeGrade): name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade) 
{
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
    std::cout << "📜 Form constructed: " << this->name << std::endl;
}

AForm::AForm(AForm const &other): name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade)
{
    std::cout << "📜 Form copy constructor called: " << this->name << std::endl;
}

AForm &AForm::operator=(AForm const &other)
{
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    std::cout << "📜 Form copy assignment called: " << this->name << std::endl;
    return *this;
}

AForm::~AForm() 
{
    std::cout << "📜 Form copy destructor called: "<< this->name << std::endl;
}

const std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getIsSigned() const
{
    return this->isSigned;
}

int AForm::getSignGrade() const
{
    return this->signGrade;
}

int AForm::getExecuteGrade() const
{
    return this->executeGrade;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > this->signGrade)
        throw GradeTooLowException();
    this->isSigned = true;
    std::cout << "📜 Form signed by " << b.getName() << std::endl;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();
    this->executeAction();
}

std::ostream &operator<<(std::ostream &o, const AForm &f) 
{
    o << "📜ℹ️  " << f.getName() << ", isSigned: " << f.getIsSigned() << ", sign grade: " << f.getSignGrade() << ", execute grade: " << f.getExecuteGrade() << ".";
    return o;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "⚠️  Grade too high, 1 is the upper limit";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "⚠️  Grade too low, 150 is the lower limit";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "⚠️  Form is not signed, unable to execute";
}
