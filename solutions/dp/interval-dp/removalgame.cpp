#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    vector<long long> values(n);
    long long total_sum = 0;
    for (long long &value : values) {
        cin >> value;
        total_sum += value;
    }

    vector<long long> dp(n, 0);
    for (int left = n - 1; left >= 0; --left) {
        dp[left] = values[left];
        for (int right = left + 1; right < n; ++right) {
            dp[right] = max(values[left] - dp[right], values[right] - dp[right - 1]);
        }
    }

    const long long difference = dp[n - 1];
    cout << (total_sum + difference) / 2 << '\n';
    return 0;
}
