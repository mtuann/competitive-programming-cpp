// Template: interval DP skeleton
// Signal: split-point interval DP over contiguous intervals [l, r].
// Assumes: transitions depend only on smaller intervals and len-order iteration is valid.
// Exposes: one len / l / r / k interval-DP skeleton over dp[l][r].
// Complexity: O(n^3) in this split-point form.
// Main trap: forcing interval DP when the real dependency graph is not interval-shaped.
// Links:
//   Topic: topics/dp/interval-dp/README.md
//   Note: practice/ladders/dp/interval-dp/removalgame.md

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main() {
    vector<int> a = {4, 1, 3, 2};
    int n = static_cast<int>(a.size());
    const long long INF = numeric_limits<long long>::max() / 4;
    vector<vector<long long>> dp(n, vector<long long>(n, INF));
    for (int i = 0; i < n; ++i) dp[i][i] = 0;
    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = l + len - 1;
            for (int k = l; k < r; ++k) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + (r - l + 1));
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
    return 0;
}
