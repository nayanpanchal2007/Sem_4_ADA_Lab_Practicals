#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

bool is_safe(vector<vector<int>>& board, int row, int col, int n) {
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

void solve(vector<vector<int>>& board, int col, int n) {
    if (col == n) {
        cout << "\nSolution\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (is_safe(board, i, col, n)) {
            board[i][col] = 1;
            solve(board, col + 1, n);
            board[i][col] = 0;
        }
    }
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    
    int n;
    cout << "Enter number of Queens (n): ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));
    
    solve(board, 0, n);

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "\nTotal Execution Time = " << time_taken << setprecision(9) << " sec";

    return 0;
}