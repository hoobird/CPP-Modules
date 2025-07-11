#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <ctime>
#include <sys/time.h>
#include <iomanip>
#include <limits>

#ifdef DEBUG
    #define DEBUG_PRINT(x) do { std::cout << x << std::endl; } while (0)
    #define DEBUG_CALL(x) x
#else
    #define DEBUG_PRINT(x) do {} while (0)
    #define DEBUG_CALL(x)
#endif

class PmergeMe {
    public:
        PmergeMe(std::vector<int> inputData);
        ~PmergeMe();

        void fjsort();
    
        std::string toString() const;
    
        static unsigned int comparisons;
    
        std::vector<int> vdata;
    private:
        class SubGroup {
            public:
            static unsigned int &comparisons;
            SubGroup();
            SubGroup(const SubGroup &other);
            SubGroup &operator=(const SubGroup &other);
            SubGroup(std::string tag, const std::vector<int> &v);
            SubGroup(std::string tag); // for comparison purposes
            ~SubGroup();
            bool operator==(const SubGroup &other) const;
            bool operator<(const SubGroup &other) const;
            std::string tag;
            int lastnum;
            std::vector<int> subvec;
            std::string toStringsg() const;
        };
        
        void fordJohnsonSort(unsigned int iteration);
        std::vector< std::vector<int> > groupVector(const std::vector<int> &other, unsigned int groupsize);
        void pairAndSortGroups(std::vector<std::vector<int> > &temp, unsigned int groupsize);
        void labelSubGroups(std::vector<std::vector<int> > &temp, std::vector<SubGroup> &mainchain, std::vector<SubGroup> &pendchain);
        void insertFromPendChain(std::vector<SubGroup> &mainchain, std::vector<SubGroup> &pendchain);

        unsigned int getJacobNo(unsigned int i);
        
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        
};

// Helper functions for printing
void    printVVint(std::vector< std::vector<int> > v1);
void    printVint(std::vector<int> v1);
std::string highlightlastnum(std::vector<int> v);
    
#endif
    