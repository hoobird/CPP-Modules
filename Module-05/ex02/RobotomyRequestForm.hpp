#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H


#include "AForm.hpp"

class RobotomyRequestForm : public AForm 
{
    public:
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
        ~RobotomyRequestForm();

        void	executed(Bureaucrat const &executor) const;
        
    
    private:
        RobotomyRequestForm();
        const std::string target;
        
};

#endif