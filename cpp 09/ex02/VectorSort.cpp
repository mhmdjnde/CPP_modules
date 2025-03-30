#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <utility>

int extra;
extern int comp_count;

#include <vector>

//this function is used to sort the vector of paires by the second
//element of each pair (where each pair is already sorted before, so by te max of each pair)
void MergeSortBySecond(std::vector<std::pair<int, int> >& VecPair)
{
    int n = VecPair.size();
    if (n <= 1)
    {
        return;
    }
    std::vector<std::pair<int, int> > temp(n);
    for (int width = 1; width < n; width *= 2)
    {
        for (int i = 0; i < n; i += 2 * width)
        {
            int left  = i;
            int mid   = i + width;
            int right = i + 2 * width;
            if (mid   > n)
                mid   = n;
            if (right > n)
                right = n;

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
}

//this will split the vector into pairs and sort each pair apart
std::vector< std::pair<int,int> > SortedPairsVector(std::vector<int> &vec)
{
    std::vector< std::pair<int,int> > VectorPairs;
    
    if (vec.size() % 2 == 1)
    {
        extra = vec.back();
        vec.pop_back();
    }
    else
        extra = -1;
    std::vector<int>::iterator it = vec.begin();
    while (it != vec.end())
    {
        int firstVal = *it;
        it++;
        int secondVal = *it;
        it++;
        comp_count++;
        if (firstVal > secondVal)
            std::swap(firstVal, secondVal);

        VectorPairs.push_back(std::make_pair(firstVal, secondVal));
    }
    MergeSortBySecond(VectorPairs);
    return VectorPairs;
}

//this will return the JacobThalNum depending on the size
int JacobthalNum(int n)
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

//return the sequence of JacobThalIndices from 3 to the vector size
std::vector<int> JacobthalIndices(int size)
{
    std::vector<int> jacobSequence;
    int jacobIndex = 3;
    while (JacobthalNum(jacobIndex) <= size)
    {
        jacobSequence.push_back(JacobthalNum(jacobIndex));
        jacobIndex++;
    }
    return jacobSequence;
}

//here we will use the JacobThalIndices to build the vector of optimal indices to parse the pend
std::vector<int> PendInsertIndices(std::vector<int> &pend)
{
    std::vector<int> pend_Indices;
    // pend_Indices.push_back(1);
    if (pend.size() == 1)
        return pend_Indices;

    std::vector<int> jacobIndices = JacobthalIndices(pend.size());
    std::vector<int>::iterator it = jacobIndices.begin();
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

// here is the binaryInsert part using the indices sequence that were built with the JacobIndices
int binaryInsert(std::vector<int>& main, int pend, int high)
{
	int low = 0;
	while (low < high)
	{
		int mid = (low + high) / 2;
		comp_count++;
		if (main[mid] == pend)
		{
			return mid;
		}
		else if (main[mid] > pend)
			high = mid - 1;
		else
			low = mid + 1;
	}
	if (pend < main[low])
		return low;
	else
		return low + 1;
}

//maiin sortVec functionality
void SortVec(std::vector<int> &vec)
{
    int high = 3;
    std::vector< std::pair<int,int> > pairs = SortedPairsVector(vec);
    std::vector<int> main;
    std::vector<int> pend;
    std::vector< std::pair<int,int> >::iterator it = pairs.begin();
    for (; it != pairs.end(); it++)
    {
        main.push_back(it->second);
        pend.push_back(it->first);
    }
    std::vector<int> pend_Indices = PendInsertIndices(pend);
    main.insert(main.begin(), pend[0]);
    for (int i = 0; i < (int)pend_Indices.size(); i++)
    {
        if (i > 0 && (pend_Indices[i] > pend_Indices[i - 1]))
            high = 2 * high + 1;
        if (high > (int)main.size())
            high = main.size();
        int pos = binaryInsert(main, pend[pend_Indices[i] - 1], high - 1);
        main.insert(main.begin() + pos, pend[pend_Indices[i] - 1]);
    }
    if (extra != -1)
    {
        int pos = binaryInsert(main, extra, main.size() - 1);
        main.insert(main.begin() + pos, extra);
    }
    vec = main;
}
