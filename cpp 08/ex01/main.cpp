#include "span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span largeSpan = Span(10000);
    for (int i = 0; i < 10000; ++i) {
        largeSpan.addNumber(i);
    }
    std::cout << "Shortest span for 10,000 numbers: " << largeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span for 10,000 numbers: " << largeSpan.longestSpan() << std::endl;

    Span randomSpan = Span(10000);
    for (int i = 0; i < 10000; ++i) {
        randomSpan.addNumber(rand() % 100000); // Random values between 0 and 99,999
    }
    std::cout << "Shortest span for random 10,000 numbers: " << randomSpan.shortestSpan() << std::endl;
    std::cout << "Longest span for random 10,000 numbers: " << randomSpan.longestSpan() << std::endl;

    Span smallSpan = Span(3);
    smallSpan.addNumber(1);
    smallSpan.addNumber(10);
    smallSpan.addNumber(100);
    std::cout << "Shortest span for small span: " << smallSpan.shortestSpan() << std::endl;
    std::cout << "Longest span for small span: " << smallSpan.longestSpan() << std::endl;

    Span emptySpan = Span(0);
    try {
        emptySpan.shortestSpan();
    } catch (const std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    try {
        emptySpan.longestSpan();
    } catch (const std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
