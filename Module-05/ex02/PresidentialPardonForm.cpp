#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
    // privated
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("ShubberyCreationForm", 145, 137), target(target)
{
    std::cout << "📜 ShuForm constructed: " << this->target << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
    
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    
}

void PresidentialPardonForm::executed(Bureaucrat const &executor) const
{
    
}

