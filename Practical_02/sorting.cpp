#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <chrono>
using namespace std;

// Bubble sort
long long bubble_sort_steps(vector<int> arr) {
    long long steps = 0;
    int n = arr.size(); steps++;

    for (int i = 0; i < n - 1; i++) {
        steps++;
        for (int j = 0; j < n - i - 1; j++) {
            steps++;
            steps++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                steps += 3;
            }
        }
    }
    return steps;
}

// Selection sort
long long selection_sort_steps(vector<int> arr) {
    long long steps = 0;
    int n = arr.size(); steps++;

    for (int i = 0; i < n - 1; i++) {
        steps++;
        int minIndex = i; steps++;

        for (int j = i + 1; j < n; j++) {
            steps++;
            steps++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j; steps++;
            }
        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            steps += 3;
        }
    }
    return steps;
}

// Insertion sort
long long insertions_sort_steps(vector<int> arr) {
    long long steps = 0;
    int n = arr.size(); steps++;

    for (int i = 1; i < n; i++) {
        steps++;
        int key = arr[i]; steps++;
        int j = i - 1; steps++;

        while (j >= 0 && arr[j] > key) {
            steps += 2;
            arr[j + 1] = arr[j]; steps++;
            j--; steps++;
        }
        arr[j + 1] = key; steps++;
    }
    return steps;
}

// Merge process
long long merge_process(vector<int>& arr, int l, int m, int r) {
    long long steps = 0;
    int n1 = m - l + 1; steps++;
    int n2 = r - m; steps++;

    vector<int> L(n1), R(n2); steps += 2;

    for (int i = 0; i < n1; i++) { L[i] = arr[l + i]; steps++; }
    for (int j = 0; j < n2; j++) { R[j] = arr[m + 1 + j]; steps++; }

    int i = 0, j = 0, k = l; steps += 3;

    while (i < n1 && j < n2) {
        steps += 2;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++]; steps += 2;
        } else {
            arr[k++] = R[j++]; steps += 2;
        }
    }

    while (i < n1) { arr[k++] = L[i++]; steps += 2; }
    while (j < n2) { arr[k++] = R[j++]; steps += 2; }

    return steps;
}

long long merge_sort_helper(vector<int>& arr, int l, int r) {
    long long steps = 0;
    if (l < r) {
        steps++;
        int m = (l + r) / 2; steps++;

        steps += merge_sort_helper(arr, l, m);
        steps += merge_sort_helper(arr, m + 1, r);
        steps += merge_process(arr, l, m, r);
    }
    return steps;
}

long long merge_sort_steps(vector<int> arr) {
    return merge_sort_helper(arr, 0, arr.size() - 1);
}

// Quick sort
long long quickSortHelper(vector<int>& arr, int low, int high) {
    long long steps = 0;
    if (low < high) {
        steps++;
        int pivot = arr[low]; steps++;
        int i = low + 1, j = high; steps += 2;

        while (true) {
            while (i <= high && arr[i] <= pivot) { i++; steps += 2; }
            while (j >= low && arr[j] > pivot) { j--; steps += 2; }

            if (i < j) {
                swap(arr[i], arr[j]);
                steps += 3;
            } else break;
        }

        swap(arr[low], arr[j]);
        steps += 3;

        steps += quickSortHelper(arr, low, j - 1);
        steps += quickSortHelper(arr, j + 1, high);
    }
    return steps;
}

long long quick_sort_steps(vector<int> arr) {
    return quickSortHelper(arr, 0, arr.size() - 1);
}

// Print array
void print_array(vector<int> arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

// Main
int main() {
    auto start = chrono::high_resolution_clock::now();

    srand(time(0));
    vector<int> arr;
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        arr.push_back(rand() % 100 + 1);
    }

    int choice;
    cout << "1. Random data\n2. Reversed data\n3. Sorted data\n";
    cout << "Enter a choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            break;
        case 2:
            reverse(arr.begin(), arr.end());
            break;
        case 3:
            sort(arr.begin(), arr.end());
            break;
        default:
            cout << "Please choose from the list.\n";
            break;
    }

    cout << endl;
    cout << "Bubble Sort Steps: " << bubble_sort_steps(arr) << endl;
    cout << "Selection Sort Steps: " << selection_sort_steps(arr) << endl;
    cout << "Insertion Sort Steps: " << insertions_sort_steps(arr) << endl;
    cout << "Merge Sort Steps: " << merge_sort_steps(arr) << endl;
    cout << "Quick Sort Steps: " << quick_sort_steps(arr) << endl;
    
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "\nTotal Exeucution Time: " << time_taken << setprecision(9) << " sec";
    return 0;
}