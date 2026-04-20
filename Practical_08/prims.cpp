#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <climits>
using namespace std;

int main() {
    auto start = chrono::high_resolution_clock::now();
    
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> cost(V, vector<int>(V, INT_MAX));

    cout << "Enter edges in format: src dest weight\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        cost[u][v] = w;
        cost[v][u] = w;
    }

    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);  
    vector<bool> inMST(V, false);

    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;

        for (int i = 0; i < V; i++) {
            if (!inMST[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }

        inMST[u] = true;

        for (int v = 0; v < V; v++) {
            if (cost[u][v] != INT_MAX && !inMST[v] && cost[u][v] < key[v]) {
                key[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "\nEdges in MST:\n";
    int totalWeight = 0;

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " = " << cost[i][parent[i]] << endl;
        totalWeight += cost[i][parent[i]];
    }

    cout << "Total weight of MST: " << totalWeight << endl;

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "\nTotal Execution Time = " << time_taken << setprecision(9) << " sec";
    return 0;
}