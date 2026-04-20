#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#define MAX 50

typedef struct {
    int weight;
    int profit;
    float ratio;
} Item;

void sort(Item items[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(items[j].ratio < items[j+1].ratio) {
                Item temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    
    int n, capacity;
    Item items[MAX];

    printf("Enter number of items: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter weight and profit of item %d: ", i+1);
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    sort(items, n);

    float totalProfit = 0.0;
    int currentWeight = 0;

    printf("\nSelected items (with fractions):\n");

    for(int i = 0; i < n; i++) {
        if(currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalProfit += items[i].profit;

            printf("Item %d: weight=%d, profit=%d, fraction=1.0\n",
                   i+1, items[i].weight, items[i].profit);
        }
        else {
            int remain = capacity - currentWeight;
            float fraction = (float)remain / items[i].weight;

            totalProfit += items[i].profit * fraction;

            printf("Item %d: weight=%d, profit=%d, fraction=%.2f\n",
                   i+1, items[i].weight, items[i].profit, fraction);

            break;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "\nTotal Execution Time = " << time_taken << setprecision(9) << " sec";
    return 0;
}