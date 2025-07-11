#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv): comparisons(0)
{
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
    makePairsandSort(0);

}

std::string PmergeMe::toString() const
{
    std::stringstream ss;
    std::string result;

    for (std::vector<int>::const_iterator it = vdata.begin(); it != vdata.end(); ++it) {
        ss << *it << " ";
    }
    result = ss.str();
    return (result);
}

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

void PmergeMe::makePairsandSort(unsigned int iteration)
{
    unsigned int groupsize = std::pow(2, iteration);
    if (groupsize * 2 > vdata.size()) {
        return;
    }
    std::cout << "Iteration " << iteration << std::endl;
    std::cout << "Group size: " << groupsize << std::endl;
    unsigned int counter = 0;
    std::vector<int>::iterator it = vdata.begin();
    std::vector< std::vector<int> > temp;
    while (it != vdata.end()) 
    {
        if (counter % groupsize == 0)
        {
            temp.push_back(std::vector<int>());
        }
        (*(temp.rbegin())).push_back(*it);;
        ++it;
        ++counter;
    }
    printVVint(temp);

    // pair up the groups, sort by last number of each group
    for (std::vector< std::vector<int> >::iterator its = temp.begin(); its != temp.end(); its += 2) {
        if (its == temp.end() - 1 || temp.rbegin()->size() < groupsize) {
            break;
        }
        ++comparisons;
        if(*(its->rbegin()) > (*(its + 1)->rbegin())) {
            std::iter_swap(its, its + 1);
        }
    }
    vdata.clear();
    for (std::vector< std::vector<int> >::iterator it2 = temp.begin(); it2 != temp.end(); ++it2) {
        for (std::vector<int>::iterator it3 = it2->begin(); it3 != it2->end(); ++it3) {
            vdata.push_back(*it3);
        }
    }
    std::cout << "Iteration " << iteration << ": " << toString() << std::endl;
    makePairsandSort(iteration + 1);
    
    std::cout << "Number of Comparisons: " << comparisons << std::endl;
    std::cout << "\n\nAfter makePairsandSort\niteration " << iteration << ": " << toString() << std::endl;

    // Steps 2 and 3: the initialization and insertion

    // 2. INITIALIZATION
    std::vector<SubGroup> mainchain;
    std::vector<SubGroup> pendchain;
    std::vector<int> nonpart;
    unsigned int nonpartsize = vdata.size() % (groupsize * 2);
    std::cout << "vdata size: " << vdata.size() << std::endl;
    std::cout << "Non-partitioned size: " << nonpartsize << std::endl;

    if (nonpartsize > 0) {
        nonpart.insert(nonpart.end(), vdata.end() - nonpartsize, vdata.end());
    }
    counter = 0;
    it = vdata.begin();
    while (it != vdata.end()) 
    {
        // if (counter % (groupsize * 2) < (groupsize / 2)) {
        //     mainchain
        // }
        ++it;
        ++counter;
    }
    printVVint(temp);

    

    // // Split into main and pend chains
    // for (size_t i = 0; i + 1 < temp.size(); i += 2) {
    //     if (i == 0) {
    //         mainchain.push_back(SubGroup("b1", temp[i]));
    //         mainchain.push_back(SubGroup("a1", temp[i + 1]));
    //     }
    // }
    // // If odd number of groups, last one goes to mainchain
    // if (temp.size() % 2 != 0) {
    //     mainchain.push_back(SubGroup("main", temp.back()));
    // }
   
}

unsigned int PmergeMe::getJacobNo(unsigned int i)
{
    if (i == 0)
        return 1;
    if (i == 1)
        return 1;
    return getJacobNo(i - 1) + 2 * getJacobNo(i - 2);
}



PmergeMe::SubGroup::SubGroup(char tagab, int tag12, const std::vector<int> &v)
: tagab(tagab), tag12(tag12), subvec(v)
{
    if (!v.empty()) {
        lastnum = v.back();
    }
}
