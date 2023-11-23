#ifndef HEURISTIC_HPP
#define HEURISTIC_HPP

#include <cmath>   // abs
#include <utility> // pair

using namespace std;

/*
    Heuristic function for the A* algorithm.

    @param x: pair of coordinates of the current node (x, y)
    @param y: pair of coordinates of the goal node (x, y)

    @return: the Manhattan distance between the current node and the goal node
*/
int heuristic(pair<int, int> x, pair<int, int> y)
{
    return abs(x.first - y.first) + abs(x.second - y.second);
}

#endif