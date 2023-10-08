import random

# Initialize a 100x100 maze filled with '0's
maze = [['0' for _ in range(100)] for _ in range(100)]

# Create a simple path from (0,0) to (99,99) using a straight line along the top row and the last column
for i in range(100):
    maze[0][i] = '1'
    maze[i][99] = '1'

# Randomly set some other cells to '1' (while avoiding the path)
for i in range(1, 100):  # Start from 1 to avoid overwriting the initial path
    for j in range(99):  # End at 99 to avoid overwriting the initial path
        maze[i][j] = str(random.choice([0, 1]))

# Write maze to file
with open("test5-large-maze.txt", "w") as f:
    f.write("100 100\n")
    for row in maze:
        f.write(" ".join(row) + "\n")
