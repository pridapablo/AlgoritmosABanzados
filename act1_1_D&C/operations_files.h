#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

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

#endif // FILE_OPERATIONS_H