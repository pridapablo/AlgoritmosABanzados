/*
This program calculates the suffix array of a string.

- Input: A string "s".
- Output: The suffix array of "s".

Author: Pablo Banzo Prida - A01782031
Date: 14/10/2023
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Struct that represents a suffix of a string.
struct Suffix
{
    int index;     // Starting index of the suffix in the string.
    string suffix; // Suffix.

    // Constructor.
    Suffix(int i, const string &s) : index(i), suffix(s) {}
};

/*
Function that compares two suffixes and returns true if the first one is smaller than the second one.
Time complexity: O(n) where n is the length of longest of the two input suffixes.

@param a: first suffix.
@param b: second suffix.
@return: true if a < b, false otherwise.
*/
bool compare(const Suffix &a, const Suffix &b)
{
    return a.suffix < b.suffix; // Compare the suffixes as strings.
}

/*
Function that calculates the suffix array of a string and returns it after sorting it lexicographically.

The sorting algorithm implemented in c++ will sort the suffixes lexicographically in O(nlogn) time while
the for loop will take O(n^2) time. Therefore, the time complexity of this function is O(n^2logn).

@param s: string of length n.
@return: the suffix array of s in the form of a Suffix struct vector.
*/
vector<Suffix> suffixArray(const string &s)
{
    int n = s.length(); // Length of the string.
    vector<Suffix> suffixes;

    // Fill the vector with the suffixes of the string.
    for (int i = 0; i < n; i++)
    {
        string suffix = s.substr(i);           // Get the suffix of the current index.
        suffixes.push_back(Suffix(i, suffix)); // Add the suffix to the vector.
    }

    sort(suffixes.begin(), suffixes.end(), compare); // Sort the suffixes lexicographically.

    return suffixes;
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    vector<Suffix> sa = suffixArray(s); // Calculate the suffix array.

    // Print the suffix array.
    cout << "Suffix Array:" << endl;
    for (int i = 0; i < sa.size(); i++)
    {
        cout << sa[i].index << " ";   // index
        cout << sa[i].suffix << endl; // string (suffix)
    }
    cout << endl;

    return 0;
}
