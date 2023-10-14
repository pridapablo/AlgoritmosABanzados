/*
This program reads a file and hashes its content using its ASCII values.
The hash is calculated by placing the characters in a table with n columns (where n is a multiple of 4 and between 16 and 64),
and then adding the values of each column and converting them to hexadecimal.

- Input: the name of the file and the value of n
- Output: the hash of the content of the file (in hexadecimal of size n/4)

Author: Pablo Banzo Prida - A01782031
Date: 14/10/2023
*/

#include <iostream>
#include <string>

#include "hashing.hpp"
#include "tests.hpp"

using namespace std;

int main()
{
    runTestCases();
    string fileName;
    int n;
    bool isFileRead = false; // flag to check if file has been successfully read
    bool isNValid = false;   // flag to check if n is valid

    string content;

    while (!isFileRead || !isNValid) // loop until both file is successfully read and n is valid
    {
        if (!isFileRead)
        {
            cout << "Ingresa el nombre del archivo: ";
            cin >> fileName;
            content = readFiles(fileName);

            if (content == "")
            {
                cout << "Archivo no encontrado o no se pudo abrir. Intente de nuevo.\n";
            }
            else
            {
                isFileRead = true;
            }
        }

        if (isFileRead && !isNValid)
        {
            cout << "Ingresa el valor de n: ";
            cin >> n;
            if (validateN(n))
            {
                cout << "El valor de n es valido" << endl;
                isNValid = true;
            }
            else
            {
                cout << "El valor de n no es valido. Intente de nuevo.\n";
            }
        }
    }

    // Hashing
    string hash = hashString(content, n);

    // Print the hash
    cout << "El hash es: " << hash << endl;

    return 0;
}