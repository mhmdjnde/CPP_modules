#include "Array.hpp"

int main()
{
    try
    {
        Array<int> intArray(5);
        for (unsigned int i = 0; i < intArray.getsize(); i++)
        {
            intArray[i] = i * 2;
        }
        for (unsigned int i = 0; i < intArray.getsize(); i++)
        {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;
        std::cout << intArray[10] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
