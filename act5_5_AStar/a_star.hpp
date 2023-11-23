#ifndef A_STAR_HPP
#define A_STAR_HPP

#include "types.hpp"     // MinHeap (priority queue)
#include "heuristic.hpp" // heuristic
#include <string>        // string
#include <vector>        // vector

using namespace std;

/*
    Reconstruct the path from the starting point to the ending point.
*/
string reconstructPath(const vector<vector<pair<int, int>>> &cameFrom, pair<int, int> start, pair<int, int> end)
{
    string path = "";
    string newLetter = ""; // temporary variable to store the new letter
    pair<int, int> currentCell = end;

    while (currentCell != start)
    {
        pair<int, int> parentCell = cameFrom[currentCell.first][currentCell.second];
        if (parentCell.first == currentCell.first)
        {
            newLetter = (parentCell.second < currentCell.second) ? "R" : "L";
        }
        else
        {
            newLetter = (parentCell.first < currentCell.first) ? "D" : "U";
        }
        path = newLetter + path;
        currentCell = parentCell;
    }
    return path;
}

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
    MinHeap mh;
    vector<vector<pair<int, int>>> cameFrom(n, vector<pair<int, int>>(n, {-1, -1}));
    vector<vector<int>> costSoFar(n, vector<int>(n, INT_MAX));

    int nodeID = start.first * n + start.second;
    mh.push(Node(nodeID, 0));
    costSoFar[start.first][start.second] = 0;

    while (!mh.empty())
    {
        Node current = mh.top();
        mh.pop();

        if (current.nodeID == end.first * n + end.second)
        {
            return reconstructPath(cameFrom, start, end);
        }

        // Von Neumann neighborhood (4 neighbors)
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};

        // Get the coordinates of the current node from its ID
        int x = current.nodeID / n;
        int y = current.nodeID % n;

        // Iterate through orthogonal neighbors
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            // Bounds check
            if (newX >= 0 && newX < n && newY >= 0 && newY < n)
            {
                // Check if the neighbor is walkable
                if (maze[newX][newY] == 1)
                {
                    // Calculate the cost of the path to the neighbor
                    int newCost = costSoFar[x][y] + 1;

                    // If the cost is lower than the current cost, update the cost and the parent
                    if (newCost < costSoFar[newX][newY])
                    {
                        int newID = newX * n + newY; // ID of the neighbor
                        costSoFar[newX][newY] = newCost;
                        cameFrom[newX][newY] = {x, y};
                        mh.push(Node(newID, newCost + heuristic({newX, newY}, end)));
                    }
                }
            }
        }
    }

    return "No path found";
}

#endif