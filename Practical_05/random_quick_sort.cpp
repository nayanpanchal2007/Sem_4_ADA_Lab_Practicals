#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <chrono>
using namespace std;

long long basic_steps = 0;
long long random_steps = 0;

/* ------------------- SWAP FUNCTION ------------------- */
void swap_values(int arr[], int i, int j) {
    if (i != j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/* ------------------- BASIC QUICK SORT ------------------- */
int basic_partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap_values(arr, i, j);
            basic_steps += 3;
        }
    }

    i++;
    swap_values(arr, i, high);
    basic_steps += 3;

    return i;
}

void basic_quick_sort_helper(int arr[], int low, int high) {
    if (low < high) {
        basic_steps++;
        int pivot_index = basic_partition(arr, low, high);
        basic_quick_sort_helper(arr, low, pivot_index - 1);
        basic_quick_sort_helper(arr, pivot_index + 1, high);
    }
}

void basic_quick_sort(int arr[], int n) {
    basic_steps = 0;
    basic_quick_sort_helper(arr, 0, n - 1);
}

/* ------------------- RANDOMIZED QUICK SORT ------------------- */

int randomized_partition(int arr[], int low, int high) {
    int random_index = low + rand() % (high - low + 1);
    swap_values(arr, random_index, high);
    random_steps++;

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap_values(arr, i, j);
            random_steps += 3;
        }
    }

    i++;
    swap_values(arr, i, high);
    random_steps += 3;

    return i;
}

void randomized_quick_sort_helper(int arr[], int low, int high) {
    if (low < high) {
        random_steps++;
        int pivot_index = randomized_partition(arr, low, high);
        randomized_quick_sort_helper(arr, low, pivot_index - 1);
        randomized_quick_sort_helper(arr, pivot_index + 1, high);
    }
}

void randomized_quick_sort(int arr[], int n) {
    random_steps = 0;
    randomized_quick_sort_helper(arr, 0, n - 1);
}

/* ------------------- ARRAY GENERATORS ------------------- */

int* generate_random_array(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = rand() % n;
    return arr;
}

int* generate_ascending_array(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = i;
    return arr;
}

int* generate_descending_array(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = n - i;
    return arr;
}

/* ------------------- MAIN ------------------- */

int main() {
    auto start = chrono::high_resolution_clock::now();

    srand(time(NULL));

    int n;
    cout << "Enter number of inputs: ";
    cin >> n;

    int sizes[n];
    cout << "Enter sizes of array: ";
    for (int i = 0; i < n; i++) {
        cin >> sizes[i];
    }

    string input_types[] = {"Random Data", "Ascending Data", "Descending Data"};

    for (int t = 0; t < 3; t++) {

        cout << "\n========================================================\n";
        cout << "                " << input_types[t] << "\n";
        cout << "========================================================\n";
        cout << "Input Size      Basic Quick Steps      Random Quick Steps\n";
        cout << "--------------------------------------------------------\n";

        for (int i = 0; i < n; i++) {

            int size = sizes[i];

            int* original;
            if (t == 1)
                original = generate_ascending_array(size);
            else if (t == 2)
                original = generate_descending_array(size);
            else
                original = generate_random_array(size);

            int* arr1 = new int[size];
            int* arr2 = new int[size];

            for (int j = 0; j < size; j++) {
                arr1[j] = original[j];
                arr2[j] = original[j];
            }

            basic_quick_sort(arr1, size);
            randomized_quick_sort(arr2, size);

            printf("%-16d%-23lld%-18lld\n", size, basic_steps, random_steps);

            delete[] original;
            delete[] arr1;
            delete[] arr2;
        }
    }

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "\nTotal Execution Time = " << time_taken << setprecision(9) << " sec";

    return 0;
}