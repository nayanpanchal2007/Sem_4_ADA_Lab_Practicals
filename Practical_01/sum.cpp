#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int loop_count = 0;
int eq_count = 0;
int rec_count = 0;

int sum_loop(int n) {
    if (n <= 0) {
        return 0;
    }

    int sum = 0;
    loop_count++;
    for (int i = 1; i <= n; i++) {
        loop_count++;
        sum += i;
        loop_count++;
    }
    loop_count++;
    return sum;
}

int sum_equation(int n) {
    if (n <= 0) {
        return 0;
    }
    
    int sum = n * (n + 1) / 2;
    eq_count++;
    return sum;
}

int sum_recursion(int n) {
    rec_count++;
    if (n <= 0) {
        return 0;
    }
    return n + sum_recursion(n - 1);
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    int n, result;
    cout << "Enter n: ";
    cin >> n;

    loop_count = 0;
    result = sum_loop(n);

    cout << endl;
    cout << "Using loop     : ";
    cout << "Sum = " << result << ", Steps = " << loop_count << endl;

    eq_count = 0;
    result = sum_equation(n);
    cout << "Using equatio  : ";
    cout << "Sum = " << result << ", Steps = " << eq_count << endl;

    rec_count = 0;
    result = sum_recursion(n);
    cout << "Using recursion: ";
    cout << "Sum = " << result << ", Steps = " << rec_count << endl;

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "\nTotal Execution Time = " << time_taken << setprecision(9) << " sec";
    return 0;
}