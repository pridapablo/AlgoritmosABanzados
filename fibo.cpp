#include <iostream>

using namespace std;

// Para calcular el n-ésimo número de la serie de Fibonacci
// Sumando los dos anteriores (recursividad)
int fibRec(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return fibRec(n - 1) + fibRec(n - 2);
}

// long long fibRecLong(long long n)
// {
//     if (n == 0 || n == 1)
//         return n;
//     else
//         return fibRec(n - 1) + fibRec(n - 2);
// }

// Para calcular el n-ésimo número de la serie de Fibonacci
// Sumando los dos anteriores (programación dinámica)
int fibSuma(int n)
{
    int F[n + 1];
    F[0] = 0;
    F[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
    }
    return F[n];
}

// long long fibSumaLong(long long n)
// {
//     long long F[n + 1];
//     F[0] = 0;
//     F[1] = 1;

//     for (long long i = 2; i <= n; i++)
//     {
//         F[i] = F[i - 1] + F[i - 2];
//     }
//     return F[n];
// }

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    // cout << fibRec(n) << "\n";
    cout << fibSuma(n) << "\n";
}