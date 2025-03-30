#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    std::vector<int>::iterator it_vec = easyfind(vec, 3);
    if (it_vec != vec.end()) std::cout << "Found in vector: " << *it_vec << "\n";
    else std::cout << "Not found in vector\n";

    std::deque<int> deq;
    deq.push_back(10);
    deq.push_back(20);
    deq.push_back(30);
    deq.push_back(40);
    deq.push_back(50);
    std::deque<int>::iterator it_deq = easyfind(deq, 25);
    if (it_deq != deq.end()) std::cout << "Found in deque: " << *it_deq << "\n";
    else std::cout << "Not found in deque\n";

    std::list<int> lst;
    lst.push_back(100);
    lst.push_back(200);
    lst.push_back(300);
    std::list<int>::iterator it_lst = easyfind(lst, 200);
    if (it_lst != lst.end()) std::cout << "Found in list: " << *it_lst << "\n";
    else std::cout << "Not found in list\n";

    return 0;
}