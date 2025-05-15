#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm()
{
    // privated
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("ShubberyCreationForm", 145, 137), target(target)
{
    std::cout << "📜 ShuForm constructed: " << this->target << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
    
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    
}

void RobotomyRequestForm::executed(Bureaucrat const &executor) const
{
    
}
