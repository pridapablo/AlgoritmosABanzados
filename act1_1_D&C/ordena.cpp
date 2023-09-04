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
#include <vector>
#include <fstream>

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
    // Decided to pivot on the leftmost element. Major pitfall if the array is already sorted and could be avoided by selecting a random pivot (or randomizing the array before sorting)
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

// ------------------------ HELPER FUNCTIONS ------------------------
/*
This function will read the data from a file and store it in a vector

@param fileName: the name of the file to be read (with the extension)

@return: the vector with the data
*/
vector<int> readData(string fileName)
{
    vector<int> data;
    ifstream file(fileName);

    if (!file)
    {
        cout << "Error opening file: " << fileName << "\n";
        return data;
    }

    string line;
    int n = 0;

    if (getline(file, line))
    {
        try
        {
            n = stoi(line);
        }
        catch (const exception &)
        {
            cout << "Error: First line of file " << fileName << " is not an integer. Returning empty vector...\n";
            return data;
        }
    }
    else
    {
        cout << "Error: File " << fileName << " is empty or first line is missing. Returning empty vector...\n";
        return data;
    }

    for (int i = 0; i < n; i++)
    {
        if (getline(file, line))
        {
            try
            {
                data.push_back(stoi(line));
            }
            catch (const exception &)
            {
                cout << "Error: Non-integer value found in file " << fileName << " on line " << i + 2 << ". Exiting with the data read so far...\n";
                return data;
            }
        }
    }

    file.close();
    return data;
}
// alias for readData: to comply with the assignment
vector<int> leeDatos(string fileName) { return readData(fileName); }

/*
This function will print the data of a vector

@param data: the vector to be printed
*/
void printData(vector<int> data)
{
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}
// alias for printData: to comply with the assignment
void imprimeDatos(vector<int> data) { printData(data); }

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