#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
private:
    T* elements;
    unsigned int size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();
    unsigned int getsize() const;
    T& operator[](unsigned int index);
    class OutOfBoundsException : public std::exception
    {
    public:
        virtual const char* what() const throw() {
            return "Index out of bounds!";
        }
    };
};

#include "Array.tpp"

#endif
