/*
This program is a solution to the activity 1.1 of the course TC2038 (ITESM),
It's an implementation of the divide and conquer algorithms for sorting an array
of integers. There are two algorithms implemented: merge sort and quick sort.

Author: Pablo Banzo Prida
Date: 03/09/2023
*/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/*
Clean public interface for the mergeSort algorithm (to comply with the
activity's instructions)

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

/*
Implementation of the merge sort algorithm, initialized based on the "mergeSort"
call. Will sort the array in place.

@param arr: the array to be sorted @param lo: the lower index of the array
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
    // call mergeSort on the first half (recursive call)
    doMergeSort(arr, lo, mid);
    //    - The second half will contain the elements from arr[mid + 1] to arr[n - 1]
    // call mergeSort on the second half (recursive call)
    doMergeSort(arr, mid + 1, hi);

    // merge the two halves in place
    merge(arr, lo, mid, hi);
}

/*
Helper function for mergeSort. This function will apply the merge step in place

@param arr: the array to be sorted @param lo: the lower index of the array
@param mid: the middle index of the array @param hi: the higher index of the
array
*/
void merge(vector<int> &arr, int lo, int mid, int hi)
{
    // copy vectors
    vector<int> left(arr.begin() + lo, arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1, arr.begin() + hi + 1);

    // initialize pointers
    int i = 0;  // left
    int j = 0;  // right
    int k = lo; // pointer for the main arr to place merged elements
}

/*
This function will apply the quick sort algorithm to sort an array of integers
@param arr: the array to be sorted

@return: the sorted array (in ascending order)
*/
vector<int> quickSort(vector<int> &arr);

/*
This function will read the data from a file and store it in a vector @param
fileName: the name of the file to be read (with the extension)

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
            cout << "Error: First line of file " << fileName << " is not an integer. Exiting...\n";
            return data;
        }
    }
    else
    {
        cout << "Error: File " << fileName << " is empty or first line is missing. Exiting...\n";
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
                cout << "Error: Non-integer value found in file " << fileName << " on line " << i + 2 << ". Exiting...\n";
                return data;
            }
        }
        else
        {
            cout << "Error: Expected more data in file " << fileName << ". Exiting...\n";
            return data;
        }
    }

    file.close();
    return data;
}
// alias for readData (to comply with the activity's instructions)
vector<int> leeDatos(string fileName) { return readData(fileName); }

/*
This function will print the data of a vector @param data: the vector to be
printed
*/
void printData(vector<int> data)
{
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}
// alias for printData (to comply with the activity's instructions)
void imprimeDatos(vector<int> data) { printData(data); }

/*
This function will run the merge sort and quick sort algorithms on the data
stored in a file. It will print the unsorted data, the data sorted with merge
sort and the data sorted with quick sort.
*/
int main()
{
    vector<int> data, sortedData;
    data = readData("data.txt");
    printData(data); // unsorted data
    // sortedData = mergeSort(data); printData(sortedData); // data sorted with
    // Merge Sort sortedData = quickSort(data); printData(sortedData); // data
    // sorted with Quick Sort
    return 0;
}