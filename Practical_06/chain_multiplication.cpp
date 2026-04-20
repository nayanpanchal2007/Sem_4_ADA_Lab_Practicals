#include <iostream>
#include <bits/stdc++.h>
#include <limits.h>
#include <chrono>
using namespace std;

#define MAX 10

int main() {
    auto start = chrono::high_resolution_clock::now();

    int n, p[MAX];
    int m[MAX][MAX], s[MAX][MAX];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions array (p0 to p%d):\n", n);
    for(int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    for(int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for(int l = 2; l <= n; l++) {
        for(int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for(int k = i; k < j; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

                if(q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("\nMatrix m (Minimum Cost):\n\n");

    printf("      ");
    for(int j = 1; j <= n; j++)
        printf("%6d", j);
    printf("\n");

    for(int i = 1; i <= n; i++) {
        printf("%6d", i);
        for(int j = 1; j <= n; j++) {
            if(i > j)
                printf("%6s", "-");
            else
                printf("%6d", m[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix s (Split Positions):\n\n");

    printf("      ");
    for(int j = 1; j <= n; j++)
        printf("%6d", j);
    printf("\n");

    for(int i = 1; i <= n; i++) {
        printf("%6d", i);
        for(int j = 1; j <= n; j++) {
            if(i >= j)
                printf("%6s", "-");
            else
                printf("%6d", s[i][j]);
        }
        printf("\n");
    }

    printf("\nMinimum number of multiplications = %d\n", m[1][n]);

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "\nTotal Execution Time = " << time_taken << setprecision(9) << " sec";
    return 0;
}