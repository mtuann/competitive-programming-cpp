// Problem: String Matching
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1753
// Topic: KMP, prefix function, exact pattern matching
// Idea: build the prefix-function of the pattern, then scan the text while
// following border links on mismatch. After a full match, continue from
// pi[m - 1] so overlapping matches are counted too.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> build_prefix_function(const string& pattern) {
    int m = static_cast<int>(pattern.size());
    vector<int> pi(m, 0);
    for (int i = 1; i < m; ++i) {
        int j = pi[i - 1];
        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            ++j;
        }
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text, pattern;
    cin >> text >> pattern;

    vector<int> pi = build_prefix_function(pattern);
    int m = static_cast<int>(pattern.size());
    int j = 0;
    long long matches = 0;

    for (char ch : text) {
        while (j > 0 && ch != pattern[j]) {
            j = pi[j - 1];
        }
        if (ch == pattern[j]) {
            ++j;
        }
        if (j == m) {
            ++matches;
            j = pi[m - 1];
        }
    }

    cout << matches << '\n';
    return 0;
}
