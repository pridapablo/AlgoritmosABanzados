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
vector<vector<int>> floyd_warshall(const Graph &graph)
{
    // Initialize resulting matrix
    vector<vector<int>> resulting_matrix(graph.matrix); // Copy of adjacency matrix (same size)

    int n = resulting_matrix.size();

    // Floyd-Warshall's algorithm
    for (int k = 0; k < n; k++) // intermediate node
    {
        for (int i = 0; i < n; i++) // matrix row
        {
            for (int j = 0; j < n; j++) // matrix column
            {
                int ik = resulting_matrix[i][k];
                int kj = resulting_matrix[k][j];

                if (!(ik == INT_MAX || kj == INT_MAX)) // If we can go through k (no infinite weight) to prevent overflow
                {
                    // If going through k is shorter than direct path, update
                    int indirect_weight = resulting_matrix[i][k] + resulting_matrix[k][j];
                    if (indirect_weight < resulting_matrix[i][j])
                    {
                        resulting_matrix[i][j] = indirect_weight;
                    }
                }
            }
        }
    }
    return resulting_matrix;
}

/*
    Prints the shortest path distances between each pair of nodes as calculated
    by Floyd-Warshall's algorithm.

    @param resulting_matrix: the matrix containing the shortest path from each
                             node to each node, as returned by floyd_warshall()
*/
void print_floyd_warshall(const vector<vector<int>> &resulting_matrix)
{
    cout << "\nFloyd-Warshall's algorithm:\n";
    for (const auto &row : resulting_matrix)
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