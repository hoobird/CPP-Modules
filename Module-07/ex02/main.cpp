#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

template <typename T>
void printArray(const Array<T>& arr, const std::string& prefix) {
    std::cout << prefix << " (size=" << arr.size() << "): ";
    for (unsigned int i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i < arr.size() - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

int main()
{
    std::srand(std::time(0));
    
    std::cout << "=== Testing Array of integers ===" << std::endl;
    // Empty int array
    Array<int> emptyInts;
    std::cout << "Empty array size: " << emptyInts.size() << std::endl;
    
    // size 20 array
    Array<int> numbers(20);
    
    // Fill with random values
    for (unsigned int i = 0; i < 20; i++) {
        numbers[i] = std::rand() % 100;
    }
    printArray(numbers, "Numbers");
    
    // Copy constructor
    Array<int> numbersCopy(numbers);
    printArray(numbersCopy, "Numbers copy");
    
    // Test deep copy
    numbers[0] = 999;
    std::cout << "After modifying original" << std::endl;
    printArray(numbers, "Original");
    printArray(numbersCopy, "Copy");
    
    // Assignment operator
    Array<int> assigned;
    assigned = numbers;
    printArray(assigned, "Assigned");
    
    // Exception test
    std::cout << "\nTesting exceptions:" << std::endl;
    try {
        std::cout << "Accessing index -1: ";
        std::cout << numbers[-1] << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "Accessing index " << numbers.size() << ": ";
        std::cout << numbers[numbers.size()] << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    


    std::cout << "\n=== Testing Array of strings ===" << std::endl;
    
    Array<std::string> fruits(5);
    fruits[0] = "Apple";
    fruits[1] = "Banana";
    fruits[2] = "Cherry";
    fruits[3] = "Durian";
    fruits[4] = "Elderberry";
    
    printArray(fruits, "Fruits");
    
    // Copy constructor
    Array<std::string> fruitsCopy(fruits);
    
    // Test deep copy
    fruits[0] = "Avocado";
    std::cout << "After modifying original" << std::endl;
    printArray(fruits, "Original");
    printArray(fruitsCopy, "Copy");
    
    // Test const array access
    const Array<std::string> constFruits = fruits;
    std::cout << "\nTesting const array: " << constFruits[2] << std::endl;
    
    return 0;
}
