#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm()
{
    // privated
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "📜🤖 RobotomyRequestForm constructed: " << this->target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), target(other.target)
{
    std::cout << "📜🤖 RobotomyRequestForm copy constructed: " << this->target << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
    if (this != &other) {
        AForm::operator=(other);
    }
    std::cout << "📜🤖 RobotomyRequestForm copy assignment called: " << this->target << std::endl;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "📜🤖 RobotomyRequestForm destructor called: " << this->target << std::endl;
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "🚧 drill noises intensifies: brr brr brr brr 🚧" << std::endl;
    if (rand() % 2 == 0)
        std::cout << "📜🤖 " << this->target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "📜🤖 " << this->target << " robotomy failed" << std::endl;
}
