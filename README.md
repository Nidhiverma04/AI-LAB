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
Enter number on index (1 2) : 5  
Enter number on index (2 0) : 6  
Enter number on index (2 1) : 7  
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

