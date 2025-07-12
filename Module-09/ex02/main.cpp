#include "PmergeMe.hpp"

bool checkPositiveIntegerSequence(int argc, char **argv);
long getMaxFJComparisons(int n);
std::vector<int> getInputDataVector(int argc, char **argv);
std::deque<int> getInputDataDeque(int argc, char **argv);
void    printVint(std::vector<int> v1);
void    printDint(std::deque<int> v1);

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: No arguments provided." << std::endl;
        return 1;
    }

    if (!checkPositiveIntegerSequence(argc, argv)) {
        return 2;
    }
    
    {
        timeval start, end;
        long seconds, useconds, total_useconds;
        std::vector<int> inputDataVector = getInputDataVector(argc, argv);
        
        // start vector-based FJ sorting
        std::cout << "Using std::vector:" << std::endl;
        gettimeofday(&start, NULL);
        PmergeMeVector pmergeMeVector(inputDataVector);;
        // std::cout << "\tBefore: ";
        // printVint(inputDataVector);
        pmergeMeVector.fjsort();
        // std::cout << "\tAfter: " << pmergeMeVector.toString() << std::endl;
        gettimeofday(&end, NULL);
        // end vector-based FJ sorting
    
        std::sort(inputDataVector.begin(), inputDataVector.end()); // sort using std::sort for comparison
        if (inputDataVector != pmergeMeVector.vdata) {
            // this one come out means gg liao
            std::cerr << "Error(Vector): The sorted output does not match the expected result." << std::endl;
            return 3;
        }
        seconds = end.tv_sec - start.tv_sec;
        useconds = end.tv_usec - start.tv_usec;
        total_useconds = seconds * 1000000 + useconds;
        
        std::cout << "\tNumber of comparisons: " << pmergeMeVector.comparisons << std::endl;
        std::cout << "\tTime to process a range of " << argc - 1 << " elements: " 
                << total_useconds << " us" << std::endl;

    }

    {
        timeval start, end;
        long seconds, useconds, total_useconds;
        std::deque<int> inputDataDeque = getInputDataDeque(argc, argv);
        
        // start vector-based FJ sorting
        std::cout << "Using std::deque:" << std::endl;
        gettimeofday(&start, NULL);
        PmergeMeDeque pmergeMeDeque(inputDataDeque);;
        // std::cout << "\tBefore: ";
        // printDint(inputDataDeque);
        pmergeMeDeque.fjsort();
        // std::cout << "\tAfter: " << pmergeMeDeque.toString() << std::endl;
        gettimeofday(&end, NULL);
        // end vector-based FJ sorting
    
        std::sort(inputDataDeque.begin(), inputDataDeque.end()); // sort using std::sort for comparison
        if (inputDataDeque != pmergeMeDeque.vdata) {
            // this one come out means gg liao
            std::cerr << "Error(Deque): The sorted output does not match the expected result." << std::endl;
            return 3;
        }
        seconds = end.tv_sec - start.tv_sec;
        useconds = end.tv_usec - start.tv_usec;
        total_useconds = seconds * 1000000 + useconds;
        
        std::cout << "\tNumber of comparisons: " << pmergeMeDeque.comparisons << std::endl;
        std::cout << "\tTime to process a range of " << argc - 1 << " elements: " 
                << total_useconds << " us" << std::endl;
    }
    return 0;
}

bool checkPositiveIntegerSequence(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        errno = 0;
        char *endptr;
        long value = strtol(argv[i], &endptr, 10);
        if (*endptr != '\0' || value <= 0) {
            std::cerr << "Error: Argument " << i << " (" << argv[i] << ") is not a positive integer." << std::endl;
            return false;
        }
        if (errno == ERANGE || value > std::numeric_limits<int>::max()) {
            std::cerr << "Error: Argument " << i << " is out of range." << std::endl;
            return false;
        }
    }
    return true;
}

std::vector<int> getInputDataVector(int argc, char **argv) {
    std::vector<int> data;
    for (int i = 1; i < argc; ++i) {
        errno = 0;
        char *endptr;
        long value = strtol(argv[i], &endptr, 10);
        data.push_back(static_cast<int>(value));
    }
    return data;
}

std::deque<int> getInputDataDeque(int argc, char **argv) {
    std::deque<int> data;
    for (int i = 1; i < argc; ++i) {
        errno = 0;
        char *endptr;
        long value = strtol(argv[i], &endptr, 10);
        data.push_back(static_cast<int>(value));
    }
    return data;
}

long getMaxFJComparisons(int n) {
    long long F = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        double logValue = std::log10(value);
        int floorLog = static_cast<int>(std::floor(logValue));
        F += floorLog;
    }
    return F;
}

void    printVint(std::vector<int> v1) {
    for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void    printDint(std::deque<int> v1) {
    for (std::deque<int>::iterator it = v1.begin(); it != v1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}