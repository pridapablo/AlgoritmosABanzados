/*
Instrucciones
Utilizando las técnicas de programación de "programación dinámica", y la de "algoritmos avaros", escribe en C++ un programa que resuelva el problema del cambio de monedas.

Problema del cambio
• Encontrar el mínimo número de monedas necesarias para formar una cantidad dada.
• Entradas:
    Integer cantidad a ser cambiada a monedas
    Integer moneda1, moneda2, .... monedad (denominaciones de las monedas disponibles)
• Salida:
    El mínimo número de monedas con denominaciones moneda1, moneda2, .... monedad, necesarias para formar cantidad.

El programa recibe un numero entero N, seguido de N valores enteros (uno en cada línea) por la entrada estándar (teclado), que representan las diferentes denominaciones disponibles de las monedas.

Seguido de esto, el programa recibe dos números enteros: P y Q, (uno en cada línea) por la entrada estándar, que representan P: el precio de un producto dado y Q: es el billete o moneda con el que se paga dicho producto. Obviamente, el valor a convertir es el cambio, es decir, el valor Q - P.

La salida del programa es una impresión de N valores correspondientes al número de monedas de cada denominación, de mayor a menor, una en cada línea, que se tienen que dar para dar el cambio por el producto pagado, primero utilizando programación dinámica, y luego utilizando un algoritmo avaro.

El programa deberá tener 3 funciones obligatorias:

minNumMonGR(int n): recibe un entero que es la cantidad a ser cambiada a monedas y regresa una lista con el números de monedas de cada tipo que se usaron para formar la cantidad, usando el algoritmo Greedy.
minNumMonDP(int n): recibe un entero que es la cantidad a ser cambiada a monedas y regresa una lista con el números de monedas de cada tipo que se usaron para formar la cantidad, usando el algoritmo de Programación Dinámica.
escribeRespuesta(int n): recibe un entero que es la cantidad a ser cambiada a monedas e imprime, a la salida estándar (la pantalla) las soluciones obtenidas por Greedy y por Programación Dinámica. La impresión se realiza de la forma descrita arriba.
La función main deberá pedir, usando letreros, los valores a ser usados, de acuerdo a lo descrito anteriormente (exactamente en el orden indicado anteriormente) y debe llamar a la función escribeRespuesta(Q-P), la cual deberá llamar a su vez las dos funciones de los dos diferentes algoritmos (minNumMonGR(n) y minNumMonDP(n)) e imprimir la respuesta con un letrero que indique a qué algoritmo se refiere.

Por ejemplo, si en un país tenemos monedas de 50, 25, 20, 10, 5 y 1 centavos, el precio P del producto es 20 centavos y se paga con 60 centavos (es sólo para que de 40 que fue el ejercicio que hicimos en clase), el programa deberá imprimir:

Usando Greedy:

1 moneda de 25

1 moneda de 10

1 moneda de 5

Usando Programación Dinámica:

2 monedas de 20

Author: Pablo Banzo Prida - A01782031
Date: 21/09/2023
*/

#include <vector>
#include <iostream>
#include <map>     // binary search tree
#include <utility> // pair class

using namespace std;

vector<int> denom; // Vector with the denominations of the coins

/*
    Greedy implementation of the coin change problem (always choose the largest coin that is less than the change)
    Time complexity: O(n) where n is the change assuming the denominations are sorted
    @param qty: the amount of change to be given

    @return: a vector with the coins used to give the change (returns {} if solution does not exist or is incorrect)
*/
vector<int> greedyChange(int qty)
{
    if (qty == 0)
        return {0}; // base case: 0 coins to make 0 change
    vector<int> change;
    int initQty = qty; // save initial qty to check if solution is correct
    // "denom" vector is a global variable
    while (qty > 0)
    {
        int coin;
        // find the largest coin that is less than qty
        bool found = false;
        int i = denom.size() - 1;

        while (!found && i >= 0)
        {
            if (denom[i] <= qty)
            {
                coin = denom[i];
                change.push_back(coin);
                found = true;
            }
            else
            {
                i--;
            }
        }
        // decrese qty since we've provided a coin
        qty -= coin;
    }
    // check if solution is correct
    int sum = 0;
    for (int i = 0; i < change.size(); i++)
    {
        sum += change[i];
    }
    if (sum != initQty)
    {
        return {}; // Solution is incorrect, so it does not exist (with this algorithm)
    }

    return change;
}
// alias for greedyChange: to comply with the assignment
vector<int> minNumMonGR(int n) { return greedyChange(n); }

/*
    Dynamic Programming implementation of the coin change problem
    Bottom-up approach for space efficiency
    Time complexity: O(n * m) where n is the change and m is the number of denominations (matrix size since we need to check all combinations)
    @param change: the amount of change to be given

    @return: a vector with the coins used to give the change (returns {} if solution does not exist or is incorrect)
*/
vector<int> dpChange(int qty)
{
    if (qty == 0)
        return {0};    // base case: 0 coins to make 0 change
    int initQty = qty; // save initial qty to check if solution is correct
    // Pair vector { no. coins, who tagged it }
    // initialize all values to change + 1 (impossible value for change since max change is change)
    vector<pair<int, int>> matrix(qty + 1, {qty + 1, -1});

    matrix[0] = {0, -1}; // base case: 0 coins to make 0 change (tag -1 since no coin was used)

    for (int i = 0; i < denom.size(); i++)
    {
        for (int j = 0; j <= qty; j++)
        {
            // if the denomination is less than the change
            if (denom[i] <= j)
            {
                // If the number of coins in the current combination is less than the minimum number of coins so far
                if (matrix[j - denom[i]].first + 1 < matrix[j].first)
                {
                    matrix[j].first = matrix[j - denom[i]].first + 1;
                    matrix[j].second = i; // Tag it with the coin used
                }
            }
        }
    }

    // If change is not possible
    if (matrix[qty].first == qty + 1)
    {
        return {}; // Solution not possible since value is unattainable (change + 1)
    }
    else
    {
        // Get the coins used
        vector<int> coinsUsed;
        int i = qty;
        while (i != 0)
        {
            int coin = denom[matrix[i].second];
            coinsUsed.push_back(coin);
            i -= coin;
        }

        // check if solution is correct
        int sum = 0;
        for (int i = 0; i < coinsUsed.size(); i++)
        {
            sum += coinsUsed[i];
        }
        if (sum != initQty)
        {
            return {}; // Solution is incorrect, so it does not exist (with this algorithm)
        }
        return coinsUsed;
    }
}
// alias for dpChange: to comply with the assignment
vector<int> minNumMonDP(int n) { return dpChange(n); }

void escribeRespuesta(int n)
{
    // sort denom array in place to avoid calculating min/max inside the functions
    sort(denom.begin(), denom.end());
    vector<int> empty = {}; // this will be returned when the solution does not exist

    cout << "Usando Greedy:\n";

    vector<int> greedy = minNumMonGR(n);
    if (greedy == empty)
        cout << "Solución no existe\n";
    else
    {
        // use a map to store the number of coins of each type
        map<int, int>
            coinCount;
        for (int i = 0; i < greedy.size(); i++)
        {
            coinCount[greedy[i]]++;
        }

        for (auto it = coinCount.begin(); it != coinCount.end(); it++)
        {
            cout << it->second << " moneda de " << it->first << endl;
        }
    }

    cout << "Usando Programación Dinámica:\n";
    vector<int> dp = minNumMonDP(n);
    if (dp == empty)
        cout << "Solución no existe\n";
    else
    {
        // use a map to store the number of coins of each type
        map<int, int>
            coinCount;
        for (int i = 0; i < dp.size(); i++)
        {
            coinCount[dp[i]]++;
        }

        for (auto it = coinCount.begin(); it != coinCount.end(); it++)
        {
            cout << it->second << " moneda de " << it->first << endl;
        }
    }
}

int main()
{
    int N, C, P, Q;

    cout << "Ingrese el numero de denominaciones de monedas: ";
    cin >> N;

    vector<int> denom(N); // Init denom vector with N coins

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

    escribeRespuesta(change);
    return 0;
}