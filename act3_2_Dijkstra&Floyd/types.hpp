#ifndef TYPES_HPP
#define TYPES_HPP

#include <queue>
#include <vector>
#include <utility>

using namespace std;

// MinHeap for Dijkstra's algorithm

using MinHeap = priority_queue<
    pair<int, int>,         // pair: {nodeID, distance}
    vector<pair<int, int>>, // container
    greater<pair<int, int>> // comparator (for min heap)
    >;

#endif