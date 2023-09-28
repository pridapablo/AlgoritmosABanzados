/*
This program solves the Coin Problem using Greedy and Dynamic Programming algorithms.

Change problem
• Find the minimum number of coins needed to form a given amount.

• Inputs:
    Integer amount to be changed to coins
    Integer coin1, coin2, .... coind (denominations of the available coins)
• Output:
    The minimum number of coins with denominations coin1, coin2, .... coind, needed to form amount

Author: Pablo Banzo Prida - A01782031
Date: 21/09/2023
*/

#include <vector>
#include <iostream>

#include "greedy.hpp"           // greedyChange (greedy algorithm)
#include "dp.hpp"               // dpChange (dynamic programming algorithm)
#include "operations_print.hpp" // printResult

using namespace std;

vector<int> denom; // Global vector with the denominations of the coins

/* Wrapper for greedyChange function with the denom vector as a parameter
    @param n: the amount of change to be given
    @return: a vector with the coins used to give the change (returns {} if solution does not exist or is incorrect)
*/
vector<int> minNumMonGR(int n) { return greedyChange(n, denom); }

/* Wrapper for dpChange function with the denom vector as a parameter
    @param n: the amount of change to be given
    @return: a vector with the coins used to give the change (returns {} if solution does not exist or is incorrect)
*/
vector<int> minNumMonDP(int n) { return dpChange(n, denom); }

/* Prints the solution of the greedy and dp algorithms
    Calls the wrapper functions and prints the results with the printResult function
    Time complexity: O(nlogn) (sort with cpp impl)

    Sorts the denom vector and calls the wrapper functions
    @param n: the amount of change to be given
*/
void escribeRespuesta(int n)
{
    // sort denom array in place to avoid calculating min/max inside the functions
    sort(denom.begin(), denom.end());

    vector<int> greedy = minNumMonGR(n);
    printResult(greedy, "Greedy");

    vector<int> dp = minNumMonDP(n);
    printResult(dp, "Programación Dinámica");
}

/*
    Main function
    Asks for the denominations of the coins, the price of the product and the coin used to pay
    Calls the escribeRespuesta function with the change as a parameter
*/
int main()
{
    int N, C, P, Q;

    cout << "Ingrese el numero de denominaciones de monedas: ";
    cin >> N;

    denom.resize(N); // resize denom vector to N

    for (int i = 0; i < N; i++)
    {
        cout << "Ingrese la denominacion de la moneda " << i + 1 << ": ";
        cin >> denom[i];
    }

    cout << "Ingrese el precio del producto: ";
    cin >> P;

    cout << "Ingrese la moneda con la que se pagó el producto: ";
    cin >> Q;

    int change = Q - P;

    cout << "Se ha determinado que el cambio necesario es: " << change << "\n";

    if (change == 0)
    {
        cout << "No se requiere cambio\n";
        return 0;
    }

    if (change < 0)
    {
        cout << "El cambio no puede ser negativo\n";
        return 0;
    }

    escribeRespuesta(change);
    return 0;
}