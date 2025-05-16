#include "Intern.hpp"



Intern::Intern()
{
    std::cout << "👦 Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &other)
{
    (void) other;
}

Intern const& Intern::operator=(Intern const &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
    std::cout << "👦 Intern destructor called" << std::endl;
}

AForm *Intern::createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string const &name, std::string const &target)
{
    FormType forms[] = {
        {"shrubbery creation", &Intern::createShrubbery},
        {"robotomy request", &Intern::createRobotomy},
        {"presidential pardon", &Intern::createPresidential}
    };

    for (int i = 0; i < 3; ++i)
    {
        if (forms[i].name == name)
        {
            std::cout << "👦 Intern creates " << name << std::endl;
            return (this->*forms[i].createform)(target);
        }
    }
    throw FormNotFoundException();
}


const char* Intern::FormNotFoundException::what() const throw()
{
    return "👦 Intern: Form not found";
}