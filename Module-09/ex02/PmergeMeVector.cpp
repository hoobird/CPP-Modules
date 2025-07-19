#include "PmergeMe.hpp"

PmergeMeVector::PmergeMeVector(std::vector<int> inputData)
: vdata(inputData), vsize(vdata.size()) {}

PmergeMeVector::~PmergeMeVector()
{
}

void PmergeMeVector::fjsort()
{
    if (vsize < 2) {
        return;
    }
    fordJohnsonSort(0);
}

std::string PmergeMeVector::toString() const
{
    std::stringstream ss;
    std::string result;

    for (std::vector<int>::const_iterator it = vdata.begin(); it != vdata.end(); ++it) {
        ss << *it << " ";
    }
    result = ss.str();
    return (result);
}

std::vector< std::vector<int> > PmergeMeVector::groupVector(const std::vector<int> &other, unsigned int groupsize) {
    std::vector< std::vector<int> > temp;
    temp.reserve(vsize % groupsize == 0 ? (vsize / groupsize) : (vsize / groupsize + 1));
    unsigned int counter = 0;
    std::vector<int>::const_iterator it = other.begin();
    while (it != other.end()) 
    {
        if (counter % groupsize == 0)
        {
            temp.push_back(std::vector<int>());
            temp.back().reserve(groupsize);
        }
        (*(temp.rbegin())).push_back(*it);
        ++it;
        ++counter;
    }
    return temp;
}

void PmergeMeVector::pairAndSortGroups(std::vector< std::vector<int> > &temp, unsigned int groupsize) {
    std::stringstream debugss;
    for (std::vector< std::vector<int> >::iterator its = temp.begin(); its != temp.end(); its += 2) {
        if (its == temp.end() - 1 || (its == temp.end() - 2 && (its + 1)->size() < groupsize) )  {
            break;
        }
        ++comparisons;
        debugss << "Comparing groups: " << highlightlastnum(*(its)) << " and " << highlightlastnum(*(its + 1));
        DEBUG_PRINT(debugss.str());
        debugss.str("");
        debugss.clear();
        if(*(its->rbegin()) > (*(its + 1)->rbegin())) {
            std::iter_swap(its, its + 1);
        }
    }
}

void PmergeMeVector::labelSubGroups(std::vector<std::vector<int> > &temp, std::vector<SubGroup> &mainchain, std::vector<SubGroup> &pendchain)
{
    if (temp.size() < 2)
        return;
    mainchain.push_back(SubGroup("b1", temp[0]));
    mainchain.push_back(SubGroup("a1", temp[1]));

    unsigned int counter = 2;
    for (size_t i = 2; i < temp.size(); ++i) {
        std::stringstream ss;
        std::string tag;
        if (counter % 2 == 0) {
            ss << "b" << counter / 2 + 1;
            tag = ss.str();
            pendchain.push_back(SubGroup(tag, temp[i]));
        } else {
            ss << "a" << counter / 2 + 1;
            tag = ss.str();
            mainchain.push_back(SubGroup(tag, temp[i]));
        }
        counter++;
    }
}

void PmergeMeVector::insertFromPendChain(std::vector<SubGroup>& mainchain, std::vector<SubGroup>& pendchain) {
    unsigned int counter = 2; // skip 1 as we already have the first element in mainchain
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
}

void PmergeMeVector::fordJohnsonSort(unsigned int iteration)
{
    // Step 1: the division into the group pairs & sorting
    unsigned int groupsize = std::pow(2, iteration);

    std::stringstream debugss;
    debugss << "Propagation phase (iteration " << iteration << "): \n";
    debugss << "Group size: " << groupsize ;
    DEBUG_PRINT(debugss.str());
    debugss.str("");

    if (groupsize * 2 > vsize) {
        debugss << "With group size " << groupsize << ", unable to make pairs\nBase case reached, returning.\n";
        debugss << "\n---------------------------------------------\n";
        DEBUG_PRINT(debugss.str());
        debugss.str("");
        return;
    }
    

    std::vector< std::vector<int> > temp = groupVector(vdata, groupsize);
    DEBUG_CALL(printVVint(temp));

    pairAndSortGroups(temp, groupsize);

    // unpack the sorted groups back to vdata
    vdata.clear();
    for (std::vector< std::vector<int> >::iterator it2 = temp.begin(); it2 != temp.end(); ++it2) {
        for (std::vector<int>::iterator it3 = it2->begin(); it3 != it2->end(); ++it3) {
            vdata.push_back(*it3);
        }
    }
    debugss << "After pairing and sorting groups: " << toString() << "\n";
    DEBUG_PRINT(debugss.str());
    debugss.str("");
    debugss.clear();
    fordJohnsonSort(iteration + 1);

    // Steps 2 and 3: the initialization and insertion 

    // 2. INITIALIZATION

    debugss << "Returning phase (iteration " << iteration << "): \n";
    debugss << "Group size: " << groupsize << "\n";
    debugss << "Current sequence: " << toString() << "\n";
    DEBUG_PRINT(debugss.str());
    debugss.str("");


    // 2.0 Partitioning
    std::vector<int> copy = vdata; 
    std::vector<int> nonpart;
    unsigned int nonpartsize = copy.size() % (groupsize);
    
    if (nonpartsize > 0) {
        nonpart.insert(nonpart.end(), copy.end() - nonpartsize, copy.end());
        copy.erase(copy.end() - nonpartsize, copy.end());
    }
    temp.clear();
    temp = groupVector(copy, groupsize);

    // 2.1 Labelling
    std::vector<SubGroup> mainchain;
    std::vector<SubGroup> pendchain;

    mainchain.reserve(temp.size());
    pendchain.reserve(temp.size() / 2 + 1);
    labelSubGroups(temp, mainchain, pendchain);

    debugss << "Main chain: \n";
    for (std::vector<SubGroup>::iterator it = mainchain.begin(); it != mainchain.end(); ++it) {
        debugss << it->toStringsg() << "\n";
    }
    debugss << "\nPend chain: \n";
    for (std::vector<SubGroup>::iterator it = pendchain.begin(); it != pendchain.end(); ++it) {
        debugss << it->toStringsg() << "\n";
    }
    debugss << "\nNon-partitioned elements: ";
    if (nonpart.empty()) {
        debugss << "None";
    } else {
        debugss << "[ ";
        for (std::vector<int>::iterator it = nonpart.begin(); it != nonpart.end(); ++it) {
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
    for (std::vector<SubGroup>::iterator it = mainchain.begin(); it != mainchain.end(); ++it) {
        debugss << highlightlastnum(it->subvec) << " ";
    }
    DEBUG_PRINT(debugss.str());
    debugss.str("");

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

    debugss << "End of iteration " << iteration << " sorting: " << toString() << "\n";
    DEBUG_PRINT(debugss.str());
    debugss.str("");
    debugss.clear();
}

unsigned int PmergeMeVector::getJacobNo(unsigned int i)
{
    if (i == 0)
        return 1;
    if (i == 1)
        return 1;
    return getJacobNo(i - 1) + 2 * getJacobNo(i - 2);
}

PmergeMeVector::SubGroup::SubGroup() {}

PmergeMeVector::SubGroup::SubGroup(const SubGroup &other): tag(other.tag), lastnum(other.lastnum), subvec(other.subvec) {}

PmergeMeVector::SubGroup &PmergeMeVector::SubGroup::operator=(const SubGroup &other)
{
    if (this != &other) {
        this->tag = other.tag;
        this->lastnum = other.lastnum;
        this->subvec = other.subvec;
    }
    return *this;
}

PmergeMeVector::SubGroup::SubGroup(std::string tag, const std::vector<int> &v)
    : tag(tag), subvec(v)
{
    lastnum = 0;
    if (!v.empty()) {
        lastnum = v.back();
    }
}

PmergeMeVector::SubGroup::SubGroup(std::string tag)
: tag(tag) {}

PmergeMeVector::SubGroup::~SubGroup()
{
}

bool PmergeMeVector::SubGroup::operator==(const SubGroup &other) const
{
    return (this->tag == other.tag);
}

bool PmergeMeVector::SubGroup::operator<(const SubGroup &other) const
{
    ++PmergeMeVector::comparisons;
    return (this->lastnum < other.lastnum);
}

std::string PmergeMeVector::SubGroup::toStringsg() const
{
    std::stringstream ss;
    // ss << "Tag: " << tag << ", Last number: " << lastnum << ", Subvector: [ ";
    // for (std::vector<int>::const_iterator it = subvec.begin(); it != subvec.end(); ++it) {
    //     ss << *it << " ";
    // }
    // ss << "]";
    ss << tag << " ->\t" << highlightlastnum(subvec);
    return ss.str();
}

