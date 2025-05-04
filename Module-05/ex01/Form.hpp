#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>

class Form 
{
    public:
        Form();
        Form(std::string name, int signGrade, int executeGrade);
        Form(Form const &other);
        Form &operator=(Form const &other);
        ~Form();

        const std::string getName();
        bool    getIsSigned();
        const int   getSignGrade();
        const int   getExecuteGrade();

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