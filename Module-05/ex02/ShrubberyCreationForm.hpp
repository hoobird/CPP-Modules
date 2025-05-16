#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H


#include "AForm.hpp"
#include <fstream>
class ShrubberyCreationForm : public AForm 
{
    public:
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
        ~ShrubberyCreationForm();
        
        void	executeAction() const;

        class FileOpenException : public std::exception
        {
            public:
                const char* what() const throw();
        };

    private:
        ShrubberyCreationForm();
        const std::string target;
        
};


#endif