#ifndef PMERGEME_HPP
#define PMERGEME_HPP

template <typename T>
class PmergeMe {
    public:
        PmergeMe();
        ~PmergeMe();

        void fjsort();
    
    private:
        T *data;

        void makePairs();

        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
};

#endif