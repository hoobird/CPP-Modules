#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array 
{
    public:
        Array() : arr(NULL), len(0) {}
        
        Array(unsigned int n) : len(n) {
            this->arr = new T[n]();
        }
        
        Array(const Array &other) {
            this->arr = NULL;
            *this = other;
        }
        
        ~Array() {
            delete[] this->arr;
        }
        
        Array &operator=(const Array &other) {
            if (this != &other)
            {
                delete[] this->arr;
                this->len = other.len;
                this->arr = new T[this->len]();
                for (unsigned int i = 0; i < this->len; i++)
                    this->arr[i] = other.arr[i];
            }
            return *this;
        }
        
        T& operator[](unsigned int i) {
            if (i >= this->len)
                throw std::exception();
            return this->arr[i];
        }
        
        const T& operator[](unsigned int i) const {
            if (i >= this->len)
                throw std::exception();
            return this->arr[i];
        }
        
        unsigned int size() const {
            return this->len;
        }
    
    private:
        T* arr;
        unsigned int len;
};

#endif
