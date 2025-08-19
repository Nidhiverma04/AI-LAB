#ifndef PUZZLE_UTILS_H
#define PUZZLE_UTILS_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct state {
    state* parent;
    vector<vector<int>> state_array;
    int state_no;
};

extern int row_moves[4];
extern int col_moves[4];

bool isValid(int x, int y, int n);
bool is_goal(const vector<vector<int>>& goal, const vector<vector<int>>& state);
void print_path(state* s, int n, int& count);
vector<vector<int>> copy_board(const vector<vector<int>>& src);
bool is_visited(const vector<vector<vector<int>>>& visited,
                const vector<vector<int>>& board);
int displaced_count(state* s, int n);

#endif
