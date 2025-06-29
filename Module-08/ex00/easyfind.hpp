#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

// template <typename T, typename U = typename T::iterator>
template <typename T>
void easyfind(T t, int i)
{
    typename T::iterator it = std::find(t.begin(), t.end(), i);
    if (it != t.end())
    {
        std::cout << "Value found: " << *it << std::endl;
        return;
    }
    std::cout << "Error: Value not found" << std::endl;
    return;
}

#endif