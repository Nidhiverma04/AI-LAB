#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct state {
    state* parent;
    vector<vector<int>> state_array;
    int state_no;
};

int row_moves[] = {0, 0, -1, 1};
int col_moves[] = {-1, 1, 0, 0};

bool isValid(int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

vector<vector<int>> get_puzzle(int n, int& state_i, int& state_y) {
    vector<vector<int>> puzzle(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Enter number on index (" << i << " " << j << ") : ";
            cin >> puzzle[i][j];
            if (puzzle[i][j] == 0) {
                state_i = i;
                state_y = j;
            }
        }
    }
    return puzzle;
}

bool is_goal(const vector<vector<int>>& goal, const vector<vector<int>>& state) {
    return goal == state;
}

void print_path(state* s, int n) {
    if (s == nullptr) return;
    print_path(s->parent, n);

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

void get_state(state* s, vector<vector<vector<int>>>& visited, int n, const vector<vector<int>>& goal) {
    visited.push_back(s->state_array);

    if (is_goal(goal, s->state_array)) {
        print_path(s, n);
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

            if(!is_visited(visited, new_board)){
                state* child = new state{s, new_board, s->state_no + 1}; 
                get_state(child, visited, n, goal);
            }
        }
    }
}

int main() {
    int n, x, y;
    cout << "Enter size : ";
    cin >> n;

    vector<vector<int>> puzzle = get_puzzle(n, x, y);
    cout << "X and Y " << x << " " << y << endl;

    vector<vector<int>> goal(n, vector<int>(n));
    int num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            goal[i][j] = num++;
        }
    }
    goal[n - 1][n - 1] = 0;

    state* s1 = new state{nullptr, puzzle, 0};

    cout << "Given state : \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << puzzle[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<vector<int>>> visited;
    get_state(s1, visited, n, goal);
}

