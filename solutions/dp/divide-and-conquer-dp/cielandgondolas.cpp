// Problem: Ciel and Gondolas
// Judge: Codeforces
// Source URL: https://codeforces.com/problemset/problem/321/E
// Topic: partition DP, divide and conquer DP, 2D prefix sums
// Idea: dp[g][i] = min_{k < i}(dp[g-1][k] + cost(k+1, i)), where cost(l, r)
// is the pairwise discomfort inside one contiguous group. Precompute cost(l, r)
// in O(1) with a 2D prefix sum, then compute each DP row in O(n log n) using
// monotone-opt divide-and-conquer optimization.

#include <algorithm>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

using namespace std;

constexpr long long INF64 = numeric_limits<long long>::max() / 4;

template <class Cost>
void compute_dnc_row(int left, int right, int opt_left, int opt_right,
                     const vector<long long>& prev, vector<long long>& cur,
                     const Cost& cost) {
    if (left > right) {
        return;
    }

    int mid = (left + right) >> 1;
    pair<long long, int> best = {INF64, -1};
    int upper = min(mid - 1, opt_right);

    for (int k = opt_left; k <= upper; ++k) {
        long long cand = prev[k] + cost(k + 1, mid);
        if (cand < best.first) {
            best = {cand, k};
        }
    }

    cur[mid] = best.first;
    compute_dnc_row(left, mid - 1, opt_left, best.second, prev, cur, cost);
    compute_dnc_row(mid + 1, right, best.second, opt_right, prev, cur, cost);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, groups;
    cin >> n >> groups;

    vector<vector<long long>> pref(n + 1, vector<long long>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            long long x;
            cin >> x;
            pref[i][j] = x + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }

    auto cost = [&](int l, int r) -> long long {
        long long twice = pref[r][r] - pref[l - 1][r] - pref[r][l - 1] + pref[l - 1][l - 1];
        return twice / 2;
    };

    vector<long long> prev(n + 1, INF64), cur(n + 1, INF64);
    prev[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prev[i] = cost(1, i);
    }

    for (int g = 2; g <= groups; ++g) {
        fill(cur.begin(), cur.end(), INF64);
        compute_dnc_row(g, n, g - 1, n - 1, prev, cur, cost);
        swap(prev, cur);
    }

    cout << prev[n] << '\n';
    return 0;
}
