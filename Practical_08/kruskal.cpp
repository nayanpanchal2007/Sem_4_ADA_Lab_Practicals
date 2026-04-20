#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

class DisjointSet {
    vector<int> parent;

public:
    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = -1;
    }

    int find(int i) {
        if (parent[i] == -1)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);
        if (s1 != s2)
            parent[s1] = s2;
    }
};

int main() {
    auto start = chrono::high_resolution_clock::now();
    
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter edges in format: src dest weight (0-indexed vertices)\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    sort(edges.begin(), edges.end(), compare);

    DisjointSet ds(V);

    vector<Edge> mst;
    int totalWeight = 0;

    for (auto edge : edges) {
        int x = ds.find(edge.src);
        int y = ds.find(edge.dest);

        if (x != y) {
            mst.push_back(edge);
            totalWeight += edge.weight;
            ds.unite(x, y);
        }
    }

    cout << "\nEdges in MST:\n";
    for (auto edge : mst) {
        cout << edge.src << " - " << edge.dest << " = " << edge.weight << endl;
    }

    cout << "Total weight of MST: " << totalWeight << endl;

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "\nTotal Execution Time = " << time_taken << setprecision(9) << " sec";
    return 0;
}