#include "Span.hpp"

Span::Span() {};

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span &other) : N(other.N), numbers(other.numbers) {}

Span::~Span() {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->N = other.N;
        this->numbers = other.numbers;
    }
    return *this;
}

unsigned int Span::getN() const
{
    return this->N;
}

const std::vector<int> &Span::getNumbers() const
{
    return this->numbers;
}

void Span::addNumber(int number)
{
    if (this->numbers.size() >= N)
    {
        throw SpanAlreadyFullException();
    }
    this->numbers.push_back(number);
}

#include <iostream>
int Span::shortestSpan() const
{
    if (this->numbers.size() < 2)
    {
        throw SpanTooSmallException();
    }

    std::vector<int>::const_iterator it = this->numbers.begin();
    std::vector<int>::const_iterator end = this->numbers.end();
    int x = *it;
    int y = *(++it);
    int minspan = abs(y - x);
    it++;
    for (; it != end; ++it)
    {
        x = y;
        y = *it;
        int diff = abs(y - x);
        if (diff < minspan)
            minspan = diff;
    }
    return minspan;
}

int Span::longestSpan() const
{
    if (this->numbers.size() < 2)
    {
        throw SpanTooSmallException();
    }

    std::vector<int>::const_iterator it = this->numbers.begin();
    std::vector<int>::const_iterator end = this->numbers.end();
    int x = *it;
    int y = *(++it);
    int maxspan = abs(y - x);
    it++;
    for (; it != end; ++it)
    {
        x = y;
        y = *it;
        int diff = abs(y - x);
        if (diff > maxspan)
            maxspan = diff;
    }
    return maxspan;
}

std::ostream &operator<<(std::ostream &o, const Span &s)
{
    o << "Span (No of elements: " << s.getNumbers().size() << ", Capacity: " << s.getN() << ")\n";
    o << "Numbers: ";
    const std::vector<int> &nums = s.getNumbers();
    for (std::vector<int>::const_iterator it = nums.begin(); it != nums.end(); ++it) {
        o << *it << " ";
    }
    o << "\n";
    return o;
}
  
