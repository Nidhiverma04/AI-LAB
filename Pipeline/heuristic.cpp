#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include "puzzle_utils.h"

using namespace std;


void heuristic_get_state(state* s, vector<vector<vector<int>>>& visited, int n, const vector<vector<int>>& goal) {
    stack<state*> st;
    st.push(s);
    visited.push_back(s->state_array);

    while (!st.empty()) {
        state* temp = st.top();
        st.pop();

        if (is_goal(goal, temp->state_array)) {
            int count = 0;
            print_path(temp, n, count);
            cout << "Count : " << count << "\n";
            return;
        }

        int blankX = 0, blankY = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (temp->state_array[i][j] == 0) {
                    blankX = i; blankY = j;
                }
            }
        }

        int bestH = INT_MAX;
        state* bestChild = nullptr;

        for (int i = 0; i < 4; i++) {
            int newX = blankX + row_moves[i];
            int newY = blankY + col_moves[i];
            if (isValid(newX, newY, n)) {
                vector<vector<int>> new_board = copy_board(temp->state_array);
                swap(new_board[blankX][blankY], new_board[newX][newY]);
                if (!is_visited(visited, new_board)) {
                    state* child = new state{temp, new_board, temp->state_no + 1};
                    visited.push_back(new_board);
                    int h = displaced_count(child, n);
                    if (h < bestH) {
                        bestH = h;
                        bestChild = child;
                    }
                }
            }
        }
        if (bestChild != nullptr) st.push(bestChild);
    }
}

// ✅ Entry function for Heuristic
void runHeuristic(const vector<vector<int>>& puzzle, int n) {
    // Create goal state
    vector<vector<int>> goal(n, vector<int>(n));
    int num = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            goal[i][j] = num++;
    goal[n - 1][n - 1] = 0;

    state* s1 = new state{nullptr, puzzle, 0};

    cout << "\nRunning Heuristic Search...\n";
    vector<vector<vector<int>>> visited;
    heuristic_get_state(s1, visited, n, goal);
}
