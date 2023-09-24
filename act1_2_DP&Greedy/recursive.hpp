#ifndef RECURSIVE_HPP
#define RECURSIVE_HPP

#include <vector>

using namespace std;

/*
    Recursive implementation of the coin change problem
    Top-down approach for simplicity
    Time complexity: O(n^m) where n is the change and m is the number of denominations (tree depth)
    @param qty: the amount of change to be given
    @param denom: the vector with the denominations of the coins (sorted)

    @return: a vector with the coins used to give the change (returns {} if solution does not exist or is incorrect)
*/
vector<int> recursiveChange(int qty, vector<int> denom)
{
    // pass
}

#endif