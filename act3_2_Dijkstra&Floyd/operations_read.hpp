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
    and an adjacency list. This function only reads the file once for efficiency.

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
    graph.matrix.resize(n, vector<int>(n, -1));
    graph.adj_list.resize(n);

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        file >> a >> b >> c;
        graph.matrix[a][b] = c;
        graph.adj_list[a].emplace_back(b, c);
    }

    return graph;
}

#endif // OPERATIONS_READ_HPP
