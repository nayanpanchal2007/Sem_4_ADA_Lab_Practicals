#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

bool is_safe(int node, vector<vector<int>>& graph, vector<int>& color, int c, int v) {
    for (int i = 0; i < v; i++) {
        if (graph[node][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

void solve(int node, vector<vector<int>>& graph, int m, int v, vector<int>& color) {
    if (node == v) {
        cout << "Coloring: ";
        for (int i = 0; i < v; i++) {
            cout << color[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int c = 1; c <= m; c++) {
        if (is_safe(node, graph, color, c, v)) {
            color[node] = c;
            solve(node + 1, graph, m, v, color);
            color[node] = 0;
        }
    }
}

int main() {
    auto start = chrono::high_resolution_clock::now();

    int v, m;
    cout << "Enter number of vertices: ";
    cin >> v;

    vector<vector<int>> graph(v, vector<int>(v));

    cout << "Enter adjacent matrix:\n";
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter number of colors: ";
    cin >> m;

    vector<int> color(v, 0);

    solve(0, graph, m, v, color);

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "\nTotal Execution Time = " << time_taken << setprecision(9) << " sec";
    return 0;
}