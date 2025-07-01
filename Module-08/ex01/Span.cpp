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

int Span::shortestSpan() const
{
    if (this->numbers.size() < 2)
    {
        throw SpanTooSmallException();
    }
    std::vector<int> sortedNumbers = this->numbers;
    std::vector<int> differences(sortedNumbers.size());
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    std::adjacent_difference(sortedNumbers.begin(), sortedNumbers.end(), differences.begin());
    int min = *std::min_element(differences.begin(), differences.end());
    return min;
}

int Span::longestSpan() const
{
    if (this->numbers.size() < 2)
    {
        throw SpanTooSmallException();
    }
    int max = *std::max_element(this->numbers.begin(), this->numbers.end()) - *std::min_element(this->numbers.begin(), this->numbers.end());
    return max;
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
  
