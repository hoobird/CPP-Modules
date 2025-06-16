#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    // Normal Case
    std::cout << "Normal Case" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    std::cout << sp << std::endl;


    std::cout << std::endl;
    // Exception Case: Span is already full
    std::cout << "Exception Case: Span is already full" << std::endl;
    Span sp2 = Span(5);
    try {
        sp2.addNumber(1);
        sp2.addNumber(2);
        sp2.addNumber(3);
        sp2.addNumber(4);
        sp2.addNumber(5);
        sp2.addNumber(6); // Explosion boom
    } catch (const Span::SpanAlreadyFullException &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << sp2 << std::endl;


    std::cout << std::endl;

    // Exception Case: Not enough numbers to find span
    std::cout << "Exception Case: Not enough numbers" << std::endl; 
    Span sp3 = Span(1);
    try {
        sp3.addNumber(42);
        std::cout << "Shortest Span: " << sp3.shortestSpan() << std::endl; // Explosion boom
    } catch (const Span::SpanTooSmallException &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << "Longest Span: " << sp3.longestSpan() << std::endl; // Explosion boom
    } catch (const Span::SpanTooSmallException &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << sp3 << std::endl;

    std::cout << std::endl;


    // Go crazy 10000 numbers
    std::cout << "Go crazy 10000 numbers" << std::endl;
    Span sp4 = Span(10000);
    std::srand(std::time(0));
    for (int i = 0; i < 10000; ++i) {
        sp4.addNumber(std::rand() % 100000);
    }
    try {
        std::cout << "Shortest Span: " << sp4.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp4.longestSpan() << std::endl;
    } catch (const Span::SpanTooSmallException &e) {
        std::cout << e.what() << std::endl;
    }

    // std::cout << sp4 << std::endl; // Uncomment this to print all 10000 numbers

    std::cout << std::endl;


    // Test addRange
    std::cout << "Test addRange" << std::endl;
    Span sp5 = Span(10);
    sp5.addNumber(2);
    sp5.addNumber(4);
    sp5.addNumber(6);
    sp5.addNumber(8);
    sp5.addNumber(10);
    std::vector<int> vec; 
    for (int i = 15; i <= 40; i+=5) { // 6 numbers
        vec.push_back(i);
    }
    try {
        sp5.addRange(vec.begin(), vec.end()); // should fail
    } catch (const Span::SpanRangeTooLargeException &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "Remove first element in vector, 5 numbers left" << std::endl;
    vec.erase(vec.begin()); // Remove the first element to make it 5 numbers
    try {
        sp5.addRange(vec.begin(), vec.end()); // should succeed
    } catch (const Span::SpanRangeTooLargeException &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << sp5 << std::endl;

    return 0;
}