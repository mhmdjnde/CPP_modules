#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Span{
    private:
        unsigned int N;
        std::vector<int> data;
    public:
        Span(unsigned int n);
        Span(const Span &other);
        ~Span();
        Span &operator=(Span &other);
        void addNumber(int value);
        int shortestSpan();
        int longestSpan();

        class OutOfRangeException : public std::exception {
            const char* what() const throw()
            {
                return "Span is out of range";
            }
        };

        class NoSpanAvailable : public std::exception {
            const char* what() const throw()
            {
                return "can't find a Span";
            }
        };
};

#endif
