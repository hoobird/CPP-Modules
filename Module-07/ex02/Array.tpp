#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array(): arr(NULL), len(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : len(n)
{
    this->arr = new T[n]();
}


template <typename T>
Array<T>::Array(const Array &other)
{
    this->arr = NULL;
    *this = other;
}

template <typename T>
Array<T>::~Array()
{
    delete[] this->arr;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
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

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (i >= this->len)
        throw std::exception();
    return this->arr[i];
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
    if (i >= this->len)
        throw std::exception();
    return this->arr[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return this->len;
}

#endif