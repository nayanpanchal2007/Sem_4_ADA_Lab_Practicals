#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#define MAX 50

int main() {
    auto start = chrono::high_resolution_clock::now();

    int n, M;
    int w[MAX], v[MAX];
    int V[MAX][MAX];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for(int i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    printf("Enter profits:\n");
    for(int i = 1; i <= n; i++)
        scanf("%d", &v[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &M);

    for(int i = 0; i <= n; i++)
        V[i][0] = 0;

    for(int j = 0; j <= M; j++)
        V[0][j] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= M; j++) {
            if(w[i] <= j) {
                int include = v[i] + V[i-1][j - w[i]];
                int exclude = V[i-1][j];
                V[i][j] = (include > exclude) ? include : exclude;
            } else {
                V[i][j] = V[i-1][j];
            }
        }
    }

    printf("\nKnapsack Table (V):\n\n");

    printf("        ");
    for(int j = 0; j <= M; j++)
        printf("%4d", j);
    printf("\n");

    printf("        ");
    for(int j = 0; j <= M; j++)
        printf("----");
    printf("\n");

    for(int i = 0; i <= n; i++) {
        printf("i=%d   |", i);
        for(int j = 0; j <= M; j++) {
            printf("%4d", V[i][j]);
        }
        printf("\n");
    }

    printf("\nSelected items:\n");

    int i = n, j = M;
    while(i > 0 && j > 0) {
        if(V[i][j] != V[i-1][j]) {
            printf("Item %d (w=%d, v=%d)\n", i, w[i], v[i]);
            j = j - w[i];
        }
        i--;
    }

    printf("\nMaximum Profit = %d\n", V[n][M]);

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "\nTotal Execution Time = " << time_taken << setprecision(9) << " sec";
    return 0;
}