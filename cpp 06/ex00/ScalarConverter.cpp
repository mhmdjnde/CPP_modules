#include "ScalarConverter.hpp"
#include <sstream>

ScalarConverter::ScalarConverter(){
}

ScalarConverter::~ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter& other){
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
    (void)other;
    return *this;
}

void ScalarConverter::convert(const std::string& str)
{
    try {
        if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
        {
            char c = str[0];
            std::cout << "char: '" << c << "'\n";
            std::cout << "int: " << static_cast<int>(c) << "\n";
            std::cout << "float: " << static_cast<float>(c) << ".0f\n";
            std::cout << "double: " << static_cast<double>(c) << ".0\n";
            return;
        }

        std::istringstream iss(str);
        int i;
        if (iss >> i)
        {
            std::cout << "char: ";
            if (i >= 32 && i <= 126)
                std::cout << "'" << static_cast<char>(i) << "'\n";
            else
                std::cout << "Non displayable\n";
            std::cout << "int: " << i << "\n";
            std::cout << "float: " << static_cast<float>(i) << ".0f\n";
            std::cout << "double: " << static_cast<double>(i) << ".0\n";
            return;
        }
        std::istringstream iss_float(str);
        float f;
        if (iss_float >> f)
        {
            std::cout << "char: ";
            if (f >= 32 && f <= 126 && (f == static_cast<int>(f)))
                std::cout << "'" << static_cast<char>(f) << "'\n";
            else
                std::cout << "Non displayable\n";

            std::cout << "int: ";
            if (f >= -2147483648 && f <= 2147483647)
                std::cout << static_cast<int>(f) << "\n";
            else
                std::cout << "Impossible\n";

            std::cout << "float: " << f << "f\n";
            std::cout << "double: " << static_cast<double>(f) << "\n";
            return;
        }
        std::istringstream iss_double(str);
        double d;
        if (iss_double >> d)
        {
            std::cout << "char: ";
            if (d >= 32 && d <= 126 && (d == static_cast<int>(d)))
                std::cout << "'" << static_cast<char>(d) << "'\n";
            else
                std::cout << "Non displayable\n";

            std::cout << "int: ";
            if (d >= -2147483648 && d <= 2147483647)
                std::cout << static_cast<int>(d) << "\n";
            else
                std::cout << "Impossible\n";

            std::cout << "float: " << static_cast<float>(d) << "f\n";
            std::cout << "double: " << d << "\n";
            return;
        }
        std::cout << "Impossible\n";
    } catch (...)
    {
        std::cout << "char: Impossible\n";
        std::cout << "int: Impossible\n";
        std::cout << "float: Impossible\n";
        std::cout << "double: Impossible\n";
    }
}
