// Template: interval DP skeleton.

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
