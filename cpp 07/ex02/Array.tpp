#include "Array.hpp"

template <typename T>
Array<T>::Array() : elements(NULL), size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]), size(n)
{}

template <typename T>
Array<T>::Array(const Array& other) : elements(NULL), size(0)
{
    *this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] elements;
        size = other.size;
        elements = new T[size];
        for (unsigned int i = 0; i < size; i++)
        {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] elements;
}

template <typename T>
unsigned int Array<T>::getsize() const
{
    return size;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= size)
    {
        throw OutOfBoundsException();
    }
    return elements[index];
}
