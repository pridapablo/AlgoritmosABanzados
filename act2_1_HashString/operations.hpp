// operations.hpp
#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <string>
#include <fstream>

using namespace std;

/*
Function to read a file and return its content as a string.
O(m) time complexity (where m is the length of the content of the file).

@param fileName: the name of the file to read
@return content: the content of the file
*/
string readFiles(string fileName)
{
    string content; // the function returns this string (the content of the file)
    string line;
    ifstream myfile(fileName);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            content += line + '\n';
        }
        myfile.close();
        return content;
    }
    else
    {
        return "";
    }
}

/*
Function to validate the value of n (the number of columns in the table where the characters will be placed including line breaks).
O(1) time complexity (constant).

@param n: the value of n (should be a multiple of 4 and between 16 and 64)
@return true if n is valid, false otherwise
*/
bool validateN(int n)
{
    if (n % 4 == 0 && n >= 16 && n <= 64)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif