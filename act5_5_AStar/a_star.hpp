#ifndef A_STAR_HPP
#define A_STAR_HPP

#include "types.hpp"     // MinHeap (priority queue)
#include "heuristic.hpp" // heuristic
#include <string>        // string
#include <vector>        // vector}
#include <iostream>      // cout

using namespace std;

/*
    A* algorithm (BFS + heuristic) for a square maze.

    @param maze: 0-1 matrix representing the maze, where 0 is a non-walkable
    cell and 1 is a walkable cell
    @param n: size of the maze
    @param start: pair of coordinates of the starting point (x, y)
    @param end: pair of coordinates of the ending point (x, y)

    @return: a string with the series of moves to solve the maze, represented
    by the letters U(up), D(down), L(left) and R(right)
*/
string aStar(vector<vector<int>> &maze, int n, pair<int, int> start, pair<int, int> end)
{
    MinHeap mh;                                                                      // auto reheapifies since it's a priority queue
    vector<vector<pair<int, int>>> cameFrom(n, vector<pair<int, int>>(n, {-1, -1})); // -1 means no parent
    vector<vector<int>> costSoFar(n, vector<int>(n, INT_MAX));                       // current shortest path cost

    int nodeID = start.first * n + start.second; // ID of the starting node
    mh.push(Node(nodeID, 0));                    // push the starting node into the min heap
    costSoFar[start.first][start.second] = 0;    // cost of the initial node is 0

    // dx and dy arrays for the neighbors of a cell
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    cout << "Iniciando aStar con n = " << n << ", start = (" << start.first << ", " << start.second << "), end = (" << end.first << ", " << end.second << ")" << endl;

    while (!mh.empty())
    {
        Node current = mh.top(); // get the node with the lowest cost
        mh.pop();                // remove the node from the min heap

        cout << "Nodo actual: ID = " << current.nodeID << ", Costo = " << current.cost << endl;

        // If the current node is the goal node, return the path
        if (current.nodeID == end.first * n + end.second)
        {
            string path = "";
            pair<int, int> currentCell = end;

            // Reconstruct the path
            while (currentCell != start)
            {
                pair<int, int> parentCell = cameFrom[currentCell.first][currentCell.second];
                cout << "Reconstruyendo: Nodo actual = (" << currentCell.first << ", " << currentCell.second << "), Nodo padre = (" << parentCell.first << ", " << parentCell.second << ")" << endl;
                if (parentCell.first == currentCell.first)
                {
                    if (parentCell.second < currentCell.second)
                    {
                        path = "R" + path;
                        cout << "Movimiento: R (derecha)" << endl;
                    }
                    else
                    {
                        path = "L" + path;
                        cout << "Movimiento: L (izquierda)" << endl;
                    }
                }
                else
                {
                    if (parentCell.first < currentCell.first)
                    {
                        path = "D" + path;
                        cout << "Movimiento: D (abajo)" << endl;
                    }
                    else
                    {
                        path = "U" + path;
                        cout << "Movimiento: U (arriba)" << endl;
                    }
                }
                currentCell = parentCell;
            }

            return path;
        }

        // Get the coordinates of the current node from its ID
        int x = current.nodeID / n;
        int y = current.nodeID % n;
        cout << "Coordenadas del nodo actual: (" << x << ", " << y << ")" << endl;

        // Check the neighbors of the current node
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            // Solo explora el vecino si está dentro de los límites del laberinto
            if (newX >= 0 && newX < n && newY >= 0 && newY < n)
            {
                cout << "Explorando vecino: (" << newX << ", " << newY << ")" << endl;

                if (maze[newX][newY] == 1)
                {
                    int newID = newX * n + newY; // ID of the neighbor

                    // Calculate the cost of the path to the neighbor
                    int newCost = costSoFar[x][y] + 1;

                    // If the cost is lower than the current cost, update the cost and the parent
                    if (newCost < costSoFar[newX][newY])
                    {
                        costSoFar[newX][newY] = newCost;
                        cameFrom[newX][newY] = {x, y};
                        mh.push(Node(newID, newCost + heuristic({newX, newY}, end)));
                        cout << "Actualizando cameFrom y costSoFar para (" << newX << ", " << newY << ")" << endl;
                    }
                }
            }
        }
    }

    return "No path found";
}

#endif