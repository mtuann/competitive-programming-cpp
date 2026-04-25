#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    vector<long double> dp(1, 1.0L);
    for (int throw_idx = 0; throw_idx < n; ++throw_idx) {
        vector<long double> nxt(dp.size() + 6, 0.0L);
        for (int sum = 0; sum < static_cast<int>(dp.size()); ++sum) {
            if (dp[sum] == 0.0L) {
                continue;
            }
            for (int face = 1; face <= 6; ++face) {
                nxt[sum + face] += dp[sum] / 6.0L;
            }
        }
        dp.swap(nxt);
    }

    a = max(a, 0);
    b = min(b, static_cast<int>(dp.size()) - 1);

    long double ans = 0.0L;
    for (int sum = a; sum <= b; ++sum) {
        ans += dp[sum];
    }

    cout << fixed << setprecision(6) << static_cast<double>(ans) << '\n';
    return 0;
}
