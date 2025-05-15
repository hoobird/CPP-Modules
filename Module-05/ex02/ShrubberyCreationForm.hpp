#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H


#include "AForm.hpp"

class ShruberryCreationForm : public AForm 
{
    public:
        ShruberryCreationForm(const std::string &target);
        ShruberryCreationForm &operator=(ShruberryCreationForm const &other);
        ~ShruberryCreationForm();

        void	executed(Bureaucrat const &executor) const;
        
    
    private:
        ShruberryCreationForm();
        const std::string target;
        
};


#endif