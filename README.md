Got it 👍 You want me to structure your **DFS 8-puzzle code explanation** in the same style as your cosine similarity lab write-up. Here’s the formatted version for your given code:

---

## **LAB-2 (23 January 2025)**

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

---

Do you also want me to prepare **one test case where DFS will go into a long search before reaching the solution** (so you can check how it explores unnecessary paths)?
