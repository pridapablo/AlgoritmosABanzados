// Instrucciones

// La salida es una cadena de longitud n/4 que es una representación hexadecimal que corresponde al hasheo del archivo de texto de entrada de acuerdo con las siguientes reglas:

// Si el numero de caracteres en el archivo de entrada no es múltiplo de n, el último renglón se "rellena" con el valor de n.
// En un arreglo a de longitud n se calcula a[i] = (la suma de los ASCII de cada char en la columna) % 256.
// La salida se genera concatenando la representación hexadecimal (mayúsculas) a dos dígitos de cada posición en el arreglo. La longitud de la cadena de salida será de n/4.                                                                                                                                                                                                                                                       debido a que la probabilidad de que haya colisión es, aproximadamente, 1 / m.Una buena selección ha sido un número primo muy grande, por ejemplo, m = 109 + 9, lo que nos da una probabilidad de colisión de alrededor de 10 - 9.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
Function to read a file and return its content as a string

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
        cout << "Unable to open file";
        return "";
    }
}

/*
Function to validate the value of n (the number of columns in the table where the characters will be placed including line breaks)

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

/*
Function to convert a number to its hexadecimal representation

@param n: the number to convert
@return hex: the hexadecimal representation of the number
*/
string toHex(int n)
{
    string hex; // the function returns this string (the hexadecimal representation of the number)
    int remainder;
    while (n != 0)
    {
        remainder = n % 16;
        if (remainder < 10)
        {
            hex = char(remainder + 48) + hex;
        }
        else
        {
            hex = char(remainder + 55) + hex;
        }
        n /= 16;
    }
    return hex;
}

/*
Function to hash the content of the file

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
    for (int i = 0; i < n; i += 4)
    {
        int value = asciiTable[i] + asciiTable[i + 1] + asciiTable[i + 2] + asciiTable[i + 3];
        hash += toHex(value);
    }

    return hash;
}

int main()
{
    string fileName;
    int n;

    cout << "Ingresa el nombre del archivo: ";
    cin >> fileName;

    // Read and validate n
    cout << "Ingresa el valor de n: ";
    cin >> n;
    if (validateN(n))
    {
        cout << "El valor de n es valido" << endl;
    }
    else
    {
        cout << "El valor de n no es valido" << endl;
        return 0;
    }

    // Read and extract content from file
    string content = readFiles(fileName);

    // Hashing
    string hash = hashString(content, n);

    // Print the hash
    cout << "El hash es: " << hash << endl;

    return 0;
}