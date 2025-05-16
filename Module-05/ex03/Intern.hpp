#ifndef INTERN_H
#define INTERN_H

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
    Intern(void);
    Intern(Intern const &copy);
    Intern const &operator=(Intern const &copy);
    ~Intern(void);

    AForm* makeForm(std::string const &name, std::string const &target);

    class FormNotFoundException : public std::exception
    {
    public:
        const char *what() const throw();
    };

private:
    struct FormType
    {
        std::string name;
        AForm* (Intern::*createform)(std::string const &target);
    };

    AForm* createShrubbery(const std::string &target);
    AForm* createRobotomy(const std::string &target);
    AForm* createPresidential(const std::string &target);
};

#endif