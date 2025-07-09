#include "PmergeMe.hpp"


bool checkPositiveIntegerSequence(int argc, char **argv);



int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: No arguments provided." << std::endl;
        return 1;
    }

    if (!checkPositiveIntegerSequence(argc, argv)) {
        return 2;
    }

    PmergeMe pmergeMe(argc, argv, VECTOR);
    std::cout << "Initial sequence: " << pmergeMe.toString() << std::endl;
    pmergeMe.fjsort();
    std::cout << "Sorted sequence: " << pmergeMe.toString() << std::endl;
    
    return 0;
}

bool checkPositiveIntegerSequence(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        errno = 0;
        char *endptr;
        long value = strtol(argv[i], &endptr, 10);
        if (*endptr != '\0' || value <= 0) {
            std::cerr << "Error: Argument " << i << " is not a positive integer." << std::endl;
            return false;
        }
    }
    return true;
}