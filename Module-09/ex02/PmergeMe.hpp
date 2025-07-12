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

class PmergeMeVector {
    public:
        PmergeMeVector(std::vector<int> inputData);
        ~PmergeMeVector();

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
        
        PmergeMeVector();
        PmergeMeVector(const PmergeMeVector &other);
        PmergeMeVector &operator=(const PmergeMeVector &other);
        
};

// Helper functions for printing
void    printVVint(std::vector< std::vector<int> > v1);
std::string highlightlastnum(std::vector<int> v);

class PmergeMeDeque {
    public:
        PmergeMeDeque(std::deque<int> inputData);
        ~PmergeMeDeque();

        void fjsort();
    
        std::string toString() const;
    
        static unsigned int comparisons;
    
        std::deque<int> ddata;
    private:
        class SubGroup {
            public:
            static unsigned int &comparisons;
            SubGroup();
            SubGroup(const SubGroup &other);
            SubGroup &operator=(const SubGroup &other);
            SubGroup(std::string tag, const std::deque<int> &v);
            SubGroup(std::string tag); // for comparison purposes
            ~SubGroup();
            bool operator==(const SubGroup &other) const;
            bool operator<(const SubGroup &other) const;
            std::string tag;
            int lastnum;
            std::deque<int> subdeq;
            std::string toStringsg() const;
        };
        
        void fordJohnsonSort(unsigned int iteration);
        std::deque< std::deque<int> > groupDeque(const std::deque<int> &other, unsigned int groupsize);
        void pairAndSortGroups(std::deque<std::deque<int> > &temp, unsigned int groupsize);
        void labelSubGroups(std::deque<std::deque<int> > &temp, std::deque<SubGroup> &mainchain, std::deque<SubGroup> &pendchain);
        void insertFromPendChain(std::deque<SubGroup> &mainchain, std::deque<SubGroup> &pendchain);

        unsigned int getJacobNo(unsigned int i);
        
        PmergeMeDeque();
        PmergeMeDeque(const PmergeMeDeque &other);
        PmergeMeDeque &operator=(const PmergeMeDeque &other);
        
};

// Helper functions for printing
void    printDDint(std::deque< std::deque<int> > v1);
std::string highlightlastnum(std::deque<int> v);

#ifdef BONUS
#include <list>
class PmergeMeList {
    public:
        PmergeMeList(std::list<int> inputData);
        ~PmergeMeList();

        void fjsort();
    
        std::string toString() const;
    
        static unsigned int comparisons;
    
        std::list<int> ldata;
    private:
        class SubGroup {
            public:
            static unsigned int &comparisons;
            SubGroup();
            SubGroup(const SubGroup &other);
            SubGroup &operator=(const SubGroup &other);
            SubGroup(std::string tag, const std::list<int> &v);
            SubGroup(std::string tag); // for comparison purposes
            ~SubGroup();
            bool operator==(const SubGroup &other) const;
            bool operator<(const SubGroup &other) const;
            std::string tag;
            int lastnum;
            std::list<int> sublist;
            std::string toStringsg() const;
        };
        
        void fordJohnsonSort(unsigned int iteration);
        std::list< std::list<int> > groupList(const std::list<int> &other, unsigned int groupsize);
        void pairAndSortGroups(std::list<std::list<int> > &temp, unsigned int groupsize);
        void labelSubGroups(std::list<std::list<int> > &temp, std::list<SubGroup> &mainchain, std::list<SubGroup> &pendchain);
        void insertFromPendChain(std::list<SubGroup> &mainchain, std::list<SubGroup> &pendchain);

        unsigned int getJacobNo(unsigned int i);
        
        PmergeMeList();
        PmergeMeList(const PmergeMeList &other);
        PmergeMeList &operator=(const PmergeMeList &other);
        
};

// Helper functions for printing
void    printLLint(std::list< std::list<int> > v1);
std::string highlightlastnum(std::list<int> v);

#endif

#endif
