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
    if
}
