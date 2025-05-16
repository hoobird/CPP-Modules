#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H


#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm 
{
    public:
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
        ~RobotomyRequestForm();

        void	executeAction() const;
        
    private:
        RobotomyRequestForm();
        const std::string target;
        
};

#endif