#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    
    std::cout << "\n==== TESTING SHRUBBERY CREATION FORM ====\n" << std::endl;
    try {
        // Create bureaucrats with different grades
        Bureaucrat low("Junior Engineer", 145);
        Bureaucrat mid("Senior Engineer", 75);
        Bureaucrat high("Staff Engineer", 5);
        
        // Create form
        ShrubberyCreationForm shrubForm("garden");
        
        std::cout << "\n-- Form details --" << std::endl;
        std::cout << shrubForm << std::endl;
        
        std::cout << "\n-- Low level bureaucrat tests --" << std::endl;
        // Low can sign but not execute
        low.signForm(shrubForm);
        
        try {
            low.executeForm(shrubForm); // Should fail, grade too low
        } catch (std::exception &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
        
        std::cout << "\n-- High level bureaucrat executes --" << std::endl;
        high.executeForm(shrubForm); // Should succeed
    } catch (std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n==== TESTING ROBOTOMY REQUEST FORM ====\n" << std::endl;
    try {
        // Create bureaucrats with different grades
        Bureaucrat low("Junior Engineer", 145);
        Bureaucrat mid("Senior Engineer", 45);
        Bureaucrat high("Staff Engineer", 5);
        
        // Create form
        RobotomyRequestForm robotForm("subject");
        
        std::cout << "\n-- Form details --" << std::endl;
        std::cout << robotForm << std::endl;
        
        std::cout << "\n-- Low level bureaucrat tests --" << std::endl;
        try {
            low.signForm(robotForm); // Should fail, grade too low
        } catch (std::exception &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
        
        std::cout << "\n-- Mid level bureaucrat tests --" << std::endl;
        mid.signForm(robotForm);
        mid.executeForm(robotForm); // Should succeed
        
        std::cout << "\n-- Testing robotomy multiple times --" << std::endl;
        // Try few more times to see success/failure
        high.executeForm(robotForm);
        high.executeForm(robotForm);
    } catch (std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n==== TESTING PRESIDENTIAL PARDON FORM ====\n" << std::endl;
    try {
        // Create bureaucrats with different grades
        Bureaucrat low("Junior Engineer", 145);
        Bureaucrat mid("Senior Engineer", 20);
        Bureaucrat high("Staff Engineer", 1);
        
        // Create form
        PresidentialPardonForm pardonForm("criminal");
        
        std::cout << "\n-- Form details --" << std::endl;
        std::cout << pardonForm << std::endl;
        
        std::cout << "\n-- Unsigned form test --" << std::endl;
        try {
            high.executeForm(pardonForm); // Should fail, form not signed
        } catch (std::exception &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
        
        std::cout << "\n-- Mid level bureaucrat tests --" << std::endl;
        mid.signForm(pardonForm);
        
        try {
            mid.executeForm(pardonForm); // Should fail, grade too low
        } catch (std::exception &e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
        
        std::cout << "\n-- High level bureaucrat executes --" << std::endl;
        high.executeForm(pardonForm); // Should succeed
    } catch (std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }
    
    return 0;
}