## **LAB-1 (14 August 2025)**

**QUES 1 ->**
**AIM :** To solve the 8-puzzle problem using Depth First Search (DFS) and print the path from the initial state to the goal state.

**WORKING :**

1. **Start**
2. **Input Puzzle Configuration:**

   * Read the puzzle size `n`.
   * Take input for the puzzle elements.
   * Identify the blank tile position (`0`).
3. **Set Goal State:**

   * Goal is defined as numbers arranged in increasing order with blank tile (0) at the last position.
4. **DFS Exploration:**

   * Initialize the state with input puzzle.
   * Recursively expand nodes by moving the blank tile in 4 possible directions (left, right, up, down).
   * Generate new states by swapping tiles.
   * If the new state has not been visited before, continue DFS from that state.
5. **Goal Test:**

   * At each step, check if the current state matches the goal.
   * If yes, print the path from root to current state.
6. **Path Printing:**

   * Print each intermediate state from the initial configuration to the goal configuration.
   * Count the number of moves taken.
7. **Stop**

**OUTPUT :**
Example Input –

```
Enter size : 3  
Enter number on index (0 0) : 1  
Enter number on index (0 1) : 2  
Enter number on index (0 2) : 3  
Enter number on index (1 0) : 4  
Enter number on index (1 1) : 0  
Enter number on index (1 2) : 5  
Enter number on index (2 0) : 6  
Enter number on index (2 1) : 7  
Enter number on index (2 2) : 8  
```

Expected Output – (path till goal state)

```
1 2 3  
4 0 5  
6 7 8  
----
1 2 3  
4 5 0  
6 7 8  
----
1 2 3  
4 5 8  
6 7 0  
----
Goal Reached  
Count : 3
```

**TIME COMPLEXITY :**
Worst Case = **O(b^d)**, where

* `b` = branching factor (≤ 4 moves possible),
* `d` = depth of the solution.

**SPACE COMPLEXITY :**
Worst Case = **O(b^d)** due to recursive DFS stack and visited states.

**QUES 2 ->**
**AIM :** To solve the 8-puzzle problem using **Breadth First Search (BFS)** and print the path from the initial state to the goal state.

**WORKING :**

1. **Start**
2. **Input Puzzle Configuration:**

   * Read the puzzle size `n`.
   * Take input for the puzzle elements.
   * Identify the blank tile position (`0`).
3. **Set Goal State:**

   * Goal is defined as numbers arranged in increasing order with blank tile (`0`) at the last position.
4. **BFS Exploration:**

   * Initialize the root node with the input puzzle configuration.
   * Create an empty **queue** and **visited list**.
   * Enqueue the root node into the queue.
   * While the queue is not empty:

     * Dequeue the front state.
     * If it matches the goal → print path and stop.
     * Otherwise, expand by moving the blank tile in **4 possible directions** (Left, Right, Up, Down).
     * Generate new states by swapping tiles.
     * If a new state has not been visited → enqueue it and mark as visited.
5. **Goal Test:**

   * At each step, check if the dequeued state = goal state.
   * If yes → print path from initial state to goal.
6. **Path Printing:**

   * Trace parent pointers back from goal to root.
   * Print each intermediate state.
   * Count number of moves taken.
7. **Stop**

**OUTPUT :**
Example Input –

```
Enter size : 3  
Enter number on index (0 0) : 1  
Enter number on index (0 1) : 2  
Enter number on index (0 2) : 3  
Enter number on index (1 0) : 4  
Enter number on index (1 1) : 0  
Enter number on index (1 2) : 6  
Enter number on index (2 0) : 7  
Enter number on index (2 1) : 5  
Enter number on index (2 2) : 8  
```

Expected Output – (shortest path till goal state)

```
1 2 3  
4 0 6  
7 5 8  
----
1 2 3  
4 5 6  
7 0 8  
----
1 2 3  
4 5 6  
7 8 0  
----
Goal Reached  
Count : 2
```

**TIME COMPLEXITY :**
Worst Case = **O(b^d)**, where

* `b` = branching factor (≤ 4 moves possible),
* `d` = depth of the solution.

BFS guarantees the **shortest solution path** but explores more states.

**SPACE COMPLEXITY :**
Worst Case = **O(b^d)** due to storage of all nodes in the queue and visited set.

**QUES 3 →**
**AIM :** To solve the 8-puzzle problem using **A\* Search (Heuristic Search)** and print the path from the initial state to the goal state.

**WORKING :**

1. **Start**
2. **Input Puzzle Configuration:**

   * Read the puzzle size `n`.
   * Take input for the puzzle elements.
   * Identify the blank tile position (`0`).
3. **Set Goal State:**

   * Goal is defined as numbers arranged in increasing order with blank tile (`0`) at the last position.
4. **Heuristic Function:**

   * Use **Manhattan Distance** as heuristic `h(n)` → sum of distances of each tile from its goal position.
   * `f(n) = g(n) + h(n)` where

     * `g(n)` = cost from root to current node (number of moves),
     * `h(n)` = heuristic estimate to goal.
5. **A\* Exploration:**

   * Initialize a **priority queue (min-heap)** ordered by `f(n)`.
   * Insert the root node with `g=0`.
   * Maintain a **visited set**.
   * While the priority queue is not empty:

     * Remove the node with **smallest f(n)**.
     * If it matches the goal → print path and stop.
     * Otherwise, expand by moving blank tile in 4 possible directions.
     * For each child state:

       * Compute `g = parent.g + 1`.
       * Compute `h` using Manhattan distance.
       * Push child with `f=g+h` into priority queue (if not visited earlier).
6. **Goal Test:**

   * At each expansion, check if the current state equals the goal state.
   * If yes → print path from initial state to goal.
7. **Path Printing:**

   * Trace parent pointers back from goal to root.
   * Print each intermediate state.
   * Count number of moves taken.
8. **Stop**

**OUTPUT :**

Example Input –

```
Enter size : 3  
Enter number on index (0 0) : 1  
Enter number on index (0 1) : 2  
Enter number on index (0 2) : 3  
Enter number on index (1 0) : 4  
Enter number on index (1 1) : 5  
Enter number on index (1 2) : 6  
Enter number on index (2 0) : 0  
Enter number on index (2 1) : 7  
Enter number on index (2 2) : 8  
```

Expected Output – (optimal path found using heuristic)

```
1 2 3  
4 5 6  
0 7 8  
----  
1 2 3  
4 5 6  
7 0 8  
----  
1 2 3  
4 5 6  
7 8 0  
----  
Goal Reached  
Count : 2
```

**TIME COMPLEXITY :**

* Worst Case ≈ **O(b^d)** but with heuristic pruning, actual explored nodes << BFS.
* In practice, A\* is much faster than BFS for large puzzles.

**SPACE COMPLEXITY :**

* **O(b^d)** since it stores nodes in the priority queue.
* Can be memory intensive for larger puzzles.

**QUES 4 →**
**AIM :** To solve the 8-puzzle problem using **Hill Climbing (Heuristic Search without backtracking)** and print the path from the initial state to the goal state, or stop at a **local maxima** if reached.

**WORKING :**

1. **Start**
2. **Input Puzzle Configuration:**

   * Read the puzzle size `n`.
   * Take input for the puzzle elements.
   * Identify the blank tile position (`0`).
3. **Set Goal State:**

   * Goal is defined as numbers arranged in increasing order with blank tile (`0`) at the last position.
4. **Heuristic Function:**

   * Use **Misplaced Tiles Count** as heuristic → `h(n)` = number of tiles not in their goal position.
   * Smaller `h(n)` = closer to goal.
5. **Hill Climbing Exploration:**

   * Initialize the root node with the input puzzle configuration.
   * Maintain a **stack** and **visited list**.
   * While stack is not empty:

     * Pop the top state.
     * If it matches the goal → print path and stop.
     * Otherwise:

       * Expand by moving blank tile in 4 possible directions.
       * Generate child states.
       * For each child, compute heuristic value (`displaced_count`).
       * Select the **best child** with **lower h(n)** than the current node.
       * If such a child exists → push it onto stack.
       * Otherwise → no better move → **local maxima reached**, stop.
6. **Goal Test:**

   * At each step, check if current state equals goal.
   * If yes → print path to goal.
   * If no better move exists → declare **Local Maxima**.
7. **Path Printing:**

   * Trace parent pointers back from goal (or local maxima) to root.
   * Print each intermediate state.
   * Count number of moves taken.
8. **Stop**

**OUTPUT :**

Example Input –

```
Enter size : 3  
Enter number on index (0 0) : 1  
Enter number on index (0 1) : 2  
Enter number on index (0 2) : 3  
Enter number on index (1 0) : 4  
Enter number on index (1 1) : 6  
Enter number on index (1 2) : 0  
Enter number on index (2 0) : 7  
Enter number on index (2 1) : 5  
Enter number on index (2 2) : 8  
```

Expected Output – (stops at **local maxima**)

```
1 2 3  
4 6 0  
7 5 8  
----  
1 2 3  
4 0 6  
7 5 8  
----  
Local maxima Reached !!  
Count : 2
```

**TIME COMPLEXITY :**

* Worst Case ≈ **O(b·d)** where

  * `b` = branching factor (≤4 moves),
  * `d` = depth of search until stuck.
* Much lower than BFS/A\*, but **not complete** (may fail).

**SPACE COMPLEXITY :**

* **O(d)** since only current path is stored.

# **LAB-2 (21 August 2025)**

**QUES 1 →**
**AIM :** To solve the **Grid Pathfinding Problem** using **A\* Search Algorithm (with Manhattan Distance heuristic)** and print the shortest path from a given **source** to the **destination**, or print **“No solution found”** if blocked by obstacles.

**WORKING :**

1. **Start**
2. **Input Grid Configuration:**

   * Read grid size `n × n`.
   * Read **source** coordinates `(i, j)` and set `g = 0`.
   * Read **destination** coordinates `(dest_i, dest_j)`.
3. **Obstacles Setup:**

   * Allow user to mark some grid cells as **water cells (blocked)**.
   * For obstacles → set `g = ∞` and `h = ∞`.
4. **Heuristic Function:**

   * Use **Manhattan Distance**:

     $$
     h(n) = |x - dest_x| + |y - dest_y|
     $$
   * Each cell stores `{g, h}`, where:

     * `g = cost from source`
     * `h = heuristic (Manhattan distance to goal)`
5. **A\* Search Exploration:**

   * Maintain a **min-heap (priority queue)** ordered by:

     $$
     f(n) = g(n) + h(n)
     $$
   * Push initial state into the priority queue.
   * Maintain a **visited matrix**.

   While queue is not empty:

   * Pop the state with lowest `f(n)`.
   * If this is the destination → **print path** and stop.
   * Otherwise:

     * Expand neighbors (up, down, left, right).
     * For valid cells:

       * Update `g` and `h`.
       * Push into priority queue.
6. **Goal Test:**

   * If current cell = destination → success.
   * If queue empties without reaching destination → **No solution found**.
7. **Path Printing:**

   * Trace back using **parent pointers** from goal to source.
   * Print sequence of coordinates in order.
8. **Stop**

**OUTPUT :**

Example Input –

```
Enter grid size (n): 5
Enter source (x y): 0 0
Enter destination (x y): 4 4
Enter indices with water (obstacles): 
Enter water cell (x y): 1 2
Do you want to enter more water cells? (y/n): y
Enter water cell (x y): 2 2
Do you want to enter more water cells? (y/n): y
Enter water cell (x y): 3 1
Do you want to enter more water cells? (y/n): n
```

Possible Output –

```
Path found:
(0,0)
(0,1)
(0,2)
(0,3)
(0,4)
(1,4)
(2,4)
(3,4)
(4,4)
```

If no valid route exists:

```
No solution found!
```

**TIME COMPLEXITY :**

* Worst Case ≈ **O(b^d)** per step, with a poorly chosen or non-admissible heuristic, the time complexity can be exponential:
  where:
  `b` represents the branching factor, which is the average number of successor states or edges originating from a given node.

`d` signifies the depth of the shallowest goal state or the length of the shortest path.

*However, when using an admissible and consistent heuristic (one that never overestimates the true cost to reach the goal), the A* algorithm is more efficient, with its time complexity bounded by:

**O(E log E)**, where:
E is the number of edges in the graph

**SPACE COMPLEXITY :**

**O(n²)** for grid storage, visited array, and priority queue.

<img width="794" height="482" alt="image" src="https://github.com/user-attachments/assets/f671d076-a9b2-43b5-88fa-af707cef7bd2" />

**QUES 2 →**
**AIM :** To solve the **Water Jug Problem** using **Depth First Search (DFS)** and print the sequence of states (amount of water in both jugs) that leads to the target amount in the desired jug. If no sequence exists, print **“No solution found.”**

**WORKING :**

1. **Start**
2. **Input Parameters:**

   * Read capacity of Jug X (`capacity1`).
   * Read capacity of Jug Y (`capacity2`).
   * Read target amount of water `target`.
   * Read jug number (`targetJug`) in which the target should be achieved (1 for X, 2 for Y).
3. **Representation of State:**

   * A state is represented as a pair `(jug1, jug2)` where

     * `jug1 = amount of water in Jug X`
     * `jug2 = amount of water in Jug Y`.
4. **Visited States:**

   * Maintain a `set` to avoid revisiting the same state.
5. **DFS Exploration:**

   * Start from initial state `(0,0)`.
   * For each state, generate possible moves:

     * **Fill Jug X**: `(capacity1, jug2)`
     * **Fill Jug Y**: `(jug1, capacity2)`
     * **Empty Jug X**: `(0, jug2)`
     * **Empty Jug Y**: `(jug1, 0)`
     * **Pour Jug X → Jug Y** until Jug X empty or Jug Y full.
     * **Pour Jug Y → Jug X** until Jug Y empty or Jug X full.
   * Push each new state into DFS recursion.
   * If the target is achieved in the required jug → stop.
6. **Goal Test:**

   * If `(jug1 == target && targetJug == 1)` OR `(jug2 == target && targetJug == 2)`
     → print the path and terminate.
7. **Path Printing:**

   * Keep a vector of visited states (`path`).
   * On success, print sequence of states from `(0,0)` to goal.
8. **Stop**

**OUTPUT :**

Example Input –

```
Enter capacity of jug X: 3
Enter capacity of jug Y: 5
Enter target amount of water: 4
In which jug do you want the target (1 for X, 2 for Y)? 2
```

Possible Output –

```
Solution steps:
(0, 0)
(3, 0)
(3, 5)
(0, 5)
(3, 2)
(0, 2)
(2, 0)
(2, 5)
(3, 4)
```

If no solution exists –

```
No solution found.
```

**TIME COMPLEXITY :**

* In worst case,
* Maximum states ≈ **(capacity1 + 1) × (capacity2 + 1)**.
* Therefore, Time Complexity = **O(capacity1 × capacity2)**.

**SPACE COMPLEXITY :**

**O(capacity1 × capacity2)** for visited set and recursion stack.

<img width="1220" height="842" alt="image" src="https://github.com/user-attachments/assets/5ccc59f5-21cf-4443-85ba-14678d731e66" />


## **LAB-3 (28 August 2025)**

**AIM :**
To implement the **Tic Tac Toe Game** using the **Minimax Algorithm** and generate a **Game Tree** to determine the best possible move for the computer. The program allows a human player to play against the computer (which always plays optimally).


**WORKING :**

1. **Start**

2. **Input Parameters:**

   * A 3×3 Tic Tac Toe board initialized with all cells as empty (`'_'`).
   * Computer plays as **‘X’ (maximizer)** and user plays as **‘O’ (minimizer)**.

3. **Representation of State:**

   * Each state is represented by a structure containing:

     * `board` → current configuration of the grid.
     * `score` → evaluation value of the state.
     * `isMax` → Boolean indicating whether it’s **X’s turn** or **O’s turn**.
     * `children` → list of possible next states.
     * `parent` → pointer to previous state.

4. **Utility Functions:**

   * **`moves_left()`** → checks if any cell is empty.
   * **`get_score()`** → returns

     * `+1` if X wins,
     * `-1` if O wins,
     * `0` otherwise.
   * **`print_board()`** → displays the current board.

5. **Game Tree Generation:**

   * Implemented using **recursive function** `generate_tree(State *s)`.
   * For each state:

     * If the board is full or a player has won → return the score.
     * Otherwise, generate all possible moves:

       * If `isMax = true` → place **‘X’** in all empty cells, create child states, and choose the **maximum score** among them.
       * If `isMax = false` → place **‘O’** in all empty cells, create child states, and choose the **minimum score** among them.

6. **Goal Test:**

   * If `get_score()` returns `1` → **Computer (X) wins**.
   * If `get_score()` returns `-1` → **Player (O) wins**.
   * If no moves are left → **Draw**.

7. **Gameplay:**

   * The user enters their move `(row, column)`.
   * Computer responds using the **best move** obtained from the Minimax tree.
   * Board is printed after every move until a win or draw occurs.

8. **Stop**


**OUTPUT :**

_ -_ _  
_- _ _   
_- _ _   

Enter your move (row col, 0-indexed): 1 1

_- _ _   
_ O _   
_ -_ _   

Computer plays:

X _ _   
_ O _   
_- _ _   

Enter your move (row col, 0-indexed): 1 0

X _ _  
O O _  
_ -_ _  

Computer plays:

X _ _  
O O X  
_- _ _  

Enter your move (row col, 0-indexed): 2 1

X _ _  
O O X  
_ O _  

Computer plays:

X X _  
O O X  
_ O _  

Enter your move (row col, 0-indexed): 2 0

X X _  
O O X  
O O _  

Computer plays:

X X X  
O O X  
O O _  

Computer (X) wins!



**TIME COMPLEXITY :**

* For an n×n Tic Tac Toe board,
  **Time Complexity = O(b^d)**
  where
  `b` = branching factor (possible moves at each turn)
  `d` = depth of the game tree (maximum number of moves).

* For 3×3 Tic Tac Toe, maximum states ≈ **9! = 362,880**.


**SPACE COMPLEXITY :**

* **O(b × d)** due to recursion stack and storage of game tree nodes.




