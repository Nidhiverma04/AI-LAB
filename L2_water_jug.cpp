#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;

int capacity1; // x-liter jug
int capacity2; // y-liter jug
int target;    // Target water
int targetJug; // Jug number (1 or 2)

set<pair<int, int>> visited;
vector<pair<int, int>> path; 

bool dfs(int jug1, int jug2) {
    if (visited.count({jug1, jug2}))
        return false;

    visited.insert({jug1, jug2});
    path.push_back({jug1, jug2});

    // Check target condition
    if ((targetJug == 1 && jug1 == target) || 
        (targetJug == 2 && jug2 == target))
        return true;

    // Fill jug1
    if (dfs(capacity1, jug2)) return true;

    // Fill jug2
    if (dfs(jug1, capacity2)) return true;

    // Empty jug1
    if (dfs(0, jug2)) return true;

    // Empty jug2
    if (dfs(jug1, 0)) return true;

    // Pour jug1 -> jug2
    int pour1to2 = min(jug1, capacity2 - jug2);
    if (dfs(jug1 - pour1to2, jug2 + pour1to2)) return true;

    // Pour jug2 -> jug1
    int pour2to1 = min(jug2, capacity1 - jug1);
    if (dfs(jug1 + pour2to1, jug2 - pour2to1)) return true;

    // Backtrack
    path.pop_back();
    return false;
}

int main() {
    cout << "Enter capacity of jug X: ";
    cin >> capacity1;
    cout << "Enter capacity of jug Y: ";
    cin >> capacity2;
    cout << "Enter target amount of water: ";
    cin >> target;
    cout << "In which jug do you want the target (1 for X, 2 for Y)? ";
    cin >> targetJug;

    if (dfs(0, 0)) {
        cout << "\nSolution steps:\n";
        for (auto state : path) {
            cout << "(" << state.first << ", " << state.second << ")\n";
        }
    } else {
        cout << "No solution found.\n";
    }
    return 0;
}
