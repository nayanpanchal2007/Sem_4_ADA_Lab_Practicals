#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int steps = 0;

// Linear Search
int linear_search(const vector<int>& arr, int target) {
    steps = 0;
    for (int i = 0; i < arr.size(); i++) {
        steps++;
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Binary Search
int binary_search(const vector<int>& arr, int target) {
    steps = 0;
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end) {
        steps++;

        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    int n;
    cout << "Enter number of input: ";
    cin >> n;

    vector<int> sizes(n);
    cout << "Enter " << n << " sizes of array: ";
    for (int i = 0; i < n; i++) {
        cin >> sizes[i];
    }

    cout << "\n-------------Best Case-------------\n";
    for (int size : sizes) {
        vector<int> arr(size);
        for (int i = 0; i < size; i++) {
            arr[i] = i + 1;
        }

        linear_search(arr, arr[0]);
        int linear_best = steps;

        binary_search(arr, arr[0]);
        int binary_best = steps;

        cout << size << " -> Linear: " << linear_best << " Binary: " << binary_best << endl;
    }

    cout << "\n-------------Average Case-------------\n";
    for (int size : sizes) {
        vector<int> arr(size);
        for (int i = 0; i < size; i++) {
            arr[i] = i + 1;
        }

        linear_search(arr, arr[(size - 1) / 2]);
        int linear_avg = steps;

        binary_search(arr, arr[(size - 1) / 2]);
        int binary_avg = steps;

        cout << size << " -> Linear: " << linear_avg << " Binary: " << binary_avg << endl;
    }

    cout << "\n-------------Worst Case-------------\n";
    for (int size : sizes) {
        vector<int> arr(size);
        for (int i = 0; i < size; i++) {
            arr[i] = i + 1;
        }

        linear_search(arr, arr[size - 1]);
        int linear_worst = steps;

        binary_search(arr, arr[size - 1]);
        int binary_worst = steps;

        cout << size << " -> Linear: " << linear_worst << " Binary: " << binary_worst << endl;
    }

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "\nTotal Execution Time = " << time_taken << setprecision(9) << " sec";
    return 0;
}