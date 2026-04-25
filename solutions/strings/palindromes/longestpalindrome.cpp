// Problem: Longest Palindrome
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1111
// Topic: Manacher, odd/even centers, longest palindromic substring
// Idea: compute odd and even palindrome radii in linear time, then recover the
// longest substring from the best radius.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> manacher_odd(const string& s) {
    int n = static_cast<int>(s.size());
    vector<int> d1(n, 0);
    int l = 0, r = -1;
    for (int i = 0; i < n; ++i) {
        int k = 1;
        if (i <= r) {
            int mirror = l + r - i;
            k = min(d1[mirror], r - i + 1);
        }
        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
            ++k;
        }
        d1[i] = k;
        if (i + k - 1 > r) {
            l = i - k + 1;
            r = i + k - 1;
        }
    }
    return d1;
}

vector<int> manacher_even(const string& s) {
    int n = static_cast<int>(s.size());
    vector<int> d2(n, 0);
    int l = 0, r = -1;
    for (int i = 0; i < n; ++i) {
        int k = 0;
        if (i <= r) {
            int mirror = l + r - i + 1;
            k = min(d2[mirror], r - i + 1);
        }
        while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) {
            ++k;
        }
        d2[i] = k;
        if (i + k - 1 > r) {
            l = i - k;
            r = i + k - 1;
        }
    }
    return d2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<int> d1 = manacher_odd(s);
    vector<int> d2 = manacher_even(s);

    int best_l = 0;
    int best_len = 1;

    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        int odd_len = 2 * d1[i] - 1;
        int odd_l = i - d1[i] + 1;
        if (odd_len > best_len) {
            best_len = odd_len;
            best_l = odd_l;
        }

        int even_len = 2 * d2[i];
        int even_l = i - d2[i];
        if (even_len > best_len) {
            best_len = even_len;
            best_l = even_l;
        }
    }

    cout << s.substr(best_l, best_len) << '\n';
    return 0;
}
