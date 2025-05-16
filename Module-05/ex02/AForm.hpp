#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;
class AForm 
{
    public:
        AForm();
        AForm(std::string const &name, int signGrade, int executeGrade);
        AForm(AForm const &other);
        AForm &operator=(AForm const &other);
        ~AForm();

        const std::string getName() const;
        bool    getIsSigned() const;
        int   getSignGrade() const;
        int   getExecuteGrade() const;
 
        void    beSigned(const Bureaucrat &b);
        void    execute(Bureaucrat const &executor) const;
        virtual void    executeAction() const = 0;

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

        class FormNotSignedException : public std::exception
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

std::ostream &operator<<(std::ostream &o, const AForm &f);


#endif