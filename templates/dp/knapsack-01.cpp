// Template: 0/1 knapsack
// dp[j] = best value with capacity j

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
