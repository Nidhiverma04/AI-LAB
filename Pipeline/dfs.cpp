#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include "puzzle_utils.h"

using namespace std;

bool dfs_goal_found = false;
void dfs_get_state(state* s, vector<vector<vector<int>>>& visited, int n, const vector<vector<int>>& goal) {
    
    if (dfs_goal_found) return; 

    visited.push_back(s->state_array);

    if (is_goal(goal, s->state_array)) {
        int count = 0;
        print_path(s, n, count);
        cout << "Count : " << count << "\n";
        dfs_goal_found = true;
        return;
    }

    int blankX = 0, blankY = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s->state_array[i][j] == 0) {
                blankX = i;
                blankY = j;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        int newX = blankX + row_moves[i];
        int newY = blankY + col_moves[i];

        if (isValid(newX, newY, n)) {
            vector<vector<int>> new_board = copy_board(s->state_array);
            swap(new_board[blankX][blankY], new_board[newX][newY]);

            if (!is_visited(visited, new_board)) {
                state* child = new state{s, new_board, s->state_no + 1};
                dfs_get_state(child, visited, n, goal);
            }
        }
    }
}

// ✅ Entry function for DFS
void runDFS(const vector<vector<int>>& puzzle, int n) {
    dfs_goal_found = false;
    vector<vector<int>> goal(n, vector<int>(n));
    int num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            goal[i][j] = num++;
        }
    }
    goal[n - 1][n - 1] = 0;

    state* s1 = new state{nullptr, puzzle, 0};

    cout << "\nRunning DFS...\n";
    vector<vector<vector<int>>> visited;
    dfs_get_state(s1, visited, n, goal);
}
