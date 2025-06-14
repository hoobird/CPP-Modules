#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>


int main() {

    std::cout << "\nVector test:" << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }   
    easyfind(vec, 0); // can find
    easyfind(vec, 2); // can find
    easyfind(vec, 20); //cannot find
    easyfind(vec, 10); // cannot find
    easyfind(vec, -1); // cannot find

    // Deque test
    std::cout << "\nDeque test:" << std::endl;
    std::deque<int> deq;
    for (int i = 20; i < 30; i++) {
        if (i % 2 == 0) {
            deq.push_back(i);
        } else {
            deq.push_front(i);
        }
    }
    easyfind(deq, 20); // can find
    easyfind(deq, 25); // can find
    easyfind(deq, 30); // cannot find
    easyfind(deq, 15); // cannot find
    easyfind(deq, -5); // cannot find
    
    // List test
    std::cout << "\nList test:" << std::endl;
    std::list<int> lst;
    for (int i = 30; i < 40; i++) {
        lst.push_back(i);
    }
    easyfind(lst, 30); // can find
    easyfind(lst, 35); // can find
    easyfind(lst, 40); // cannot find
    easyfind(lst, 25); // cannot find
    easyfind(lst, -10); // cannot find
   
    return 0;

}