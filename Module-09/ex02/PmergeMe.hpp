#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <cmath>

typedef enum {
    VECTOR,
    DEQUE
} containertype;

class PmergeMe {
    public:
        PmergeMe(int argc, char **argv, containertype type);
        ~PmergeMe();

        void fjsort();
    
        std::ostream &toStream(std::ostream &os) const;
    
    
    private:
        PmergeMe();
        std::vector<int> vdata;

        void makePairsandSort(unsigned int iteration);

        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
};

#endif
