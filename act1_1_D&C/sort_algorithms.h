#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H
#include <vector>
#include "sort_merge_impl.h"
#include "sort_quick_impl.h"

using namespace std;

// ------------------------ MERGE SORT ------------------------
/*
Public interface for the mergeSort algorithm.
The function's (worst scenario) time complexity is O(n log n).

@param arr: the array to be sorted
@return: the sorted array (in ascending order)
*/
vector<int> mergeSort(const vector<int> &arr)
{
    // Copy the input array
    vector<int> sortedArray = arr;
    // Call the recursive function in place setting the lower and upper bounds
    doMergeSort(sortedArray, 0, sortedArray.size() - 1);
    return sortedArray;
}

// ------------------------ QUICK SORT ------------------------
/*
Public interface for the quickSort algorithm.
The function's (worst scenario) time complexity is O(n*n),
but it's O(n log n) on average (it also depends on the pivot selection)

@param arr: the array to be sorted.

@return: the sorted array (in ascending order)
*/
vector<int> quickSort(const vector<int> &arr)
{
    // Decision to copy to ensure the original array is not modified
    vector<int> sortedArray = arr;
    // Call the recursive function in place setting the lower and upper bounds
    doQuickSort(sortedArray, 0, sortedArray.size() - 1);
    return sortedArray;
}

#endif // SORT_ALGORITHMS_H
