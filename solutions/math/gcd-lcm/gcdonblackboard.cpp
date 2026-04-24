// Problem: GCD on Blackboard
// Judge: AtCoder
// Source URL: https://atcoder.jp/contests/abc125/tasks/abc125_c
// Topic: gcd, prefix/suffix aggregates, remove one element
// Idea: after replacing A[i] arbitrarily, the best possible final gcd is the
// gcd of all elements except A[i]. Compute that in O(n) using prefix and suffix
// gcd arrays, then maximize over every removed position.

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }

    vector<int> prefix(n + 1, 0);
    vector<int> suffix(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = gcd(prefix[i], a[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        suffix[i] = gcd(suffix[i + 1], a[i]);
    }

    int answer = 0;
    for (int i = 0; i < n; ++i) {
        answer = max(answer, gcd(prefix[i], suffix[i + 1]));
    }

    cout << answer << '\n';
    return 0;
}
