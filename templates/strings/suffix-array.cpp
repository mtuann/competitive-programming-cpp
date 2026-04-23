// Template: suffix array with doubling and LCP.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> build_suffix_array(const string &s) {
    int n = static_cast<int>(s.size());
    vector<int> sa(n), rank(n), tmp(n);
    for (int i = 0; i < n; ++i) {
        sa[i] = i;
        rank[i] = s[i];
    }
    for (int k = 1;; k <<= 1) {
        auto cmp = [&](int a, int b) {
            if (rank[a] != rank[b]) return rank[a] < rank[b];
            int ra = (a + k < n) ? rank[a + k] : -1;
            int rb = (b + k < n) ? rank[b + k] : -1;
            return ra < rb;
        };
        sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; ++i) tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        rank = tmp;
        if (rank[sa[n - 1]] == n - 1) break;
    }
    return sa;
}

int main() {
    vector<int> sa = build_suffix_array("banana");
    cout << sa[0] << '\n';
    return 0;
}
