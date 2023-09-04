#ifndef MERGE_SORT_IMPL_H
#define MERGE_SORT_IMPL_H

#include <vector>

using namespace std;

// ------------------------ MERGE SORT ------------------------

/*
Helper function for mergeSort. This function will apply the merge step in place.
Space complexity is O(n) since we need to copy the elements to auxiliar arrays.

@param arr: the array to be sorted
@param lo: the lower index of the array
@param mid: the middle index of the array
@param hi: the higher index of the
array
*/
void merge(vector<int> &arr, int lo, int mid, int hi)
{
    // TODO: this is inneficient in terms of memory, but it's the
    // easiest way to implement it. We could adjust `doMergeSort` function to
    // pass an auxiliar vector to avoid this?

    vector<int> left(arr.begin() + lo, arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1, arr.begin() + hi + 1);

    int i = 0;
    int j = 0;
    int k = lo; // main array

    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i += 1;
        }
        else
        {
            arr[k] = right[j];
            j += 1;
        }
        k += 1;
    }

    // Will copy elements when one half is longer than the other
    for (int p = i; p < left.size(); p++)
    {
        arr[k] = left[p];
        k++;
    }

    for (int p = j; p < right.size(); p++)
    {
        arr[k] = right[p];
        k++;
    }
}

/*
Implementation of the merge sort algorithm, initialized based on the "mergeSort"
call. Will sort the array in place.

@param arr: the array to be sorted
@param lo: the lower index of the array
@param hi: the higher index of the array
*/
void doMergeSort(vector<int> &arr, int lo, int hi)
{
    if (lo >= hi)
    {
        return;
    }

    // prevent overflow of (hi + lo) / 2
    int mid = lo + (hi - lo) / 2;
    //    - The first half will contain the elements from arr[0] to arr[mid]
    // recursion first half
    doMergeSort(arr, lo, mid);
    //    - The second half will contain the elements from arr[mid + 1] to arr[n - 1]
    // recursion second half
    doMergeSort(arr, mid + 1, hi);
    merge(arr, lo, mid, hi);
}

#endif // MERGE_SORT_IMPL_H
