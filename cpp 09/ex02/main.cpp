#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cctype>

int comp_count = 0;

//checks if the vector of numbers if sorted or not
bool isSortedVector(const std::vector<int>& vec)
{
    for (size_t i = 1; i < vec.size(); i++)
    {
        if (vec[i - 1] > vec[i])
        {
            return false;
        }
    }
    return true;
}

//checks if the list of numbers if sorted or not
bool isSortedList(const std::list<int>& lst)
{
    if (lst.empty()) return true;

    std::list<int>::const_iterator it = lst.begin();
    std::list<int>::const_iterator nextIt = it;
    nextIt++;

    while (nextIt != lst.end())
    {
        if (*it > *nextIt)
        {
            return false;
        }
        it++;
        nextIt++;
    }
    return true;
}

//sort the vector, calculate and display the time taken using clock()
void sortVectorAndDisplay(std::vector<int>& input)
{
    std::cout << "before: ";
    for (size_t i = 0; i < input.size(); i++)
    {
        std::cout << input[i] << " ";
    }
    clock_t start = clock();
    if (input.size() > 1)
        SortVec(input);
    clock_t end = clock();
    std::cout << std::endl << "after: ";
    for (size_t i = 0; i < input.size(); i++)
    {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl << "Time to process a range of 5 elements with std::vector : "
              << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6
              << " us" << std::endl;
    std::cout << "is vector sorted? " << isSortedVector(input) << std::endl;
}

//sort the list, calculate and display the time taken using clock()
void sortListAndDisplay(std::list<int>& input)
{
    clock_t start = clock();
    if (input.size() > 1)
        SortList(input);
    clock_t end = clock();
    std::cout << std::endl << "after: ";
    for (std::list<int>::iterator it = input.begin(); it != input.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl << "Time to process a range of 5 elements with std::list : "
              << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6
              << " us" << std::endl;
              std::cout << "is list sorted? " << isSortedList(input) << std::endl;
}

//take the av from the user and checks that everything entered is number (no leters...)
int input_check(char **av)
{
    for (int i = 1; av[i]; i++)
    {
        const char *arg = av[i];
        std::string number;
        for (int j = 0; arg[j] != '\0'; j++)
        {
            if (std::isspace(arg[j]))
            {
                if (!number.empty())
                {
                    if (number[0] == '-' && number.size() == 1)
                    {
                        std::cout << "Error" << std::endl;
                        return 0;
                    }
                    for (size_t k = 0; k < number.size(); k++)
                    {
                        if (!std::isdigit(number[k]) && !(k == 0 && number[k] == '-'))
                        {
                            std::cout << "Error" << std::endl;
                            return 0;
                        }
                    }
                    int num = std::atoi(number.c_str());
                    if (num < 0)
                    {
                        std::cout << "Error." << std::endl;
                        return 0;
                    }
                    number.clear();
                }
            }
            else
            {
                number += arg[j];
            }
        }
        if (!number.empty())
        {
            if (number[0] == '-' && number.size() == 1)
            {
                std::cout << "Error" << std::endl;
                return 0;
            }
            for (size_t k = 0; k < number.size(); k++)
            {
                if (!std::isdigit(number[k]) && !(k == 0 && number[k] == '-'))
                {
                    std::cout << "Error" << std::endl;
                    return 0;
                }
            }
            int num = std::atoi(number.c_str());
            if (num < 0 || num > 2147483647)
            {
                std::cout << "Error" << std::endl;
                return 0;
            }
        }
    }
    return 1;
}

// take the user's input and push them into the data vector 
//to start the sorting proccess
void parseInput(char **av, std::vector<int> &data)
{
    for (int i = 1; av[i]; i++)
    {
        const char *arg = av[i];
        std::string number;
        for (int j = 0; arg[j] != '\0'; j++)
        {
            if (std::isspace(arg[j]))
            {
                if (!number.empty())
                {
                    data.push_back(std::atoi(number.c_str()));
                    number.clear();
                }
            }
            else
            {
                number += arg[j];
            }
        }
        if (!number.empty())
        {
            data.push_back(std::atoi(number.c_str()));
        }
    }
}

int main(int ac, char** av)
{
    if (ac < 2)
    {
        std::cout << "Error: No input provided." << std::endl;
        return 1;
    }

    std::vector<int> numbers;
    std::list<int> numberList;

    if (input_check(av) == 0)
        return 0;

    parseInput(av, numbers);

    if (isSortedVector(numbers) == true)
    {
        std::cout << "already sorted: ";
        for (size_t i = 0; i < numbers.size(); i++)
        {
            std::cout << numbers[i] << " ";
        }
        return (0);
    }
    for (size_t i = 0; i < numbers.size(); i++)
    {
        numberList.push_back(numbers[i]);
    }
    sortVectorAndDisplay(numbers);
    std::cout << "vector comparision: " << comp_count << std::endl;
    sortListAndDisplay(numberList);
    std::cout << "list comparision: " << comp_count << std::endl;

    return 0;
}
