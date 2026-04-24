// Template: bitmask subset iterate
// Signal: state is a subset of up to about 20 items, and transitions add one missing bit at a time.
// Assumes: O(n * 2^n) is acceptable and the DP state is subset-closed.
// Exposes: one forward bitmask DP skeleton over dp[mask].
// Complexity: O(n * 2^n).
// Main trap: using it after n grows past the feasible subset frontier.
// Links:
//   Topic: topics/dp/bitmask-dp/README.md
//   Note: practice/ladders/dp/bitmask-dp/vmmarble.md

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
