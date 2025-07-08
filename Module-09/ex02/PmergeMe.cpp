#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv, containertype type)
{
    (void)type; // Suppress unused parameter warning
    for (int i = 1; i < argc; ++i) {
        errno = 0;
        char *endptr;
        long value = strtol(argv[i], &endptr, 10);
        vdata.push_back(static_cast<int>(value));
    }
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::fjsort()
{
    if (vdata.size() < 2) {
        return;
    }

}

std::ostream &PmergeMe::toStream(std::ostream &os) const
{
    for (std::vector<int>::const_iterator it = vdata.begin(); it != vdata.end(); ++it) {
        os << *it << " ";
    }
    return os;
}

void PmergeMe::makePairsandSort(unsigned int iteration)
{
    int groupsize = std::pow(2, iteration);
    if (groupsize * 2 > vdata.size()) {
        return;
    }

    std::vector<std::vector<int>> temp;
    for (unsigned int i = 0; i < vdata.size(); ++i) {
        if (i )
    }

}