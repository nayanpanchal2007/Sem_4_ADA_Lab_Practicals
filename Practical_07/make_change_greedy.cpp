#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#define MAX 50

void sort(int d[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(d[j] < d[j+1]) {
                int temp = d[j];
                d[j] = d[j+1];
                d[j+1] = temp;
            }
        }
    }
}

int main() {
    auto start = chrono::high_resolution_clock::now();

    int n, N;
    int d[MAX], count[MAX] = {0};

    printf("Enter number of denominations: ");
    scanf("%d", &n);

    printf("Enter denominations:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }

    printf("Enter amount: ");
    scanf("%d", &N);
    sort(d, n);

    int remaining = N;

    for(int i = 0; i < n; i++) {
        while(remaining >= d[i]) {
            remaining -= d[i];
            count[i]++;
        }
    }

    printf("\nCoins used:\n");
    int totalCoins = 0;

    for(int i = 0; i < n; i++) {
        if(count[i] > 0) {
            printf("Denomination %d --> %d coins\n", d[i], count[i]);
            totalCoins += count[i];
        }
    }

    printf("\nMinimum coins (Greedy) = %d\n", totalCoins);

    if(remaining != 0) {
        printf("Exact change not possible with given denominations.\n");
    }

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "\nTotal Execution Time = " << time_taken << setprecision(9) << " sec";

    return 0;
}