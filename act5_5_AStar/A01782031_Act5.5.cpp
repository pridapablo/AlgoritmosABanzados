/*
Maze solver using the A* algorithm (BFS + heuristic), considering a square maze.

Input:
    - A 0-1 matrix representing the maze

Output:
    - A string with the series of moves to solve the maze, represented by the letters U(up),
    D(down), L(left) and R(right).

The program assumes the starting point is the top left corner and the ending
point is the bottom right corner.

Edited on 22/nov/2023 - Pablo Banzo Prida
*/

#include "a_star.hpp" // a_star
#include <iostream>

using namespace std;

// Global variables for the maze
int n = 4; // maze size
vector<vector<int>> maze = {
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {1, 1, 0, 0},
    {0, 1, 1, 1}};

// main function
int main()
{
    // Solve the maze
    string path = aStar(maze, n, {0, 0}, {n - 1, n - 1});

    // Print the path
    cout << path << endl;

    return 0;
}
