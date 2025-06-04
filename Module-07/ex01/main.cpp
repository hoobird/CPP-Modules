#include "iter.hpp"
#include <iostream>

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

template < typename T> 
void plus5(T &x )
{
  x+=5;
  return;
}

int main() {
  int numbers[] = { 10, 11, 12, 13, 14 };
  char letters[] = { 'a','b','c','d','e','f' };

  std::cout << "Before" << std::endl;
  iter( numbers, 5, print<int> );
  iter( letters, 5, print<char> );
  std::cout << "\nAdding 5 to both array values" << std::endl;
  iter( numbers, 5, plus5<int> );
  iter( letters, 5, plus5<char> );
  std::cout << "\nAfter" << std::endl;
  iter( numbers, 5, print<int> );
  iter( letters, 5, print<char> );

  return 0;
}
