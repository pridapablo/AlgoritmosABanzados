/**
  Maze Solver in C++ using Backtracking and Branch-and-Bound

  Reads a 2D boolean grid from an input file, where '1' is traversable and '0' is not.
  Finds a path from cell (0, 0) to (M-1, N-1), with M and N as maze dimensions.

  Functions:
  - leeArchivo(string): Reads input file.
  - imprimeSolucion(): Prints solutions.
  - backtracking(): Uses backtracking algorithm.
  - branchAndBound(): Uses branch-and-bound algorithm.

  Outputs solutions as 2D grids, first using backtracking, then branch-and-bound.

  Author: Pablo Banzo Prida - A01782031
  Date: 08/10/2023
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <climits>

using namespace std;

// Global variables
int M, N;
vector<vector<bool>> maze;       // Maze matrix
vector<vector<bool>> btsolution; // Solution found by backtracking algorithm
vector<vector<bool>> bbsolution; // Solution found by branch-and-bound algorithm
int bbminSteps = INT_MAX;        // Minimum number of steps to reach goal in branch-and-bound algorithm

/*
  Reads input file and stores data in global variables.
  O(MxN) time complexity (where M is maze height and N is maze width).

  @param fileName: Name of input file.
*/
void readFile(string fileName)
{
  ifstream file(fileName);

  if (!file)
  {
    cout << "Error opening file: " << fileName << "\n";
    return;
  }

  string line;

  if (getline(file, line)) // First line has maze dimensions
  {
    stringstream ss(line);
    if (!(ss >> M >> N))
    {
      cout << "Error reading maze dimensions.\n";
      return;
    }

    maze.resize(M, vector<bool>(N));
    btsolution.resize(M, vector<bool>(N));
    bbsolution.resize(M, vector<bool>(N));
    cout << "Maze dimensions: " << M << " x " << N << "\n";

    // initialize vectors with false values
    for (int i = 0; i < M; i++)
    {
      for (int j = 0; j < N; j++)
      {
        maze[i][j] = false;
        btsolution[i][j] = false;
        bbsolution[i][j] = false;
      }
    }
  }
  else
  {
    cout << "Error reading maze dimensions.\n";
    return;
  }

  for (int i = 0; i < M; i++)
  {
    if (getline(file, line))
    {
      stringstream ss(line);
      for (int j = 0; j < N; j++)
      {
        int value;
        if (!(ss >> value))
        {
          cout << "Error reading maze matrix: failed to extract integer.\n";
          return;
        }
        maze[i][j] = value;
        cout << value << " ";
      }
      cout << "\n";
    }
    else
    {
      cout << "Error reading maze matrix.\n";
      return;
    }
  }

  cout << "Maze matrix read successfully.\n";

  file.close();
}
// Alias for readFile() to comply with the assignment requirements
void leeArchivo(string fileName) { readFile(fileName); }

/*
  Backtracking algorithm to solve maze.

  @param x: abscissa of current position in maze.
  @param y: ordinate of current position in maze.

  @return: True if a solution is found, false otherwise to backtrack and try another solution.
*/
bool backtracking(int x, int y)
{
  if (x < 0 || x >= M || y < 0 || y >= N) // Out of bounds
    return false;
  if (maze[x][y] == 0 || btsolution[x][y]) // Non-traversable cell or already visited
    return false;

  // Mark as part of solution path
  btsolution[x][y] = true;

  if (x == M - 1 && y == N - 1) // Goal
    return true;

  // Move in all possible directions
  if (backtracking(x + 1, y) || backtracking(x, y + 1) || backtracking(x - 1, y) || backtracking(x, y - 1))
    return true;

  // Backtrack
  btsolution[x][y] = false;

  return false;
}

int branchAndBound(int x, int y, int steps, vector<vector<bool>> &currentPath)
{
  if (x == M - 1 && y == N - 1) // Goal
  {
    currentPath[x][y] = true; // Part of solution
    if (steps < bbminSteps)   // Update minimum number of steps to reach goal
    {
      bbminSteps = steps;
      bbsolution = currentPath; // Current path is the best solution so far
    }
    return steps;
  }

  if (x < 0 || x >= M || y < 0 || y >= N) // Out of bounds
    return INT_MAX;

  if (maze[x][y] == 0) // Not traversable
    return INT_MAX;

  if (steps >= bbminSteps) // Step prune
    return INT_MAX;

  int manhattanDistance = abs(M - 1 - x) + abs(N - 1 - y); // Manhattan distance to goal (relaxation)

  if (steps + manhattanDistance >= bbminSteps) // Relaxation prune
    return INT_MAX;

  currentPath[x][y] = true; // Add current cell to path

  // Try all 4 directions
  int down = branchAndBound(x + 1, y, steps + 1, currentPath);
  int right = branchAndBound(x, y + 1, steps + 1, currentPath);
  int up = branchAndBound(x - 1, y, steps + 1, currentPath);
  int left = branchAndBound(x, y - 1, steps + 1, currentPath);

  currentPath[x][y] = false; // Remove current cell from path

  // Return the minimum steps needed among all directions
  return min(min(down, right), min(up, left));
}

/*
  Prints globally stored solutions as 2D grids.
  O(MxN) time complexity (where M is maze height and N is maze width), asymptotically the two execution times (one for b&b and the other for bt) are equal.
 */
void printSolutions()
{
  if (backtracking(0, 0)) // Start at (0, 0) to find solution
  {
    cout << "Backtracking solution:\n";
    for (auto row : btsolution)
    {
      for (auto cell : row)
      {
        cout << (cell ? '1' : '0') << " ";
      }
      cout << "\n";
    }
  }
  else
  {
    cout << "No solution found using backtracking.\n";
  }

  vector<vector<bool>> currentPath(M, vector<bool>(N, false));
  int steps = branchAndBound(0, 0, 0, currentPath);

  if (steps != INT_MAX)
  {
    cout << "Branch-and-Bound solution found in " << steps << " steps: " << endl;
    for (auto row : bbsolution)
    {
      for (auto cell : row)
      {
        cout << (cell ? '1' : '0') << " ";
      }
      cout << "\n";
    }
  }
  else
  {
    cout << "No solution found using Branch-and-Bound.\n";
  }
}
// Alias for printSolutions() to comply with the assignment requirements
void imprimeSolucion() { printSolutions(); }

int main()
{
  const vector<string> tests = {"test0-example.txt", "test1-no-solution.txt", "test2-multiple-solutions.txt", "test3-single-cell.txt", "test4-all-walls", "test5-all-traversable.txt", "test6-20x30-maze.txt", "test7-660x50-maze.txt", "test8-100x100-maze.txt", "test9-30x20-maze.txt"};

  // leeArchivo(tests[6]);
  leeArchivo("test.txt");
  imprimeSolucion();

  return 0;
}