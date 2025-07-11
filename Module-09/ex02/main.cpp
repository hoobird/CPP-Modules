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
    
    timeval start, end;
    long seconds, useconds, total_useconds;
    std::vector<int> inputData;
    
    gettimeofday(&start, NULL);
    PmergeMe pmergeMe(argc, argv);
    inputData = pmergeMe.vdata;
    std::cout << "Before: " << pmergeMe.toString() << std::endl;
    pmergeMe.fjsort();
    std::cout << "After: " << pmergeMe.toString() << std::endl;
    gettimeofday(&end, NULL);

    std::sort(inputData.begin(), inputData.end());
    if (inputData != pmergeMe.vdata) {
        std::cerr << "Error: The sorted output does not match the expected result." << std::endl;
        return 3;
    }

    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    total_useconds = seconds * 1000000 + useconds;
    
    std::cout << "Number of comparisons: " << pmergeMe.comparisons << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with PmergeMe: " 
              << total_useconds << " us" << std::endl;
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
        if (errno == ERANGE || value > std::numeric_limits<int>::max()) {
            std::cerr << "Error: Argument " << i << " is out of range." << std::endl;
            return false;
        }
    }
    return true;
}