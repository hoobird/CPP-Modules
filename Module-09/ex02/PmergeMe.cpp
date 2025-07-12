#include "PmergeMe.hpp"

unsigned int PmergeMeVector::comparisons = 0;
unsigned int PmergeMeDeque::comparisons = 0;

void    printVVint(std::vector< std::vector<int> > v1) {
    for (std::vector< std::vector<int> >::iterator it = v1.begin(); it != v1.end(); ++it) {
        std::cout << "[ ";
        for (std::vector<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2) {
            std::cout << *it2 << " ";
        }
        std::cout << "] " ;
    }
    std::cout << std::endl;
}

std::string highlightlastnum(std::vector<int> v) {
    std::stringstream ss;
    if (v.empty()) {
        return "";
    }
    ss << "[ ";
    for (std::vector<int>::const_iterator it = v.begin(); it != v.end() - 1; ++it) {
        ss << *it << " ";
    }
    ss << "(" << v.back() << ") ]" ;
    return ss.str();
}

void    printDDint(std::deque< std::deque<int> > v1) {
    for (std::deque< std::deque<int> >::iterator it = v1.begin(); it != v1.end(); ++it) {
        std::cout << "[ ";
        for (std::deque<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2) {
            std::cout << *it2 << " ";
        }
        std::cout << "] " ;
    }
    std::cout << std::endl;
}

std::string highlightlastnum(std::deque<int> v) {
    std::stringstream ss;
    if (v.empty()) {
        return "";
    }
    ss << "[ ";
    for (std::deque<int>::const_iterator it = v.begin(); it != v.end() - 1; ++it) {
        ss << *it << " ";
    }
    ss << "(" << v.back() << ") ]" ;
    return ss.str();
}