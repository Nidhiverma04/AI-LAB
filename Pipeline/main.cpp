#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Declare solver functions from other files
void runDFS(const vector<vector<int>>& puzzle, int n);
void runBFS(const vector<vector<int>>& puzzle, int n);
void runHeuristic(const vector<vector<int>>& puzzle, int n);
void runHillClimbing(const vector<vector<int>>& puzzle, int n);

int main() {
    int n;
    cout << "Enter puzzle size: ";
    cin >> n;

    vector<vector<int>> puzzle(n, vector<int>(n));
    cout << "Enter puzzle elements (row by row, use 0 for blank):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> puzzle[i][j];
        }
    }

    // Run DFS
    auto start = high_resolution_clock::now();
    runDFS(puzzle, n);
    auto stop = high_resolution_clock::now();
    cout << "DFS Time: " 
         << duration_cast<milliseconds>(stop - start).count() 
         << " ms\n\n";

    // Run BFS
    start = high_resolution_clock::now();
    runBFS(puzzle, n);
    stop = high_resolution_clock::now();
    cout << "BFS Time: " 
         << duration_cast<milliseconds>(stop - start).count() 
         << " ms\n\n";

    // Run Heuristic Search
    start = high_resolution_clock::now();
    runHeuristic(puzzle, n);
    stop = high_resolution_clock::now();
    cout << "Heuristic Time: " 
         << duration_cast<milliseconds>(stop - start).count() 
         << " ms\n\n";

    // Run Hill Climbing
    start = high_resolution_clock::now();
    runHillClimbing(puzzle, n);
    stop = high_resolution_clock::now();
    cout << "Hill Climbing Time: " 
         << duration_cast<milliseconds>(stop - start).count() 
         << " ms\n\n";

     cout << "DFS Time: " 
     << duration_cast<milliseconds>(stop - start).count() 
     << " ms\n\n";

     cout << "BFS Time: " 
     << duration_cast<milliseconds>(stop - start).count() 
     << " ms\n\n";

    cout << "Heuristic Time: " 
     << duration_cast<milliseconds>(stop - start).count() 
     << " ms\n\n";

    return 0;
}
