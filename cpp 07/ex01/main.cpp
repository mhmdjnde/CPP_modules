#include "iter.hpp"

void incrementFloat(float &num)
{
    num += 0.5;
}

void toUpperCase(std::string &str)
{
    for (int i = 0 ; str[i] != '\0' ; i++)
        str[i] = std::toupper(str[i]);
}

int main()
{
    float floatArray[] = {1.5, 2.3, 3.7, 4.4, 5.8};
    int floatArrayLen = sizeof(floatArray) / sizeof(floatArray[0]);

    std::cout << "Float array before: ";
    for (int i = 0; i < floatArrayLen; ++i)
        std::cout << floatArray[i] << " ";
    std::cout << std::endl;

    iter(floatArray, floatArrayLen, incrementFloat);

    std::cout << "Float array after: ";
    for (int i = 0; i < floatArrayLen; ++i)
        std::cout << floatArray[i] << " ";
    std::cout << std::endl;

    std::string strArray[] = {"hello", "world", "cpp", "iter", "template"};
    int strArrayLen = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "String array before: ";
    for (int i = 0; i < strArrayLen; ++i)
        std::cout << strArray[i] << " ";
    std::cout << std::endl;

    iter(strArray, strArrayLen, toUpperCase);

    std::cout << "String array after: ";
    for (int i = 0; i < strArrayLen; ++i)
        std::cout << strArray[i] << " ";
    std::cout << std::endl;

    return 0;
}
