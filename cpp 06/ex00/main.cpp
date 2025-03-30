#include "ScalarConverter.hpp"
#include <iostream>

int main() {
    ScalarConverter::convert("c");
    ScalarConverter::convert("42");
    ScalarConverter::convert("-42");
    ScalarConverter::convert("42.42f");
    ScalarConverter::convert("-42.42f");
    ScalarConverter::convert("42.0");
    ScalarConverter::convert("-42.0");
    ScalarConverter::convert("nan");
    ScalarConverter::convert("+inf");
    ScalarConverter::convert("-inf");
    ScalarConverter::convert("non_numeric");
    ScalarConverter::convert("1e10f");
    ScalarConverter::convert("999999999999");

    return 0;
}
