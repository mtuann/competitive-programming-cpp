#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr int MOD = 1'000'000'007;

void generate_next_masks(int row, int height, int cur_mask, int next_mask, int ways,
                         vector<int>& next_dp) {
    if (row == height) {
        next_dp[next_mask] += ways;
        if (next_dp[next_mask] >= MOD) next_dp[next_mask] -= MOD;
        return;
    }

    if (cur_mask & (1 << row)) {
        generate_next_masks(row + 1, height, cur_mask, next_mask, ways, next_dp);
        return;
    }

    generate_next_masks(row + 1, height, cur_mask, next_mask | (1 << row), ways, next_dp);

    if (row + 1 < height && !(cur_mask & (1 << (row + 1)))) {
        generate_next_masks(row + 2, height, cur_mask, next_mask, ways, next_dp);
    }
}

int count_domino_tilings(int rows, int cols) {
    if ((rows * cols) & 1) return 0;

    int height = min(rows, cols);
    int width = max(rows, cols);
    vector<int> dp(1 << height, 0), next_dp(1 << height, 0);
    dp[0] = 1;

    for (int col = 0; col < width; ++col) {
        fill(next_dp.begin(), next_dp.end(), 0);
        for (int mask = 0; mask < (1 << height); ++mask) {
            if (dp[mask] == 0) continue;
            generate_next_masks(0, height, mask, 0, dp[mask], next_dp);
        }
        dp.swap(next_dp);
    }

    return dp[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    cout << count_domino_tilings(n, m) << '\n';
    return 0;
}
