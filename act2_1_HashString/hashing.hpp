// hashing.hpp
#ifndef HASHING_H
#define HASHING_H

#include <string>
#include <vector>

using namespace std;

/*
Function to convert a number to its hexadecimal representation.
Loops until the number is 0 but the maximum input is 255, so the time complexity is O(1) (constant).

@param n: the number to convert
@return hex: the hexadecimal representation of the number
*/
string toHex(int n)
{
    string hex = "";
    while (n)
    {
        int temp = n % 16;
        if (temp < 10)
            hex += temp + 48;
        else
            hex += temp + 55;
        n /= 16;
    }
    while (hex.length() < 2) // Ensure it's two characters
    {
        hex = "0" + hex;
    }
    return hex;
}

/*
Function to hash the content of the file. Since n is bounded by 64 (constant), the time complexity of this function is
only related to the length of the content of the file, which is O(m), where m is the length of the content of the file.

@param content: the content of the file
@param n: the value of n (the number of columns in the table where the characters will be placed including line breaks)
@return hash: the hash of the content of the file
*/
string hashString(string content, int n)
{
    string hash;                  // the function returns this string (the hash of the content of the file)
    int asciiColIndex = 0;        // the index of the current column in the ascii table
    vector<int> asciiTable(n, 0); // the ascii table

    // Fill the ascii table
    for (char ch : content)
    {
        asciiTable[asciiColIndex] += ch;
        asciiColIndex = (asciiColIndex + 1) % n;
    }

    // fill the last row with the value of n
    while (asciiColIndex != 0)
    {
        asciiTable[asciiColIndex] += n;
        asciiColIndex = (asciiColIndex + 1) % n;
    }

    // Mod 256 for all columns
    for (int i = 0; i < n; i++)
    {
        asciiTable[i] %= 256; // overwriting the value of the ascii table with the mod 256 of the sum per column
    }

    // Generate the hash string
    for (int i = 0; i < n; i += 4) // Looping every 4 columns to generate n/4 hex characters
    {
        string hexValue = toHex(asciiTable[i]); // No need to sum across columns, just mod 256
        hash += hexValue;
    }

    return hash;
}

#endif