// Problem: Finding Periods
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1733
// Topic: Z-function, string periodicity
// Idea: a length p is a valid period iff the suffix s[p..n) matches the prefix
// s[0..n-p), which is exactly z[p] == n - p. The last repetition may be partial.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> build_z(const string& s) {
    const int n = static_cast<int>(s.size());
    vector<int> z(n, 0);
    int l = 0;
    int r = 0;

    for (int i = 1; i < n; ++i) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }

    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    const int n = static_cast<int>(s.size());
    const vector<int> z = build_z(s);

    bool first = true;
    for (int p = 1; p < n; ++p) {
        if (p + z[p] == n) {
            if (!first) {
                cout << ' ';
            }
            cout << p;
            first = false;
        }
    }

    if (!first) {
        cout << ' ';
    }
    cout << n << '\n';

    return 0;
}
