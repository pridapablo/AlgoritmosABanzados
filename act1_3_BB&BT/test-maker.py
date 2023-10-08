import random

def generate_maze(n, m):
    # Initialize an n x m maze filled with '0's
    maze = [['0' for _ in range(m)] for _ in range(n)]

    # Create a simple path from (0,0) to (n-1, m-1) using a straight line along the top row and the last column
    for i in range(m):
        maze[0][i] = '1'
    for i in range(n):
        maze[i][m - 1] = '1'

    # Randomly set some other cells to '1' (while avoiding the path)
    for i in range(1, n):  # Start from 1 to avoid overwriting the initial path
        for j in range(m - 1):  # End at m-1 to avoid overwriting the initial path
            maze[i][j] = str(random.choice([0, 1]))

    # Write maze to file
    with open(f"test{n}x{m}-maze.txt", "w") as f:
        f.write(f"{n} {m}\n")
        for row in maze:
            f.write(" ".join(row) + "\n")

# Generate a 100 x 100 maze
generate_maze(30,20);
