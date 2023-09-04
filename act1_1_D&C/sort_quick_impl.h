#ifndef QUICK_SORT_IMPL_H
#define QUICK_SORT_IMPL_H

#include <vector>

using namespace std;

// ------------------------ QUICK SORT ------------------------

/*
Helper function for quickSort. This function will apply the partition step in
place

@param arr: the array to be sorted
@param lo: the lower index of the array
@param hi: the higher index of the array
*/
int partition(vector<int> &arr, int lo, int hi)
{
    int i = lo;     // left
    int j = hi + 1; // right
    // Decided to pivot on the leftmost element. Major pitfall if the array is
    // already sorted and could be avoided by selecting a random pivot
    // (or randomizing the array before sorting)
    int v = arr[lo];
    bool pointersCrossed = false;

    while (!pointersCrossed)
    {
        // Find the next element from the left that is >= pivot
        do
        {
            i++;                         // move the pointer to the right
        } while (i <= hi && arr[i] < v); // as long as its value is less than the pivot

        // Find the next element from the right that is <= pivot
        do
        {
            j--;                         // move the pointer to the left
        } while (j >= lo && arr[j] > v); // as long as its value is greater than the pivot

        // Check if the two pointers have crossed each other
        pointersCrossed = i >= j;

        if (!pointersCrossed)
        {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[lo], arr[j]); // j is the new pivot point
    return j;              // return the new pivot point
}

/*
Implementation of the quick sort algorithm, initialized based on the "quickSort"
call. Will sort the array in place.

@param arr: the array to be sorted
@param lo: the lower index of the array
@param hi: the higher index of the array
*/
void doQuickSort(vector<int> &arr, int lo, int hi)
{
    if (hi <= lo)
    {
        return;
    }
    int j = partition(arr, lo, hi);
    //  Sort the left part
    doQuickSort(arr, lo, j - 1);
    // Sort the right part
    doQuickSort(arr, j + 1, hi);
}

#endif // QUICK_SORT_IMPL_H
