#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <string.h>
using namespace std;

#define MAX 50

char X[MAX], Y[MAX];
int C[MAX][MAX];
char B[MAX][MAX];

void printLCS(int i, int j) {
    if(i == 0 || j == 0)
        return;

    if(B[i][j] == 'D') {
        printLCS(i-1, j-1);
        printf("%c", X[i-1]);
    }
    else if(B[i][j] == 'U') {
        printLCS(i-1, j);
    }
    else {
        printLCS(i, j-1);
    }
}

int main() {
    auto start = chrono::high_resolution_clock::now();

    int m, n;

    printf("Enter string X: ");
    scanf("%s", X);

    printf("Enter string Y: ");
    scanf("%s", Y);

    m = strlen(X);
    n = strlen(Y);

    for(int i = 0; i <= m; i++)
        C[i][0] = 0;

    for(int j = 0; j <= n; j++)
        C[0][j] = 0;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(X[i-1] == Y[j-1]) {
                C[i][j] = C[i-1][j-1] + 1;
                B[i][j] = 'D';
            }
            else if(C[i-1][j] >= C[i][j-1]) {
                C[i][j] = C[i-1][j];
                B[i][j] = 'U';
            }
            else {
                C[i][j] = C[i][j-1];
                B[i][j] = 'L';
            }
        }
    }

    printf("\nLCS Length Table (C):\n\n");

    printf("      ");
    for(int j = 0; j <= n; j++)
        printf("%4c", j==0 ? '-' : Y[j-1]);
    printf("\n");

    for(int i = 0; i <= m; i++) {
        printf("%4c ", i==0 ? '-' : X[i-1]);
        for(int j = 0; j <= n; j++) {
            printf("%4d", C[i][j]);
        }
        printf("\n");
    }

    printf("\nDirection Table (B):\n\n");

    printf("      ");
    for(int j = 0; j <= n; j++)
        printf("%4c", j==0 ? '-' : Y[j-1]);
    printf("\n");

    for(int i = 0; i <= m; i++) {
        printf("%4c ", i==0 ? '-' : X[i-1]);
        for(int j = 0; j <= n; j++) {
            if(i==0 || j==0)
                printf("%4c", '-');
            else
                printf("%4c", B[i][j]);
        }
        printf("\n");
    }

    printf("\nLength of LCS = %d\n", C[m][n]);

    printf("LCS = ");
    printLCS(m, n);

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "\n\nTotal Execution Time = " << time_taken << setprecision(9) << " sec";
    
    return 0;
}