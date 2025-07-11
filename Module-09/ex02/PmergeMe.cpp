#include "PmergeMe.hpp"

unsigned int PmergeMe::comparisons = 0;

PmergeMe::PmergeMe(int argc, char **argv)
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

void    printVint(std::vector<int> v1) {
    for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::makePairsandSort(unsigned int iteration)
{
    unsigned int groupsize = std::pow(2, iteration);
    if (groupsize * 2 > vdata.size()) {
        return;
    }
    // std::cout << "Iteration " << iteration << std::endl;
    // std::cout << "Group size: " << groupsize << std::endl;
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
    // printVVint(temp);

    // pair up the groups, sort by last number of each group
    for (std::vector< std::vector<int> >::iterator its = temp.begin(); its != temp.end(); its += 2) {
        if (its == temp.end() - 1 || (its == temp.end() - 2 && (its + 1)->size() < groupsize) )  {
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
    // std::cout << "Iteration " << iteration << ": " << toString() << std::endl;
    makePairsandSort(iteration + 1);
    // std::cout << "AFTER number of comparisons: " << comparisons << std::endl;
    
    // std::cout << "\n\nAfter makePairsandSort\niteration " << iteration << ": " << toString() << std::endl;

    // Steps 2 and 3: the initialization and insertion

    // 2. INITIALIZATION

    // 2.0 Partitioning
    std::vector<int> copy = vdata; 
    std::vector<int> nonpart;
    unsigned int nonpartsize = copy.size() % (groupsize);
    
    // std::cout << "vdata size: " << copy.size() << std::endl;
    // std::cout << "Non-partitioned size: " << nonpartsize << std::endl;
    
    if (nonpartsize > 0) {
        nonpart.insert(nonpart.end(), copy.end() - nonpartsize, copy.end());
        copy.erase(copy.end() - nonpartsize, copy.end());
    }
    temp.clear();
    counter = 0;
    it = copy.begin();
    while (it != copy.end()) 
    {
        if (counter % groupsize == 0)
        {
            temp.push_back(std::vector<int>());
        }
        (*(temp.rbegin())).push_back(*it);;
        ++it;
        ++counter;
    }
    // std::cout << "\nnew temp: ";
    // printVVint(temp);
    // std::cout << "new nonpart: ";
    // printVint(nonpart);

    // 2.1 Labelling
    std::vector<SubGroup> mainchain;
    std::vector<SubGroup> pendchain;

    mainchain.push_back(SubGroup("b1", temp[0]));
    mainchain.push_back(SubGroup("a1", temp[1]));
    temp.erase(temp.begin(), temp.begin() + 2);

    counter = 2;
    while (!temp.empty()) {
        std::stringstream ss;
        std::string tag;
        if (counter % 2 == 0) {
            ss << "b" << counter / 2 + 1;
            tag = ss.str();
            pendchain.push_back(SubGroup(tag, temp[0]));
        } else {
            ss << "a" << counter / 2 + 1;
            tag = ss.str();
            mainchain.push_back(SubGroup(tag, temp[0]));
        }
        counter++;
        temp.erase(temp.begin());
    }
    // std::cout << "Main chain: ";
    // for (std::vector<SubGroup>::iterator it = mainchain.begin(); it != mainchain.end(); ++it) {
    //     std::cout << it->toStringsg() << " | ";
    // }
    // std::cout << std::endl;
    // std::cout << "Pend chain: ";
    // for (std::vector<SubGroup>::iterator it = pendchain.begin(); it != pendchain.end(); ++it) {
    //     std::cout << it->toStringsg() << " | ";
    // }
    // std::cout << std::endl;

    // 3. INSERTION
    // we know that the pend chain starts from 2,3,4,5....
    counter = 2; // skip 1 as we already have the first element in mainchain
    unsigned int insertioncounter = 0;
    unsigned int lowerbound = 1;
    unsigned int currJacob = getJacobNo(counter);
    while (1) {
        if (insertioncounter >= pendchain.size()) {
            break;
        }
        for (unsigned int i = currJacob; i > lowerbound; --i) {
            if (i > pendchain.size() + 1) {
                continue;
            }
            std::stringstream ssm;
            ssm << "a" << i;
            std::string tagm = ssm.str();
            std::vector<SubGroup>::iterator upperit = std::find(mainchain.begin(), mainchain.end(), SubGroup(tagm));

            std::vector<SubGroup>::iterator itinsert = std::lower_bound(mainchain.begin(), upperit, pendchain[i - 2]);
            mainchain.insert(itinsert, pendchain[i - 2]);
            ++insertioncounter;   
        }
        lowerbound = currJacob;
        ++counter;
        currJacob = getJacobNo(counter);
    }

    // 4. convert mainchain to vdata
    vdata.clear();
    for (std::vector<SubGroup>::iterator it = mainchain.begin(); it != mainchain.end(); ++it) {
        for (std::vector<int>::iterator it2 = it->subvec.begin(); it2 != it->subvec.end(); ++it2) {
            vdata.push_back(*it2);
        }
    }
    if (!nonpart.empty()) {
        vdata.insert(vdata.end(), nonpart.begin(), nonpart.end());
    }

    // std::cout << "Final sorted sequence: " << toString() << std::endl;

}

unsigned int PmergeMe::getJacobNo(unsigned int i)
{
    if (i == 0)
        return 1;
    if (i == 1)
        return 1;
    return getJacobNo(i - 1) + 2 * getJacobNo(i - 2);
}

bool PmergeMe::compareSubGroups(const SubGroup &a, const SubGroup &b)
{
    ++comparisons;
    return a.lastnum < b.lastnum;
}

PmergeMe::SubGroup::SubGroup() {}

PmergeMe::SubGroup::SubGroup(const SubGroup &other): tag(other.tag), lastnum(other.lastnum), subvec(other.subvec) {}

PmergeMe::SubGroup &PmergeMe::SubGroup::operator=(const SubGroup &other)
{
    if (this != &other) {
        this->tag = other.tag;
        this->lastnum = other.lastnum;
        this->subvec = other.subvec;
    }
    return *this;
}

PmergeMe::SubGroup::SubGroup(std::string tag, const std::vector<int> &v)
    : tag(tag), subvec(v)
{
    lastnum = 0;
    if (!v.empty()) {
        lastnum = v.back();
    }
}

PmergeMe::SubGroup::SubGroup(std::string tag)
: tag(tag) {}

PmergeMe::SubGroup::~SubGroup()
{
}

bool PmergeMe::SubGroup::operator==(const SubGroup &other) const
{
    return (this->tag == other.tag);
}

bool PmergeMe::SubGroup::operator<(const SubGroup &other) const
{
    ++PmergeMe::comparisons;
    return (this->lastnum < other.lastnum);
}

std::string PmergeMe::SubGroup::toStringsg() const
{
    std::stringstream ss;
    ss << "Tag: " << tag << ", Last number: " << lastnum << ", Subvector: [ ";
    for (std::vector<int>::const_iterator it = subvec.begin(); it != subvec.end(); ++it) {
        ss << *it << " ";
    }
    ss << "]";
    return ss.str();
}

