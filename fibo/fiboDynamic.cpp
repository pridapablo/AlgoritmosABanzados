#include <iostream>
#include <map> // Could use unordered_map

using namespace std;

map<int, long long> memo = {{0, 0}, {1, 1}};

int fibDP(int n)
{
    if (memo.find(n) != memo.end()) // if n is in memo
    {
        return memo[n]; // use memoized value
    }
    else
    {
        memo[n] = fibDP(n - 1) + fibDP(n - 2); // memoize the value
        return memo[n];                            // return the value
    }
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Fibonacci of " << n << " is " << fibDP(n + 1) << endl;
    return 0;
}
