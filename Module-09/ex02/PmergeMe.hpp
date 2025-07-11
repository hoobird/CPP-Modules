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
#include <ctime>
#include <sys/time.h>
#include <iomanip>
#include <limits>


class PmergeMe {
    public:
        PmergeMe(int argc, char **argv);
        ~PmergeMe();

        void fjsort();
    
        std::string toString() const;
    
        static unsigned int comparisons;
    
        std::vector<int> vdata;
    private:


        void makePairsandSort(unsigned int iteration);

        unsigned int getJacobNo(unsigned int i);

        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);

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

        bool compareSubGroups(const SubGroup &a, const SubGroup &b);
};

#endif
