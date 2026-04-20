#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

bool is_safe(int v, vector<vector<int>>& graph, vector<int>& path, int pos, int V) {
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }

    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }

    return true;
}

bool solve_hamitonian(vector<vector<int>>& graph, vector<int>& path, int pos, int V) {
    if (pos == V) {
        return true;
    }

    for (int v = 1; v < V; v++) {
        if (is_safe(v, graph, path, pos, V)) {
            path[pos] = v;

            if (solve_hamitonian(graph, path, pos + 1, V)) {
                return true;
            }

            path[pos] = -1;
        }
    }

    return false;
}

int main() {
    auto start = chrono::high_resolution_clock::now();

    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V, 0));

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> path(V, -1);

    path[0] = 0;

    if (solve_hamitonian(graph, path, 1, V)) {
        cout << "Hamiltonian Path: ";
        for (int i = 0; i < V; i++) {
            cout << path[i] << " ";
        } 
    } else {
        cout << "No Hamiltonian Path exists!";
    }

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "\n\nTotal Execution Time = " << time_taken << setprecision(9) << " sec";
    return 0;
}