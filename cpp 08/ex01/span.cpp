#include "span.hpp"

Span::Span(unsigned int n)
{
    N = n;
    std::cout << "Span constructor called" << std::endl;
}

Span::Span(const Span &other)
{
    N = other.N;
    data = other.data;
    std::cout << "Span copy constructor called" << std::endl;
}
Span::~Span()
{
    std::cout << "Span destructor called" << std::endl;
}

Span& Span::operator=(Span &other)
{
    if (this != &other)
    {
        N = other.N;
        data = other.data;
    }
    return *this;
}

void    Span::addNumber(int value)
{
    try{
        if (data.size() < N)
            data.push_back(value);
        else
            throw OutOfRangeException();
    } catch (...){}
}

int Span::longestSpan()
{
    try
    {
        if (data.size() < 2)
            throw OutOfRangeException();
        else
            return *std::max_element(data.begin(), data.end()) - *std::min_element(data.begin(), data.end());
    }
    catch(...)
    {
        return -1;
    }
}

int Span::shortestSpan()
{
    std::vector<int> temp = data;
    std::sort(temp.begin(), temp.end());
    try
    {
        if (data.size() < 2)
            throw OutOfRangeException();
        else
        {
            int shortest = INT_MAX;
            for (std::vector<int>::iterator it = temp.begin(); it != temp.end() - 1; ++it)
            {
                int diff = *(it + 1) - *it;
                if (diff < shortest)
                    shortest = diff;
            }
            return shortest;
        }
    }
    catch (...)
    {
        return -1;
    }
}

