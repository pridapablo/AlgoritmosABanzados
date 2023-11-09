#ifndef FLOYD_WARSHALL_HPP
#define FLOYD_WARSHALL_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include "data_structs.hpp"

using namespace std;

/*
    Solves the "shortest path" problem using the Floyd-Warshall algorithm.
    Time complexity is O(n^3), where n is the number of nodes in the graph.

    @param graph: the graph to solve
    @return: a matrix containing the shortest path from each node to each node
*/
vector<vector<int>> floydWarshall(const Graph &graph)
{
    // Initialize resulting matrix
    vector<vector<int>> resultingMatrix(graph.matrix); // Copy of adjacency matrix (same size)

    int n = resultingMatrix.size();

    // Floyd-Warshall's algorithm
    for (int k = 0; k < n; k++) // intermediate node
    {
        for (int i = 0; i < n; i++) // matrix row
        {
            for (int j = 0; j < n; j++) // matrix column
            {
                if (!(resultingMatrix[i][k] == INT_MAX || resultingMatrix[k][j] == INT_MAX))
                {
                    int indirectWeight = resultingMatrix[i][k] + resultingMatrix[k][j];
                    if (indirectWeight < resultingMatrix[i][j])
                    {
                        resultingMatrix[i][j] = indirectWeight;
                    }
                }
            }
        }
    }

    // Check for negative cycles by looking at the diagonal of the matrix.
    for (int i = 0; i < n; i++)
    {
        if (resultingMatrix[i][i] < 0)
        {
            throw std::runtime_error("Graph contains a negative weight cycle");
        }
    }

    return resultingMatrix;
}

/*
    Prints the shortest path distances between each pair of nodes as calculated
    by Floyd-Warshall's algorithm.

    @param resultingMatrix: the matrix containing the shortest path from each
                             node to each node, as returned by floydWarshall()
*/
void printFloydWarshall(const vector<vector<int>> &resultingMatrix)
{
    cout << "\nFloyd-Warshall's algorithm:\n";
    for (const auto &row : resultingMatrix)
    {
        for (int val : row)
        {
            if (val == INT_MAX)
            {
                cout << "∞ ";
            }
            else
            {
                cout << val << " ";
            }
        }
        cout << "\n";
    }
}
#endif