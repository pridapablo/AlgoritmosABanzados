#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> memo = {{0, 0}, {1, 1}};

int memoFib(int n)
{
    if (memo.find(n) != memo.end()) // if n is in memo
    {
        return memo[n]; // use memoized value
    }
    else
    {
        memo[n] = memoFib(n - 1) + memoFib(n - 2); // memoize the value
        return memo[n];                            // return the value
    }
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Fibonacci of " << n << " is " << memoFib(n + 1) << endl;
    return 0;
}
