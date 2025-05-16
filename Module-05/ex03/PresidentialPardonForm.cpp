#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
    // privated
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "📜🏛 PresidentialPardonForm constructed: " << this->target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other), target(other.target)
{
    std::cout << "📜🏛 PresidentialPardonForm copy constructor called: " << this->target << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
    if (this != &other) {
        AForm::operator=(other);
    }
    std::cout << "📜🏛 PresidentialPardonForm copy assignment called: " << this->target << std::endl;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "📜🏛 PresidentialPardonForm destructor called: " << this->target << std::endl;
}

void PresidentialPardonForm::executeAction() const
{
    std::cout << "📜🏛 " << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
