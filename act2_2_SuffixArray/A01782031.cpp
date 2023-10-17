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
Function that calculates the suffix array of a string and returns it.

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
        string suffix = s.substr(i);
        suffixes.push_back(Suffix(i, suffix)); 
    }
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
        cout << sa[i].index << " ";
        cout << sa[i].suffix << endl;
    }
    cout << endl;

    return 0;
}
