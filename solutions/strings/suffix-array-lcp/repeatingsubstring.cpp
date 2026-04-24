// Problem: Repeating Substring
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/2106
// Topic: suffix array, LCP
// Idea: the longest repeated substring is the maximum common prefix of two suffixes.
// Build the suffix array with doubling, compute adjacent LCP values with Kasai,
// and print one substring achieving the maximum LCP.

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

void counting_sort(vector<int>& p, const vector<int>& classes) {
    int n = static_cast<int>(p.size());
    vector<int> cnt(n, 0);
    for (int x : classes) {
        ++cnt[x];
    }

    vector<int> pos(n, 0);
    for (int i = 1; i < n; ++i) {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }

    vector<int> p_new(n);
    for (int x : p) {
        p_new[pos[classes[x]]++] = x;
    }
    p.swap(p_new);
}

vector<int> build_suffix_array(const string& s) {
    string t = s;
    t.push_back('$');
    int n = static_cast<int>(t.size());

    vector<int> p(n), classes(n);
    vector<pair<char, int>> initial(n);
    for (int i = 0; i < n; ++i) {
        initial[i] = {t[i], i};
    }
    sort(initial.begin(), initial.end());
    for (int i = 0; i < n; ++i) {
        p[i] = initial[i].second;
    }

    classes[p[0]] = 0;
    for (int i = 1; i < n; ++i) {
        classes[p[i]] = classes[p[i - 1]];
        if (initial[i].first != initial[i - 1].first) {
            ++classes[p[i]];
        }
    }

    for (int k = 0; (1 << k) < n; ++k) {
        int shift = 1 << k;
        for (int i = 0; i < n; ++i) {
            p[i] = (p[i] - shift + n) % n;
        }
        counting_sort(p, classes);

        vector<int> new_classes(n);
        new_classes[p[0]] = 0;
        for (int i = 1; i < n; ++i) {
            pair<int, int> cur = {classes[p[i]], classes[(p[i] + shift) % n]};
            pair<int, int> prev = {classes[p[i - 1]], classes[(p[i - 1] + shift) % n]};
            new_classes[p[i]] = new_classes[p[i - 1]] + (cur != prev);
        }
        classes.swap(new_classes);
    }

    p.erase(p.begin());
    return p;
}

vector<int> build_lcp(const string& s, const vector<int>& sa) {
    int n = static_cast<int>(s.size());
    if (n == 0) {
        return {};
    }

    vector<int> rank(n);
    for (int i = 0; i < n; ++i) {
        rank[sa[i]] = i;
    }

    vector<int> lcp(max(0, n - 1), 0);
    int matched = 0;
    for (int i = 0; i < n; ++i) {
        if (rank[i] == n - 1) {
            matched = 0;
            continue;
        }

        int j = sa[rank[i] + 1];
        while (i + matched < n && j + matched < n && s[i + matched] == s[j + matched]) {
            ++matched;
        }
        lcp[rank[i]] = matched;
        if (matched > 0) {
            --matched;
        }
    }

    return lcp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<int> sa = build_suffix_array(s);
    vector<int> lcp = build_lcp(s, sa);

    int best_len = 0;
    int best_pos = -1;
    for (int i = 0; i < static_cast<int>(lcp.size()); ++i) {
        if (lcp[i] > best_len) {
            best_len = lcp[i];
            best_pos = sa[i];
        }
    }

    if (best_len == 0) {
        cout << "-1\n";
        return 0;
    }

    cout << s.substr(best_pos, best_len) << '\n';
    return 0;
}
