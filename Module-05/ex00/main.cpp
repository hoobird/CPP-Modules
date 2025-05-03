#include "Bureaucrat.hpp"

int main() {
    
    std::cout << "-- Out of upper range test-- " << std::endl;
    try {
        Bureaucrat b1("Denise", 0);
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "-- Out of lower range test 1-- " << std::endl;
    try {
        Bureaucrat b1("Charlie", 151);
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "-- Upper limit test -- " << std::endl;
    try {
        Bureaucrat b1("Abigail", 1);
        std::cout << b1 << std::endl;
        b1.decrementGrade();
        std::cout << "After decrement: " << b1 << std::endl;
        std::cout << "Incrementing twice now... " << std::endl;
        b1.incrementGrade();
        b1.incrementGrade(); // should throw
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "-- Lower limit test -- " << std::endl;
    try {
        Bureaucrat b1("Bobby", 150);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << "After increment: " << b1 << std::endl;
        std::cout << "Decrementing twice now... " << std::endl;
        b1.decrementGrade();
        b1.decrementGrade(); // should throw
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    return 0;
}
