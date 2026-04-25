// Problem: Knuth Division
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/2088/
// Topic: interval DP, Knuth optimization, prefix sums
// Idea: dp[l][r] = min(dp[l][k] + dp[k+1][r] + sum(l, r)). The extra interval
// cost does not depend on the split point, so after prefix sums we can apply
// Knuth optimization and search k only in [opt[l][r-1], opt[l+1][r]].

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

constexpr long long INF64 = numeric_limits<long long>::max() / 4;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (long long& x : a) {
        cin >> x;
    }

    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    auto cost = [&](int l, int r) -> long long {
        return pref[r + 1] - pref[l];
    };

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

    cout << dp[0][n - 1] << '\n';
    return 0;
}
