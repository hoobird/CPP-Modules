#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm 
{
    public:
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
        ~PresidentialPardonForm();

        void	executed(Bureaucrat const &executor) const;
        
    
    private:
        PresidentialPardonForm();
        const std::string target;
        
};

#endif