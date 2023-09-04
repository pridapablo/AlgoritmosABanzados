#ifndef PRINT_OPERATIONS_H
#define PRINT_OPERATIONS_H

#include <iostream>
#include <vector>

using namespace std;

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

#endif // PRINT_OPERATIONS_H