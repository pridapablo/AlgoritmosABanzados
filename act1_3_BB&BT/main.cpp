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

using namespace std;

// Global variables
int M, N;
vector<vector<bool>> maze;
vector<vector<bool>> btsolution;
vector<vector<bool>> bbsolution;

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

  file.close();
}
// Alias for readFile() to comply with the assignment requirements
void leeArchivo(string fileName) { return readFile(fileName); }

/*
  Backtracking algorithm to solve maze.

  @param x: abscissa of current position in maze.
  @param y: ordinate of current position in maze.

  @return: True if a solution is found, false otherwise to backtrack and try another solution.
*/
bool backtracking(int x, int y)
{
  if (x == M - 1 && y == N - 1) // Goal
  {
    btsolution[x][y] = true;
    return true;
  }

  else if (x < 0 || x >= M || y < 0 || y >= N) // Out of bounds
    return false;
  else if (maze[x][y] == 0) // Traversable cell
    return false;

  else
  {
    btsolution[x][y] = true;
    // Recursive calls to solve maze moving in all four directions

    if (backtracking(x + 1, y))
      return true;

    if (backtracking(x, y + 1))
      return true;

    if (backtracking(x - 1, y))
      return true;

    if (backtracking(x, y - 1))
      return true;
  }

  btsolution[x][y] = false;
  return false;
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

  cout << "Branch-and-bound solution:\n";
  for (auto row : bbsolution)
  {
    for (auto cell : row)
    {
      cout << (cell ? '1' : '0') << " ";
    }
    cout << "\n";
  }
}
// Alias for printSolutions() to comply with the assignment requirements
void imprimeSolucion() { return printSolutions(); }

void branchAndBound()
{
  return;
}

int main()
{
  leeArchivo("maze.txt");
  imprimeSolucion();
  return 0;
}