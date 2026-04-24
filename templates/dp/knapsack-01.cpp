// Template: 0/1 knapsack
// Signal: each item can be taken at most once and capacity is the only DP axis.
// Assumes: reverse capacity loop is required so each item is used at most once.
// Exposes: one 1D dp[j] skeleton for maximizing value under capacity.
// Complexity: O(n * capacity).
// Main trap: iterating j upward and silently turning the template into unbounded knapsack.
// Links:
//   Topic: topics/dp/knapsack-family/README.md
//   Note: practice/ladders/dp/knapsack-family/bookshop.md
// dp[j] = best value with capacity limit j

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> weight = {3, 4, 2};
    vector<int> value = {4, 5, 3};
    int capacity = 6;

    vector<int> dp(capacity + 1, 0);
    for (int i = 0; i < static_cast<int>(weight.size()); ++i) {
        for (int j = capacity; j >= weight[i]; --j) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    cout << dp[capacity] << '\n';
    return 0;
}
