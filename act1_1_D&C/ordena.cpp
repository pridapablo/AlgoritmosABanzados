/*
This program is an implementation of the divide and conquer algorithms for sorting an array
of integers. There are two algorithms implemented: merge sort and quick sort.

Expected input: a file with the following format:
- The first line contains an integer n, which is the number of elements in the array
- The following n lines contain the elements of the array, one per line

Expected output: the unsorted array and the sorted array for each algorithm

Author: Pablo Banzo Prida - A01782031
Date: 03/09/2023
*/

#include <iostream>
#include <fstream>

#include "sort_algorithms.h"
#include "operations_files.h"
#include "operations_print.h"

/*
This function will run the merge sort and quick sort algorithms on the data
stored in a file. It will print the unsorted data and the sorted data for each
algorithm.
*/
int main()
{
    vector<int> data, sortedData;
    data = leeDatos("data.txt");
    imprimeDatos(data);
    sortedData = mergeSort(data);
    imprimeDatos(sortedData);
    sortedData = quickSort(data);
    imprimeDatos(sortedData);
    return 0;
}