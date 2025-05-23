#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;
class Form 
{
    public:
        Form();
        Form(std::string const &name, int signGrade, int executeGrade);
        Form(Form const &other);
        Form &operator=(Form const &other);
        ~Form();

        const std::string getName() const;
        bool    getIsSigned() const;
        int   getSignGrade() const;
        int   getExecuteGrade() const;
 
        void    beSigned(const Bureaucrat &b);

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };

    private:
        const std::string name;
        bool isSigned;
        const int   signGrade;
        const int   executeGrade;
};

std::ostream &operator<<(std::ostream &o, const Form &f);


#endif