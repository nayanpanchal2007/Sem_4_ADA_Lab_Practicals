#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#define ll unsigned long long

ll steps_rec = 0;
ll steps_iter = 0;

ll fibonacci_rec(ll n) {
    steps_rec++;
    if (n == 0 || n == 1)
        return n;

    return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
}

ll fibonacci_iter(ll n) {
    steps_iter++;

    if (n == 0 || n == 1)
        return n;

    ll f0 = 0, f1 = 1, fn;

    for (ll i = 2; i <= n; i++) {
        steps_iter++;
        fn = f0 + f1;
        f0 = f1;
        f1 = fn;
    }
    return f1;
}

int main() {
    auto start = chrono::high_resolution_clock::now();

    cout << "Welcome to Fibonacci numbers\n";

    ll n;
    cout << "Enter n: ";
    cin >> n;

    ll iter_result = fibonacci_iter(n);
    ll rec_result = fibonacci_rec(n);

    cout << "Iterative Fibonacci(" << n << "): "
         << iter_result << " | Steps: "
         << steps_iter << endl;

    cout << "Recursive Fibonacci(" << n << "): "
         << rec_result << " | Steps: "
         << steps_rec << endl;

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "\nTotal Execution Time = " << time_taken << setprecision(9) << " sec";
    return 0;
}