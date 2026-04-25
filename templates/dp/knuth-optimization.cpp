// Template: Knuth optimization for split-point interval DP
// Signal: dp[l][r] = min_{l <= k < r}(dp[l][k] + dp[k+1][r] + cost(l, r))
// with opt[l][r-1] <= opt[l][r] <= opt[l+1][r].
// Assumes: cost(l, r) is O(1), independent of the chosen split k, and the
// caller has already proved or imported the Knuth monotonicity conditions.
// Exposes: knuth_optimize_interval_dp(n, cost) returning dp and opt tables for
// 0-indexed inclusive intervals.
// Complexity: O(n^2) after cost preprocessing.
// Main trap: using it for partition-row DP, or when the extra cost still
// depends on k.
// Links:
//   Topic: topics/dp/knuth-optimization/README.md
//   Note: practice/ladders/dp/knuth-optimization/knuthdivision.md

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

constexpr long long INF64 = numeric_limits<long long>::max() / 4;

struct KnuthResult {
    vector<vector<long long>> dp;
    vector<vector<int>> opt;
};

template <class Cost>
KnuthResult knuth_optimize_interval_dp(int n, const Cost& cost) {
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    vector<vector<int>> opt(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        opt[i][i] = i;
    }

    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = l + len - 1;
            dp[l][r] = INF64;
            int start = opt[l][r - 1];
            int end = min(r - 1, opt[l + 1][r]);
            long long extra = cost(l, r);
            for (int k = start; k <= end; ++k) {
                long long cand = dp[l][k] + dp[k + 1][r] + extra;
                if (cand <= dp[l][r]) {
                    dp[l][r] = cand;
                    opt[l][r] = k;
                }
            }
        }
    }

    return {dp, opt};
}

int main() {
    vector<long long> a = {2, 7, 3, 2, 5};
    int n = static_cast<int>(a.size());
    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    auto cost = [&](int l, int r) -> long long {
        return pref[r + 1] - pref[l];
    };

    KnuthResult result = knuth_optimize_interval_dp(n, cost);
    cout << result.dp[0][n - 1] << '\n';
    return 0;
}
