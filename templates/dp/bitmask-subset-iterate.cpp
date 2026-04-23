// Template: subset iteration and simple bitmask DP skeleton.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 4;
    int full = 1 << n;
    vector<int> dp(full, -1);
    dp[0] = 0;
    for (int mask = 0; mask < full; ++mask) {
        if (dp[mask] == -1) continue;
        for (int bit = 0; bit < n; ++bit) {
            if (mask & (1 << bit)) continue;
            int nmask = mask | (1 << bit);
            dp[nmask] = max(dp[nmask], dp[mask] + bit);
        }
    }
    cout << dp[full - 1] << '\n';
    return 0;
}
