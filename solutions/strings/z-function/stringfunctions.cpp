// Problem: String Functions
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/2107
// Topic: Z-function, prefix function
// Idea: compute the Z array with the current best [l, r) prefix-match interval,
// and compute the prefix-function with standard border fallback links.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> build_z(const string& s) {
    int n = static_cast<int>(s.size());
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

vector<int> build_prefix_function(const string& s) {
    int n = static_cast<int>(s.size());
    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        pi[i] = j;
    }
    return pi;
}

void print_array(const vector<int>& arr) {
    for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
        if (i) {
            cout << ' ';
        }
        cout << arr[i];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<int> z = build_z(s);
    vector<int> pi = build_prefix_function(s);

    print_array(z);
    print_array(pi);
    return 0;
}
