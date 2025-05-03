#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat {
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(Bureaucrat const &other);
        Bureaucrat &operator=(Bureaucrat const &other);
        ~Bureaucrat();

        const std::string   getName() const;
        int           getGrade() const;

    private:
        const std::string name;
        int         grade;
};

std::ostream    &operator<<(std::ostream &o, Bureaucrat *b);

#endif