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
    for (std::vector<int>::const_iterator it = vdata.begin(); it != data.end(); ++it) {
        os << *it << " ";
    }
    return os;
}
