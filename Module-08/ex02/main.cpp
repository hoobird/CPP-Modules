#include "MutantStack.hpp"
#include "iostream"
#include <list>

void mutantStackDefaultExample();
void listDefaultExample();
void mutantStackMyExample();
void listMyExample();

int main() {

    //comment what u dont want to run
    mutantStackDefaultExample();
    listDefaultExample();
    mutantStackMyExample();
    listMyExample();
    
    return 0;
}

void mutantStackDefaultExample() {
    std::cout << "\n=== Running MutantStack Example ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
}

void listDefaultExample() {
    std::cout << "\n=== Running List Example ===" << std::endl;
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << mlist.size() << std::endl;
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);
    std::list<int>::iterator it = mlist.begin();
    std::list<int>::iterator ite = mlist.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int, std::list<int> > s(mlist);
}

void mutantStackMyExample() {
    std::cout << "\n=== Running My MutantStack Example ===" << std::endl;
    MutantStack<int> mstack;
    for (int i = 42; i < 56; ++i) {
        mstack.push(i);
    }
    std::cout << mstack << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;
    std::cout << "Top: " << mstack.top() << std::endl;
    std::cout << std::endl;
    const MutantStack<int> const_mstack(mstack);

    std::cout << "Normal Iterator" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    std::cout << "Const Iterator" << std::endl;
    MutantStack<int>::const_iterator cit = const_mstack.begin();
    MutantStack<int>::const_iterator cite = const_mstack.end();
    while (cit != cite) {
        std::cout << *cit << " ";
        ++cit;
    }
    std::cout << std::endl;

    std::cout << "Reverse Iterator" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite) {
        std::cout << *rit << " ";
        ++rit;
    }
    std::cout << std::endl;

    std::cout << "Const Reverse Iterator" << std::endl;
    MutantStack<int>::const_reverse_iterator crit = const_mstack.rbegin();
    MutantStack<int>::const_reverse_iterator crite = const_mstack.rend();
    while (crit != crite) {
        std::cout << *crit << " ";
        ++crit;
    }
    std::cout << std::endl;
    
}

std::ostream& operator<<(std::ostream& os, const std::list<int>& mlist) {
    os << "List contents: ";
    for (std::list<int>::const_iterator it = mlist.begin(); it != mlist.end(); ++it) {
        os << *it << " ";
    }
    return os;
}

void listMyExample() {
    std::cout << "\n=== Running My list Example ===" << std::endl;
    std::list<int> mlist;
    for (int i = 42; i < 56; ++i) {
        mlist.push_back(i);
    }
    std::cout << mlist << std::endl;
    std::cout << "Size: " << mlist.size() << std::endl;
    std::cout << "Top: " << mlist.back() << std::endl;
    std::cout << std::endl;
    const std::list<int> const_mlist(mlist);

    std::cout << "Normal Iterator" << std::endl;
    std::list<int>::iterator it = mlist.begin();
    std::list<int>::iterator ite = mlist.end();
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    std::cout << "Const Iterator" << std::endl;
    std::list<int>::const_iterator cit = const_mlist.begin();
    std::list<int>::const_iterator cite = const_mlist.end();
    while (cit != cite) {
        std::cout << *cit << " ";
        ++cit;
    }
    std::cout << std::endl;

    std::cout << "Reverse Iterator" << std::endl;
    std::list<int>::reverse_iterator rit = mlist.rbegin();
    std::list<int>::reverse_iterator rite = mlist.rend();
    while (rit != rite) {
        std::cout << *rit << " ";
        ++rit;
    }
    std::cout << std::endl;

    std::cout << "Const Reverse Iterator" << std::endl;
    std::list<int>::const_reverse_iterator crit = const_mlist.rbegin();
    std::list<int>::const_reverse_iterator crite = const_mlist.rend();
    while (crit != crite) {
        std::cout << *crit << " ";
        ++crit;
    }
    std::cout << std::endl;
}