#ifndef OPERATIONS_READ_HPP
#define OPERATIONS_READ_HPP

#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <utility>

using namespace std;

/*
    Reads the directed graph from a file and stores it as both an adjacency matrix
    and an adjacency list. This function only reads the file once for
    efficiency.

    Note: format errors are unhandled.

    @param filename: the name of the file to read
    @return: a Graph structure containing both the adjacency matrix and list
*/
Graph read_graph(string filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        throw runtime_error("Could not open file.");
    }

    int n, m;
    file >> n >> m;

    Graph graph;
    int maxValue = INT_MAX / 2;                     // Prevent overflow
    graph.matrix.resize(n, vector<int>(n, INT_MAX)); // No edges by default (infinite weight)

    // Set the diagonal to 0 (distance to itself)
    for (int i = 0; i < n; ++i)
    {
        graph.matrix[i][i] = 0;
    }

    graph.adj_list.resize(n);

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        file >> a >> b >> c;
        if (a == b && c != 0) // Zero weight is allowed (won't affect shortest path)
        {
            throw runtime_error("Self-loop with non-zero weight detected at node " + to_string(a));
        }
        if (c > maxValue)
        {
            throw runtime_error("Edge weight at node " + to_string(a) + " exceeds INT_MAX/2");
        }
        graph.matrix[a][b] = c;
        graph.adj_list[a].emplace_back(b, c);
    }

    file.close();
    return graph;
}

#endif // OPERATIONS_READ_HPP
