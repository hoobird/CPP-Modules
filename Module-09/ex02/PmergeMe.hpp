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

class PmergeMe {
    public:
        PmergeMe(int argc, char **argv);
        ~PmergeMe();

        void fjsort();
    
        std::string toString() const;
    
    
    private:
        unsigned int comparisons;
        std::vector<int> vdata;
        
        void makePairsandSort(unsigned int iteration);

        unsigned int getJacobNo(unsigned int i);

        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);

        typedef struct sSubGroup {
            bool    isMain;
            unsigned int     number;
            std::vector<int> subvec;
            sSubGroup(bool isMain, unsigned int number, std::vector<int> subvec);
        } SubGroup;
        
        bool matchSubGroup(const SubGroup& sg, bool isMain, unsigned int number);
};

#endif
