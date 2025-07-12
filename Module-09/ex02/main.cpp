#include "PmergeMe.hpp"

bool checkPositiveIntegerSequence(int argc, char **argv);
long getMaxFJComparisons(int n);
std::vector<int> getInputDataVector(int argc, char **argv);
std::deque<int> getInputDataDeque(int argc, char **argv);
void    printVint(std::vector<int> v1);
void    printDint(std::deque<int> v1);
#ifdef BONUS
std::list<int> getInputDataList(int argc, char **argv);
void    printLint(std::list<int> v1);
#endif

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: No arguments provided." << std::endl;
        return 1;
    }

    if (!checkPositiveIntegerSequence(argc, argv)) {
        return 2;
    }
    #ifndef BONUS
        std::vector<int> quickvector = getInputDataVector(argc, argv);
        std::cout << "Before:\t";
        printVint(quickvector);
        std::sort(quickvector.begin(), quickvector.end());
        std::cout << "After:\t";
        printVint(quickvector);
    #else
        std::cout << "Maximum number of comparisons for FJ sort with " 
                  << argc - 1 << " elements: " 
                  << getMaxFJComparisons(argc - 1) << std::endl;    
    #endif

    
    {
        timeval start, end;
        long seconds, useconds, total_useconds;
        std::vector<int> inputDataVector = getInputDataVector(argc, argv);
        
        // start vector-based FJ sorting
        gettimeofday(&start, NULL);
        PmergeMeVector pmergeMeVector(inputDataVector);;
        pmergeMeVector.fjsort();
        gettimeofday(&end, NULL);
        // end vector-based FJ sorting
        
        #ifdef BONUS
        std::cout << "Using std::vector:" << std::endl;
        // std::cout << "\tBefore: ";
        // printVint(inputDataVector);
        // std::cout << "\tAfter: " << pmergeMeVector.toString() << std::endl;
        #endif
        std::sort(inputDataVector.begin(), inputDataVector.end()); // sort using std::sort for comparison
        if (inputDataVector != pmergeMeVector.vdata) {
            // this one come out means gg liao
            std::cerr << "Error(Vector): The sorted output does not match the expected result." << std::endl;
            return 3;
        }
        seconds = end.tv_sec - start.tv_sec;
        useconds = end.tv_usec - start.tv_usec;
        total_useconds = seconds * 1000000 + useconds;
        #ifdef BONUS
        std::cout << "\tNumber of comparisons: " << pmergeMeVector.comparisons << std::endl;
        std::cout << "\tTime to process a range of " << argc - 1 << " elements: " 
                << total_useconds << " us" << std::endl;
        #else
        std::cout << "Time to process a range of 5 elements with std::vector : " << total_useconds << " us" << std::endl;
        #endif

    }

    {
        timeval start, end;
        long seconds, useconds, total_useconds;
        std::deque<int> inputDataDeque = getInputDataDeque(argc, argv);
        
        // start deque-based FJ sorting
        gettimeofday(&start, NULL);
        PmergeMeDeque pmergeMeDeque(inputDataDeque);;
        pmergeMeDeque.fjsort();
        gettimeofday(&end, NULL);
        // end deque-based FJ sorting
        
        #ifdef BONUS
        std::cout << "Using std::deque:" << std::endl;
        // std::cout << "\tBefore: ";
        // printDint(inputDataDeque);
        // std::cout << "\tAfter: " << pmergeMeDeque.toString() << std::endl;
        #endif
        std::sort(inputDataDeque.begin(), inputDataDeque.end()); // sort using std::sort for comparison
        if (inputDataDeque != pmergeMeDeque.ddata) {
            // this one come out means gg liao
            std::cerr << "Error(Deque): The sorted output does not match the expected result." << std::endl;
            return 4;
        }
        seconds = end.tv_sec - start.tv_sec;
        useconds = end.tv_usec - start.tv_usec;
        total_useconds = seconds * 1000000 + useconds;
        #ifdef BONUS
        std::cout << "\tNumber of comparisons: " << pmergeMeDeque.comparisons << std::endl;
        std::cout << "\tTime to process a range of " << argc - 1 << " elements: " 
                << total_useconds << " us" << std::endl;
        #else
        std::cout << "Time to process a range of 5 elements with std::deque : " << total_useconds << " us" << std::endl;
        #endif
    }

    #ifdef BONUS
    {
        timeval start, end;
        long seconds, useconds, total_useconds;
        std::list<int> inputDataList = getInputDataList(argc, argv);
        
        // start list-based FJ sorting
        gettimeofday(&start, NULL);
        PmergeMeList pmergeMeList(inputDataList);;
        pmergeMeList.fjsort();
        gettimeofday(&end, NULL);
        // end list-based FJ sorting
        
        std::cout << "Using std::list:" << std::endl;
        // std::cout << "\tBefore: ";
        // printLint(inputDataList);
        // std::cout << "\tAfter: " << pmergeMeList.toString() << std::endl;
        inputDataList.sort();
        if (inputDataList != pmergeMeList.ldata) {
            // this one come out means gg liao
            std::cerr << "Error(List): The sorted output does not match the expected result." << std::endl;
            return 5;
        }
        seconds = end.tv_sec - start.tv_sec;
        useconds = end.tv_usec - start.tv_usec;
        total_useconds = seconds * 1000000 + useconds;
        
        std::cout << "\tNumber of comparisons: " << pmergeMeList.comparisons << std::endl;
        std::cout << "\tTime to process a range of " << argc - 1 << " elements: " 
                << total_useconds << " us" << std::endl;
    }
    #endif
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
    long sum = 0;
    for (int k = 1; k <= n; ++k) {
        double val = (3.0 / 4.0) * k;
        double log2val = log(val) / log(2.0); // log base 2
        long ceilval = static_cast<int>(ceil(log2val));
        sum += ceilval;
    }
    return sum;
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

#ifdef BONUS

std::list<int> getInputDataList(int argc, char **argv)
{
    std::list<int> data;
    for (int i = 1; i < argc; ++i) {
        errno = 0;
        char *endptr;
        long value = strtol(argv[i], &endptr, 10);
        data.push_back(static_cast<int>(value));
    }
    return data;
}

void printLint(std::list<int> v1)
{
    for (std::list<int>::iterator it = v1.begin(); it != v1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

#endif