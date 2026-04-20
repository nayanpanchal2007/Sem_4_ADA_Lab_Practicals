#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <limits.h>
using namespace std;

#define MAX 100

int main() {
    auto start = chrono::high_resolution_clock::now();
    
    int n, N;
    int d[MAX];
    int C[MAX][MAX];

    printf("Enter number of denominations: ");
    scanf("%d", &n);

    printf("Enter denominations:\n");
    for(int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
    }

    printf("Enter amount: ");
    scanf("%d", &N);

    for(int i = 1; i <= n; i++) {
        C[i][0] = 0;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= N; j++) {

            if(i == 1 && j < d[i]) {
                C[i][j] = INT_MAX - 1;
            }
            else if(i == 1) {
                C[i][j] = 1 + C[i][j - d[i]];
            }
            else if(j < d[i]) {
                C[i][j] = C[i - 1][j];
            }
            else {
                int exclude = C[i - 1][j];
                int include = 1 + C[i][j - d[i]];
                C[i][j] = (exclude < include) ? exclude : include;
            }
        }
    }

    printf("\nDP Matrix (C):\n\n");
    printf("        ");
    for(int j = 0; j <= N; j++) {
        printf("%4d", j);
    }
    printf("\n");

    printf("        ");
    for(int j = 0; j <= N; j++) {
        printf("----");
    }
    printf("\n");

    for(int i = 1; i <= n; i++) {
        printf("i=%d(%d) |", i, d[i]);
        
        for(int j = 0; j <= N; j++) {
            if(C[i][j] == INT_MAX - 1)
                printf("%4s", "INF");
            else
                printf("%4d", C[i][j]);
        }
        printf("\n");
    }

    printf("\nMinimum coins required = %d\n", C[n][N]);

    printf("Coins used: ");
    int i = n, j = N;

    while(j > 0 && i > 0) {
        if(i > 1 && C[i][j] == C[i - 1][j]) {
            i--;
        } else {
            printf("%d ", d[i]);
            j = j - d[i];
        }
    }

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "\n\nTotal Execution Time = " << time_taken << setprecision(9) << " sec";
    
    return 0;
}