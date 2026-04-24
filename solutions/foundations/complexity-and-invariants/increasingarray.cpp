// Problem: Increasing Array
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1094
// Topic: greedy scan, loop invariant, running maximum
// Idea: after repairing a prefix optimally, the next value must be at least the
// repaired previous value, so the cheapest legal repair is max(current, need).

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long moves = 0;
    long long need = 0;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;

        if (i == 0) {
            need = x;
            continue;
        }

        if (x < need) {
            moves += need - x;
        } else {
            need = x;
        }
    }

    cout << moves << '\n';
    return 0;
}
