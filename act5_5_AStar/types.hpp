#ifndef TYPES_HPP
#define TYPES_HPP

#include <queue>
#include <vector>
#include <utility>

using namespace std;

/*
Node struct for the A* algorithm.

@param nodeID: ID of the node
@param cost: cost of the node
*/
struct Node
{
    int nodeID;
    int cost;

    Node(int id, int c) : nodeID(id), cost(c) {}

    // Define the < operator for priority comparison in the min heap
    bool operator<(const Node &other) const
    {
        return cost > other.cost; // Greater-than ensures a min heap
    }
};

// Define a min heap of nodes
using MinHeap = priority_queue<Node, vector<Node>>;

#endif
