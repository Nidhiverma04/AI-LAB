#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

int n = 3;

struct state {
    state* parent;
    vector<vector<char>> state_array; 
    int score;
};

bool isValid(int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int get_score(vector<vector<char>> board) {

    for (int i = 0; i<3; i++){
        if (board[i][0] == board[i][1] == board[i][2] and board[i][0] != '_'){
            return board[i][0] == 'X'? 1 :-1;
        }
        if (board[0][i] == board[1][i] == board[2][i] and board[0][i] != '_'){
            return board[0][i] == 'X'? 1 : -1;
        }
    }

 // Check diagonals
    if (board[0][0] == board[1][1] == board[2][2] and board[0][0] != '_'){
        return board[0][0] == 'X'? 1 : -1;   
    }
    if (board[0][2] == board[1][1] == board[2][0] and board[0][2] != '_'){
        return board[0][2] == 'X'? 1 : -1;   
    }

    return 0;
}

vector<vector<pair<int, float>>> copy_board(const vector<vector<pair<int, float>>>& src) {
    return src; 
}

bool moves_left(vector<vector<char>> board){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == '_'){
                return true;
            }
        }
    }
    return false;
}

int generate_tree(state* s, int depth, bool is_max){
    int score = get_score(s->state_array);

    if(score == 1 || score == -1){
        return score;
    }
    if(moves_left(s->state_array)){
        return 0;
    }

    vector<vector<char>> board = s->state_array;

    if (is_max){
        int best = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == '_'){
                    board[i][j] = 'X';
                    state* child = new state{s, board, score};
                    best = max(best, generate_tree(child, depth + 1, false));
                    // board[i][j] = '_';
                }
            }
        }
        return best;
    }
    else{
        int best = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == '_'){
                    board[i][j] = 'O';
                    state* child = new state{s, board, score};
                    best = min(best, generate_tree(child, depth + 1, true));
                    // board[i][j] = '_';
                }
            }
        }
        return best;
    }
}

int* find_best_move(state* s){
    int best_val = INT_MIN;
    int best_move_x = -1, best_move_y =-1;
    vector<vector<char>> board = s->state_array;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == '_'){
                board[i][j] = 'X';
                state* child = new state{s, board, s->score};
                int move_val = generate_tree(child, 0, false);

                // board[i][j] = '_';
                if (move_val > best_val){
                    best_val = move_val;
                    best_move_x = i; best_move_y = j;
                }
            }
        }
    }
    int* array = new int[2];
    array[0] = best_move_x;
    array[1] = best_move_y;
    return array;
}

void tic_tac_toe(state* s){

    int* best_move = find_best_move(s);
    cout<<"Best move to go is : ";
    cout<<best_move[0]<<" "<<best_move[1];
    cout<<"Enter your move indices : ";
    int x, y;
    cin>>x >>y;

}

int main() {
    vector<vector<char>> board;
    board = {
    {'X', '_', 'X'},
    {'_', '_', '_'},
    {'_', '_', '_'}
    };

    state* s = new state{NULL, board, 0};
    return 0;
}
