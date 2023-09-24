
#ifndef GREEDY_HPP
#define GREEDY_HPP

#include <vector>
#include <utility> // pair class

using namespace std;

/*
    Greedy implementation of the coin change problem (always choose the largest coin that is less than the change)
    Time complexity: O(n) where n is the change assuming the denominations are sorted
    @param qty: the amount of change to be given
    @param denom: the vector with the denominations of the coins (sorted)

    @return: a vector with the coins used to give the change (returns {} if solution does not exist or is incorrect)
*/
vector<int> greedyChange(int qty, vector<int> denom)
{
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

#endif