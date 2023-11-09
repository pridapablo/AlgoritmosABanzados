/*
This program solves the "shortest path" problem using two different algorithms:
1. Dijkstra's algorithm
2. Floyd-Warshall algorithm

Note: Floyd-Warshall's algorithm is applicable to graphs with negative weights,
while Dijkstra's algorithm is not.

The program reads a directed graph from a file and outputs the shortest path.

Input:
A file containing the graph in the following format:
  - First line: the number of nodes and the number of edges separated by a
    space (e.g. 5 7)
  - The following "m" lines: each line contains three numbers "a", "b" and
    "c" where a is the starting node of the edge, b is the ending node of the
    edge and c is the weight of the edge (e.g. 1 2 3)
  - Note: nodes are 0-indexed

Output:
For Dijkstra's algorithm:
  - The shortest path from the starting node (i) to each node in the graph (j)

For Floyd-Warshall algorithm:
  - The resulting matrix of the shortest path from each node (i) to each node
    in the graph (j)
*/

#include <iostream>
#include "data_structs.hpp"
#include "operations_read.hpp"
#include "dijkstra.hpp"
#include "floyd_warshall.hpp"

using namespace std;

int main()
{
  // Read graph into both an adjacency matrix and list
  Graph graph = read_graph("graph_input.txt");

  // Adjacency matrix
  cout << "\nAdjacency Matrix:\n";
  for (const auto &row : graph.matrix)
  {
    for (int val : row)
    {
      cout << val << " ";
    }
    cout << endl;
  }

  // Adjacency list with weights
  cout << "\nWeighted adjacency list:\n";
  for (const auto &adj_list : graph.adj_list)
  {
    for (const auto &edge : adj_list)
    {
      cout << edge.first << "(w " << edge.second << ") -> ";
    }
    cout << "null" << endl;
  }

  // Run Dijkstra's algorithm
  auto all_distances = dijkstra_all(graph);
  print_dijkstra_all(all_distances);

  // Run Floyd-Warshall algorithm
  auto resulting_matrix = floyd_warshall(graph);
  print_floyd_warshall(resulting_matrix);
  return 0;
}
