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

##  


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

##

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

##  


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
