#ifndef OPERATIONS_PRINT_HPP
#define OPERATIONS_PRINT_HPP

#include <vector>
#include <map> // binary search tree
#include <string>
#include <iostream> // cout

using namespace std;

/*
    Prints the result of a vector of coins (in spanish)
    @param result: the vector with the coins used to give the change ie. {25, 10, 5}
    @param method: the name of the method used to get the result ie. "Greedy"
*/
void printResult(const vector<int> &result, const string &method)
{
    // map to count the coins
    map<int, int> coinCount;
    for (int i = 0; i < result.size(); i++)
    {
        coinCount[result[i]]++; // count amount of each coin
    }

    cout << "Usando " << method << ":\n";
    if (result.empty())
    {
        cout << "Solución no existe\n"; // solution does not exist (method returned empty vector)
    }
    else
    {
        for (auto it = coinCount.begin(); it != coinCount.end(); it++)
        {
            cout << it->second << " ";
            if (it->second > 1)
                cout << "monedas de "; // plural
            else
                cout << "moneda de "; // singular
            cout << it->first << endl;
        }
    }
}

#endif