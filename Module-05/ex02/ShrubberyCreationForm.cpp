#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm()
{
    // privated
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShubberyCreationForm", 145, 137), target(target)
{
    std::cout << "📜 ShuForm constructed: " << this->target << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
    
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    
}

void ShrubberyCreationForm::executed(Bureaucrat const &executor) const
{
    
}
