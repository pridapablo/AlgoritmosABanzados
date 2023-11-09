/*
This program solves the "shortest path" problem using two different algorithms:
1. Dijkstra's algorithm
2. Floyd-Warshall algorithm

The program reads a directed graph from a file and outputs the shortest path

Input:
A file containing the graph in the following format:
  - First line: the number of nodes and the number of edges separated by a
    space (e.g. 5 7)
  - The following "m" lines: each line contains three numbers "a", "b" and
    "c" where a is the starting node of the edge, b is the ending node of the
    edge and c is the weight of the edge (e.g. 1 2 3)

Output:
For Dijkstra's algorithm:
  - The shortest path from the starting node (i) to each node in the graph (j)

For Floyd-Warshall algorithm:
  - The resulting matrix of the shortest path from each node (i) to each node
    in the graph (j)
*/

#include <iostream>
#include "operations_read.hpp"

using namespace std;

int main()
{
  // Read graph into both an adjacency matrix and list
  Graph graph = read_graph("graph_input.txt");

  // Print the adjacency matrix
  cout << "Adjacency Matrix:" << endl;
  for (const auto &row : graph.matrix)
  {
    for (int val : row)
    {
      cout << val << " ";
    }
    cout << endl;
  }

  // Print the adjacency list with weights
  cout << "\nAdjacency List with Weights:" << endl;
  for (const auto &adj_list : graph.adj_list)
  {
    for (const auto &edge : adj_list)
    {
      cout << edge.first << "(w " << edge.second << ") -> ";
    }
    cout << "null" << endl;
  }

  return 0;
}
