#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

// template <typename T, typename U = typename T::iterator>
template <typename T>
void easyfind(T t, int i)
{
    typename T::iterator first = t.begin();
    typename T::iterator last = t.end();
    typename T::iterator it = first;
    while (it != last)
    {
        if (*it == i)
        {
            std::cout << "Found value: " << *it << std::endl;
            return;
        }
        ++it;
    }
    std::cout << "Error: Value not found" << std::endl;
    return;
}

#endif