#include <iostream>
#include <string>

using namespace std;

/*
Z-Function (naiive impl)
    - Given a string s of length n, the Z-function produces an array Z where Z[i] is the length of the longest substring starting from s[i] which is also a prefix of s.
    - Time Complexity: O(n^2)
*/
vector<int> z_function(string s)
{
    int n = s.length();
    vector<int> z(n);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (s[j] == s[i + j])
                z[i]++; // increment the count in i
            else
                break;
        }
    }
    return z;
}

/*
Z-Function (optimized) DP
    - Given a string s of length n, the Z-function produces an array Z where Z[i] is the length of the longest substring starting from s[i] which is also a prefix of s.
    - Keeps track of the rightmost segment and stores previous answers to improve complexity.
    - Time Complexity: O(n)
*/
vector<int> z_functionDP(string s)
{
    int n = s.length();
    vector<int> z(n);
}

int main()
{
    string s = "aaabaaab";
    cout << s << endl;
    vector<int> result = z_function(s);

    cout << "Z-Function: ";
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    return 0;
}