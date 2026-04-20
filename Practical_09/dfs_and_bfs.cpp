#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

void DFS(int start, vector<vector<int>> &adj, vector<bool> &visited) {
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int node = s.top();
        s.pop();
        cout << node << " ";

        for (int i = adj[node].size() - 1; i >= 0; i--) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
}

void BFS(int start, vector<vector<int>> &adj, vector<bool> &visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    auto st = chrono::high_resolution_clock::now();

    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<int>> adj(vertices);

    cout << "Enter edges in format: u v (0-based indexing)\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter starting node for traversal: ";
    cin >> start;

    vector<bool> visited(vertices, false);
    cout << "DFS Traversal: ";
    DFS(start, adj, visited);

    fill(visited.begin(), visited.end(), false);

    cout << "\nBFS Traversal: ";
    BFS(start, adj, visited);

    auto en = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(en - st).count();
    time_taken *= 1e-9;

    cout << "\n\nTotal Execution Time = " << time_taken << setprecision(9) << " sec";
    return 0;
}