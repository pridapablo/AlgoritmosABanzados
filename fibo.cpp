#include <iostream>

using namespace std;

int fibRec(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return fibRec(n - 1) + fibRec(n - 2);
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    cout << fibRec(n) << "\n";
}