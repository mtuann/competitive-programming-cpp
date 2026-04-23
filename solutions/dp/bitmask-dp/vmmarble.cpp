#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
Problem: VMMARBLE - Phân loại bi
Judge: VN SPOJ
URL: https://vn.spoj.com/problems/VMMARBLE/
Topic: DP, bitmask DP, assignment

Key idea:
- after choosing which single color each box will keep, every other source-color
  group must leave that box
- group (box i, color j) needs exactly ceil(A[i][j] / K) moves if box i does not
  keep color j: this is both a lower bound and directly achievable
- so the only real decision is which color each box keeps, with the constraint
  that every color that actually appears must be kept by at least one box
- run a DP over the set of colors already covered
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<vector<long long>> keep_cost(n, vector<long long>(m, 0));
    long long base_cost = 0;
    int required_mask = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            long long marbles;
            cin >> marbles;
            if (marbles > 0) {
                required_mask |= (1 << j);
            }
            keep_cost[i][j] = (marbles + k - 1) / k;
            base_cost += keep_cost[i][j];
        }
    }

    const long long NEG_INF = -(1LL << 60);
    vector<long long> dp(1 << m, NEG_INF);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        vector<long long> next = dp;
        for (int mask = 0; mask < (1 << m); ++mask) {
            if (dp[mask] == NEG_INF) {
                continue;
            }
            for (int color = 0; color < m; ++color) {
                int new_mask = mask | (1 << color);
                next[new_mask] = max(next[new_mask], dp[mask] + keep_cost[i][color]);
            }
        }
        dp.swap(next);
    }

    cout << (base_cost - dp[required_mask]) << '\n';
    return 0;
}
