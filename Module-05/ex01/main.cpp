#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "-- Form with invalid sign grade test -- " << std::endl;
    try {
        Form f1("Tax Form", 0, 50);  // Too high sign grade
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "-- Form with invalid execute grade test -- " << std::endl;
    try {
        Form f2("Permit Form", 50, 151);  // Too low execute grade
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "-- Form signing with sufficient grade test -- " << std::endl;
    try {
        Bureaucrat b1("Alice", 30);
        Form f3("Approval Form", 50, 25);
        
        std::cout << "Initial state: " << f3 << std::endl;
        std::cout << "Bureaucrat: " << b1 << std::endl;
        
        b1.signForm(f3);
        std::cout << "After signing: " << f3 << std::endl;
        
        // Try signing again
        b1.signForm(f3);
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "-- Form signing with insufficient grade test -- " << std::endl;
    try {
        Bureaucrat b2("Bob", 75);
        Form f4("Classified Form", 25, 10);
        
        std::cout << "Initial state: " << f4 << std::endl;
        std::cout << "Bureaucrat: " << b2 << std::endl;
        
        b2.signForm(f4);  // Should throw GradeTooLowException
        std::cout << "This line should not be reached" << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "-- Direct beSigned test with insufficient grade -- " << std::endl;
    try {
        Bureaucrat b3("Charlie", 100);
        Form f5("Secret Form", 50, 25);
        
        std::cout << "Initial state: " << f5 << std::endl;
        std::cout << "Bureaucrat: " << b3 << std::endl;
        
        f5.beSigned(b3);  // Should throw GradeTooLowException
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    return 0;
}
