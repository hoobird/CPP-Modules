#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>

class Span {
    public:
        Span(unsigned int N);
        Span(const Span &other);
        ~Span();
        Span &operator=(const Span &other);

        unsigned int getN() const;
        const std::vector<int>& getNumbers() const;

        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;

        class SpanAlreadyFullException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Span is already full";
                }
        };
    
        class SpanTooSmallException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Not enough numbers to find span";
                }
        };

        class SpanRangeTooLargeException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Range is too large to add to span";
                }
        };

        template <typename T>
        void addRange(T begin, T end) {
            // Returns the number of hops from first to last.
            if (std::distance(begin, end) + numbers.size() > N) {
                throw SpanRangeTooLargeException();
            }
            numbers.insert(numbers.end(), begin, end);
        }
        
        private:
        Span();
        unsigned int N;
        std::vector<int> numbers;
        
        
};

std::ostream &operator<<(std::ostream &o, const Span &s);  
#endif

// Refernence:
// https://cplusplus.com/reference/iterator/distance/
// https://cplusplus.com/reference/vector/vector/insert/