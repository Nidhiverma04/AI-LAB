#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct state {
    state* parent;
    vector<vector<int>> state_array;
    int state_no;
};

int row_moves[] = {0, 0, -1, 1};
int col_moves[] = {-1, 1, 0, 0};

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

void get_state(state* s, vector<vector<vector<int>>>& visited, int n, const vector<vector<int>>& goal) {

    queue<state*> q;
    q.push(s);
    visited.push_back(s->state_array);


    while(!q.empty()){
        state* temp = q.front();

        if (is_goal(goal, temp->state_array)) {
            int count = 0;
            print_path(temp, n, count);
            cout<<"Count : "<<count;
            return;
        }

        int blankX = 0, blankY = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (temp->state_array[i][j] == 0) {
                    blankX = i;
                    blankY = j;
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            int newX = blankX + row_moves[i];
            int newY = blankY + col_moves[i];

            if (isValid(newX, newY, n)) {
                vector<vector<int>> new_board = copy_board(temp->state_array);
                swap(new_board[blankX][blankY], new_board[newX][newY]);

                if(!is_visited(visited, new_board)){
                    state* child = new state{temp, new_board, temp->state_no + 1}; 
                    visited.push_back(new_board);
                    q.push(child);
                }
            }
        }
        q.pop();
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

    vector<vector<vector<int>>> visited;
    get_state(s1, visited, n, goal);

}
