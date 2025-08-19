#include "puzzle_utils.h"

int row_moves[4] = {0, 0, -1, 1};
int col_moves[4] = {-1, 1, 0, 0};

bool isValid(int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

bool is_goal(const vector<vector<int>>& goal, const vector<vector<int>>& state) {
    return goal == state;
}

void print_path(state* s, int n, int& count) {
    if (s == nullptr) return;
    count++;
    print_path(s->parent, n, count);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << s->state_array[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "----\n";
}

vector<vector<int>> copy_board(const vector<vector<int>>& src) {
    return src;
}

bool is_visited(const vector<vector<vector<int>>>& visited,
                const vector<vector<int>>& board) {
    return find(visited.begin(), visited.end(), board) != visited.end();
}

int displaced_count(state* s, int n) {
    int count = 0, num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(s->state_array[i][j] != num++){
                count++;
            }
        }
    }
    return count;
}
