#ifdef BONUS
#include "PmergeMe.hpp"

PmergeMeList::PmergeMeList(std::list<int> inputData)
: ldata(inputData) {}

PmergeMeList::~PmergeMeList()
{
}

void PmergeMeList::fjsort()
{
    if (ldata.size() < 2) {
        return;
    }
    fordJohnsonSort(0);
}

std::string PmergeMeList::toString() const
{
    std::stringstream ss;
    for (std::list<int>::const_iterator it = ldata.begin(); it != ldata.end(); ++it) {
        ss << *it << " ";
    }
    return ss.str();
}

std::list< std::list<int> > PmergeMeList::groupList(const std::list<int> &other, unsigned int groupsize) {
    std::list< std::list<int> > temp;
    unsigned int counter = 0;
    std::list<int>::const_iterator it = other.begin();
    while (it != other.end()) {
        if (counter % groupsize == 0)
            temp.push_back(std::list<int>());
        temp.back().push_back(*it);
        ++it;
        ++counter;
    }
    return temp;
}

void PmergeMeList::pairAndSortGroups(std::list< std::list<int> > &temp, unsigned int groupsize) {
    std::list< std::list<int> >::iterator its = temp.begin();
    while (its != temp.end()) {
        std::list< std::list<int> >::iterator next = its;
        ++next;
        if (next == temp.end() || next->size() < groupsize)
            break;
        ++comparisons;
        if (its->back() > next->back()) {
            std::iter_swap(its, next);
        }
        std::advance(its, 2);
    }
}

void PmergeMeList::labelSubGroups(std::list<std::list<int> > &temp, std::list<SubGroup> &mainchain, std::list<SubGroup> &pendchain)
{
    if (temp.size() < 2)
        return;

    unsigned int counter = 0;
    for (std::list<std::list<int> >::const_iterator it = temp.begin(); it != temp.end(); ++it, ++counter) {
        std::stringstream ss;
        std::string tag;
        if (counter == 0) {
            tag = "b1";
            mainchain.push_back(SubGroup(tag, *it));
        } else if (counter == 1) {
            tag = "a1";
            mainchain.push_back(SubGroup(tag, *it));
        } else if (counter % 2 == 0) {
            ss << "b" << counter / 2 + 1;
            tag = ss.str();
            pendchain.push_back(SubGroup(tag, *it));
        } else {
            ss << "a" << counter / 2 + 1;
            tag = ss.str();
            mainchain.push_back(SubGroup(tag, *it));
        }
    }
}

void PmergeMeList::insertFromPendChain(std::list<SubGroup>& mainchain, std::list<SubGroup>& pendchain) {
    unsigned int counter = 2;
    unsigned int insertioncounter = 0;
    unsigned int lowerbound = 1;
    unsigned int currJacob = getJacobNo(counter);
    while (insertioncounter < pendchain.size()) {
        for (unsigned int i = currJacob; i > lowerbound; --i) {
            if (i > pendchain.size() + 1)
                continue;
            std::stringstream ssm;
            ssm << "a" << i;
            std::string tagm = ssm.str();
            std::list<SubGroup>::iterator upperit = std::find(mainchain.begin(), mainchain.end(), SubGroup(tagm));
            std::list<SubGroup>::iterator pendit = pendchain.begin();
            std::advance(pendit, i - 2);
            std::list<SubGroup>::iterator itinsert = std::lower_bound(mainchain.begin(), upperit, *pendit);
            mainchain.insert(itinsert, *pendit);
            ++insertioncounter;
        }
        lowerbound = currJacob;
        ++counter;
        currJacob = getJacobNo(counter);
    }
}

void PmergeMeList::fordJohnsonSort(unsigned int iteration)
{
    unsigned int groupsize = std::pow(2, iteration);

    std::stringstream debugss;
    debugss << "Propagation phase (iteration " << iteration << "): \n";
    debugss << "Group size: " << groupsize ;
    DEBUG_PRINT(debugss.str());
    debugss.str("");

    if (groupsize * 2 > ldata.size()) {
        debugss << "End of recursion: group size too large for current data size (" << ldata.size() << ")";
        DEBUG_PRINT(debugss.str());
        debugss.str("");
        return;
    }

    std::list< std::list<int> > temp = groupList(ldata, groupsize);
    DEBUG_CALL(printLLint(temp));

    pairAndSortGroups(temp, groupsize);

    ldata.clear();
    for (std::list< std::list<int> >::iterator it2 = temp.begin(); it2 != temp.end(); ++it2) {
        ldata.insert(ldata.end(), it2->begin(), it2->end());
    }
    fordJohnsonSort(iteration + 1);

    std::list<int> copy = ldata;
    std::list<int> nonpart;
    unsigned int nonpartsize = copy.size() % groupsize;
    if (nonpartsize > 0) {
        std::list<int>::iterator it = copy.end();
        for (unsigned int i = 0; i < nonpartsize; ++i)
            --it;
        nonpart.insert(nonpart.end(), it, copy.end());
        copy.erase(it, copy.end());
    }
    temp.clear();
    temp = groupList(copy, groupsize);

    std::list<SubGroup> mainchain;
    std::list<SubGroup> pendchain;

    labelSubGroups(temp, mainchain, pendchain);

    debugss << "\nMain chain: \n";
    for (std::list<SubGroup>::iterator it = mainchain.begin(); it != mainchain.end(); ++it) {
        debugss << it->toStringsg() << "\n";
    }
    debugss << "\nPend chain: \n";
    for (std::list<SubGroup>::iterator it = pendchain.begin(); it != pendchain.end(); ++it) {
        debugss << it->toStringsg() << "\n";
    }
    debugss << "\nNon-partitioned elements: ";
    if (nonpart.empty()) {
        debugss << "None";
    } else {
        debugss << "[ ";
        for (std::list<int>::iterator it = nonpart.begin(); it != nonpart.end(); ++it) {
            debugss << *it << " ";
        }
        debugss << "]";
    }
    DEBUG_PRINT(debugss.str());
    debugss.str("");
    debugss.clear();

    // 3. INSERTION
    insertFromPendChain(mainchain, pendchain);
    debugss << "main chain after insertion: ";
    for (std::list<SubGroup>::iterator it = mainchain.begin(); it != mainchain.end(); ++it) {
        debugss << it->toStringsg() << " ";
    }
    DEBUG_PRINT(debugss.str());
    debugss.str("");
    debugss.clear();

    ldata.clear();
    for (std::list<SubGroup>::iterator it = mainchain.begin(); it != mainchain.end(); ++it) {
        ldata.insert(ldata.end(), it->sublist.begin(), it->sublist.end());
    }
    if (!nonpart.empty()) {
        ldata.insert(ldata.end(), nonpart.begin(), nonpart.end());
    }

    debugss << "End of iteration " << iteration << " sorting: " << toString() << "\n";
    DEBUG_PRINT(debugss.str());
    debugss.str("");
    debugss.clear();
}

unsigned int PmergeMeList::getJacobNo(unsigned int i)
{
    if (i == 0)
        return 1;
    if (i == 1)
        return 1;
    return getJacobNo(i - 1) + 2 * getJacobNo(i - 2);
}

// SubGroup implementation

PmergeMeList::SubGroup::SubGroup() {}

PmergeMeList::SubGroup::SubGroup(const SubGroup &other): tag(other.tag), lastnum(other.lastnum), sublist(other.sublist) {}

PmergeMeList::SubGroup &PmergeMeList::SubGroup::operator=(const SubGroup &other)
{
    if (this != &other) {
        this->tag = other.tag;
        this->lastnum = other.lastnum;
        this->sublist = other.sublist;
    }
    return *this;
}

PmergeMeList::SubGroup::SubGroup(std::string tag, const std::list<int> &v)
    : tag(tag), sublist(v)
{
    lastnum = 0;
    if (!v.empty()) {
        lastnum = v.back();
    }
}

PmergeMeList::SubGroup::SubGroup(std::string tag)
: tag(tag) {}

PmergeMeList::SubGroup::~SubGroup()
{
}

bool PmergeMeList::SubGroup::operator==(const SubGroup &other) const
{
    return (this->tag == other.tag);
}

bool PmergeMeList::SubGroup::operator<(const SubGroup &other) const
{
    ++PmergeMeList::comparisons;
    return (this->lastnum < other.lastnum);
}

std::string PmergeMeList::SubGroup::toStringsg() const
{
    std::stringstream ss;
    ss << tag << " ->\t";
    ss << "[ ";
    for (std::list<int>::const_iterator it = sublist.begin(); it != sublist.end(); ++it) {
        std::list<int>::const_iterator next_it = it;
        ++next_it;
        if (next_it == sublist.end())
            ss << "(" << *it << ") ";
        else
            ss << *it << " ";
    }
    ss << "]";
    return ss.str();
}

unsigned int PmergeMeList::comparisons = 0;

#endif