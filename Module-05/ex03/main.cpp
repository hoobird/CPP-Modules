#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib> // for srand
#include <ctime> // for time

int main() {
    // Seed random number generator for RobotomyRequestForm
    srand(time(NULL));
    
    std::cout << "\n==== TESTING INTERN FORM CREATION ====\n" << std::endl;
    
    Intern chaoIntern;
    AForm* form;
    Bureaucrat boss("CEO", 1);
    
    // Test successful form creation cases
    std::cout << "\n-- Creating shrubbery creation form --" << std::endl;
    try {
        form = chaoIntern.makeForm("shrubbery creation", "garden");
        std::cout << *form << std::endl;
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form; // Clean up allocated memory
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n-- Creating robotomy request form --" << std::endl;
    try {
        form = chaoIntern.makeForm("robotomy request", "subject");
        std::cout << *form << std::endl;
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form; // Clean up allocated memory
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n-- Creating presidential pardon form --" << std::endl;
    try {
        form = chaoIntern.makeForm("presidential pardon", "criminal");
        std::cout << *form << std::endl;
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form; // Clean up allocated memory
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test error cases
    std::cout << "\n-- Testing with invalid form name --" << std::endl;
    try {
        form = chaoIntern.makeForm("intern conversion", "poor intern");
        if (form) { // This should not execute
            std::cout << "fail liao" << std::endl;
            delete form;
        }
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n-- Testing with empty form name --" << std::endl;
    try {
        form = chaoIntern.makeForm("", "empty");
        if (form) { // This should not execute
            std::cout << "fail liao" << std::endl;
            delete form;
        }
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n==== TESTING MULTIPLE INTERNS ====\n" << std::endl;
    
    // Test creating multiple interns and forms
    Intern intern1;
    Intern intern2;
    
    std::cout << "\n-- Different interns creating different forms --" << std::endl;
    try {
        AForm* form1 = intern1.makeForm("shrubbery creation", "park");
        AForm* form2 = intern2.makeForm("presidential pardon", "criminal");
        
        std::cout << "Form 1: " << *form1 << std::endl;
        std::cout << "Form 2: " << *form2 << std::endl;
        
        delete form1;
        delete form2;
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}