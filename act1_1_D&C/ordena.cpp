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
This function will apply the merge sort algorithm to sort an array of integers
@param arr: the array to be sorted

@return: the sorted array (in ascending order)
*/
vector<int> mergeSort(vector<int> &arr);

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
vector<int> readData(string fileName);
// alias for readData (to comply with the activity's instructions)
vector<int> leeDatos(string fileName) { return readData(fileName); }

/*
This function will print the data of a vector @param data: the vector to be
printed
*/
void printData(vector<int> data);
// alias for printData (to comply with the activity's instructions)
void imprimeDatos(vector<int> data) { printData(data); }

/*
This function will run the merge sort and quick sort algorithms on the data
stored in a file. It will print the unsorted data, the data sorted with merge
sort and the data sorted with quick sort.
*/
int main();

// Function implementations:

vector<int> readData(string fileName)
{
    vector<int> data;
    ifstream file(fileName);

    if (!file)
    { // check if the file was successfully opened
        cout << "Error opening file: " << fileName << "\n";
        return data;
    }

    string line;
    int n = 0;
    // read each line of the file
    // Line 1: n, the number of elements in the array
    // Line 2...n: the elements of the array

    try
    {
        if (getline(file, line))
        {
            n = stoi(line);
        }

        for (int i = 0; i < n; i++)
        {
            if (getline(file, line))
            {
                data.push_back(stoi(line));
            }
        }
    }
    catch (exception e)
    {
        cout << "Error: Non-integer value found in file " << fileName << " on line " << n + 1 << ". Returning vector with values read up to this point."
             << "\n";
        return data;
    }

    file.close();

    return data;
}

void printData(vector<int> data)
{
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> data, sortedData;
    data = readData("data.txt");
    printData(data); // unsorted data
    // sortedData = mergeSort(data);x
    // printData(sortedData); // data sorted with Merge Sort
    // sortedData = quickSort(data);
    // printData(sortedData); // data sorted with Quick Sort
    return 0;
}