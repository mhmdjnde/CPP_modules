#include <list>
#include <utility>
#include <iostream>
#include <algorithm> // for std::swap
#include <iterator>  // for std::distance, std::advance
#include <vector>    // <<-- ADDED for std::vector in C++98

int extraList;
extern int comp_count;

// C++98 does not provide std::next, so we define a small helper:
inline std::list<int>::iterator myNext(std::list<int>::iterator it, int n)
{
    while (n-- > 0)
        it++;
    return it;
}

// This function is used to sort the list of pairs by the second element of each pair
// (where each pair is already sorted before, so by the max of each pair).
void MergeSortBySecond(std::list<std::pair<int, int> >& ListPair)
{
    int n = ListPair.size();
    if (n <= 1)
        return;
    std::vector<std::pair<int, int> > VecPair;
    VecPair.reserve(n);
    for (std::list<std::pair<int,int> >::iterator it = ListPair.begin(); it != ListPair.end(); it++)
        VecPair.push_back(*it);
    std::vector<std::pair<int, int> > temp(n);
    for (int width = 1; width < n; width *= 2)
    {
        for (int i = 0; i < n; i += 2 * width)
        {
            int left  = i;
            int mid   = i + width;
            int right = i + 2 * width;
            if (mid > n)   mid = n;
            if (right > n) right = n;

            int leftPos  = left;
            int rightPos = mid;
            int merged   = left;
            while (leftPos < mid && rightPos < right)
            {
                comp_count++;
                if (VecPair[leftPos].second <= VecPair[rightPos].second)
                    temp[merged++] = VecPair[leftPos++];
                else
                    temp[merged++] = VecPair[rightPos++];
            }
            while (leftPos < mid)
                temp[merged++] = VecPair[leftPos++];
            while (rightPos < right)
                temp[merged++] = VecPair[rightPos++];
        }
        for (int j = 0; j < n; j++)
            VecPair[j] = temp[j];
    }
    std::list<std::pair<int,int> >::iterator lit = ListPair.begin();
    for (int k = 0; k < n; ++k, ++lit)
        *lit = VecPair[k];
}

// This will split the list into pairs and sort each pair apart
std::list<std::pair<int,int> > SortedPairsList(std::list<int> &lst)
{
    std::list<std::pair<int,int> > ListPairs;
    
    if (lst.size() % 2 == 1)
    {
        extraList = lst.back();
        lst.pop_back();
    }
    else
        extraList = -1;
    std::list<int>::iterator it = lst.begin();
    while (it != lst.end())
    {
        int firstVal = *it;
        it++;
        int secondVal = *it;
        it++;
        comp_count++;
        if (firstVal > secondVal)
            std::swap(firstVal, secondVal);

        ListPairs.push_back(std::make_pair(firstVal, secondVal));
    }
    MergeSortBySecond(ListPairs);
    return ListPairs;
}

// This will return the jacobthalNum depending on the size
int jacobthalNum(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int prev2 = 0, prev1 = 1, curr = 0;
    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

// Return the sequence of JacobthalIndices from 3 to the list size
// (we will store them in a list to keep usage consistent)
std::list<int> JacobthalIndices(int size)
{
    std::list<int> jacobSequence;
    int jacobIndex = 3;
    while (jacobthalNum(jacobIndex) <= size)
    {
        jacobSequence.push_back(jacobthalNum(jacobIndex));
        jacobIndex++;
    }
    return jacobSequence;
}

// Here we will use the JacobThalIndices to build the list of optimal indices
// to parse the "pend" list
std::list<int> PendInsertIndices(std::list<int> &pend)
{
    std::list<int> pend_Indices;
    if (pend.size() == 1)
        return pend_Indices;

    std::list<int> jacobIndices = JacobthalIndices(pend.size());
    std::list<int>::iterator it = jacobIndices.begin();
    int prev = 1;
    while (it != jacobIndices.end())
    {
        int now = *it;
        while (now > prev)
        {
            pend_Indices.push_back(now);
            now--;
        }
        prev = *it;
        it++;
    }
    int last = pend.size();
    while (last > prev)
    {
        pend_Indices.push_back(last);
        last--;
    }
    return pend_Indices;
}

// Here is the binaryInsert part using the indices sequence that were
// built with the JacobIndices, except we use list iterators.
int binaryInsert(std::list<int>& mainList, int pendValue, int high)
{
    std::vector<int> temp;
    temp.reserve(high + 1);

    std::list<int>::iterator it = mainList.begin();
    for (int i = 0; i <= high && it != mainList.end(); ++i, it++)
        temp.push_back(*it);

    int low = 0;
    int h = high;
    int mid;
    while (low < h)
    {
        mid = (low + h) / 2;
        comp_count++;
        if (temp[mid] == pendValue)
            return mid;
        else if (temp[mid] > pendValue)
            h = mid - 1;
        else
            low = mid + 1;
    }
    if (low < (int)temp.size())
    {
        if (pendValue < temp[low])
            return low;
        else
            return low + 1;
    }
    return low;
}

// Main sortList functionality
void SortList(std::list<int> &lst)
{
    comp_count = 0;
    int high = 3;
    std::list<std::pair<int,int> > pairs = SortedPairsList(lst);
    std::list<int> mainList;
    std::list<int> pend;
    for (std::list<std::pair<int,int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        mainList.push_back(it->second);
        pend.push_back(it->first);
    }
    std::cout << std::endl;
    std::list<int> pend_Indices = PendInsertIndices(pend);
    mainList.push_front(pend.front());
    std::list<int>::iterator idxIt = pend_Indices.begin();
    for (int i = 0; i < (int)pend_Indices.size(); i++, ++idxIt)
    {
        if (i > 0)
        {
            std::list<int>::iterator prevIt = idxIt;
            --prevIt;
            if (*idxIt > *prevIt)
                high = 2 * high + 1;
        }
        if (high > (int)mainList.size())
            high = mainList.size();
        int position = binaryInsert(mainList,
                                    *myNext(pend.begin(), (*idxIt) - 1),
                                    (int)high - 1);
        std::list<int>::iterator insertIt = mainList.begin();
        std::advance(insertIt, position);
        mainList.insert(insertIt, *myNext(pend.begin(), (*idxIt) - 1));
    }
    if (extraList != -1)
    {
        int position = binaryInsert(mainList, extraList, mainList.size() - 1);
        std::list<int>::iterator insertIt = mainList.begin();
        std::advance(insertIt, position);
        mainList.insert(insertIt, extraList);
    }
    lst.clear();
    for (std::list<int>::iterator it = mainList.begin(); it != mainList.end(); it++)
        lst.push_back(*it);
}
