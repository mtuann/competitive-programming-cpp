// Problem: VOSFENCE - Xay hang rao
// Judge: VN SPOJ / VNOI mirror
// Source URL: https://vn.spoj.com/problems/VOSFENCE/
// Mirror URL: https://oj.vnoi.info/problem/vosfence
// Topic: bounded compositions / combinatorial counting
// Idea: count the B/R skeleton by number of color changes, then distribute W white bars into gaps with upper bounds

#include <iostream>
#include <vector>

using namespace std;

namespace {

const int MOD = 1000000007;

long long add_mod(long long a, long long b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
    return a;
}

vector<vector<long long>> build_bounded_dp(int vars, int sum_limit, int upper) {
    vector<vector<long long>> dp(vars + 1, vector<long long>(sum_limit + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= vars; ++i) {
        for (int s = 0; s <= sum_limit; ++s) {
            long long ways = 0;
            for (int x = 0; x <= upper && x <= s; ++x) {
                ways += dp[i - 1][s - x];
                if (ways >= MOD) {
                    ways -= MOD;
                }
            }
            dp[i][s] = ways;
        }
    }

    return dp;
}

}  // namespace

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w, b, r, k, m;
    cin >> w >> b >> r >> k >> m;

    const int colored = b + r;

    if (colored == 0) {
        cout << ((m == 0 && w < k) ? 1 : 0) << '\n';
        return 0;
    }

    vector<vector<long long>> comb(colored + 2, vector<long long>(colored + 2, 0));
    comb[0][0] = 1;
    for (int i = 1; i <= colored + 1; ++i) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            comb[i][j] = add_mod(comb[i - 1][j - 1], comb[i - 1][j]);
        }
    }

    vector<long long> skeleton_count(colored, 0);
    if (b == 0 || r == 0) {
        skeleton_count[0] = 1;
    } else {
        for (int transitions = 0; transitions < colored; ++transitions) {
            if ((transitions & 1) == 0) {
                int x = transitions / 2;

                int blue_runs = x + 1;
                int red_runs = x;
                if (red_runs > 0 && b >= blue_runs && r >= red_runs) {
                    skeleton_count[transitions] = add_mod(
                        skeleton_count[transitions],
                        comb[b - 1][blue_runs - 1] * comb[r - 1][red_runs - 1] % MOD
                    );
                }

                blue_runs = x;
                red_runs = x + 1;
                if (blue_runs > 0 && b >= blue_runs && r >= red_runs) {
                    skeleton_count[transitions] = add_mod(
                        skeleton_count[transitions],
                        comb[b - 1][blue_runs - 1] * comb[r - 1][red_runs - 1] % MOD
                    );
                }
            } else {
                int runs = (transitions + 1) / 2;
                if (b >= runs && r >= runs) {
                    long long ways = 2LL * comb[b - 1][runs - 1] % MOD * comb[r - 1][runs - 1] % MOD;
                    skeleton_count[transitions] = add_mod(skeleton_count[transitions], ways);
                }
            }
        }
    }

    vector<vector<long long>> high = build_bounded_dp(colored + 1, w, max(0, k - 1));
    vector<vector<long long>> low(colored + 2, vector<long long>(w + 1, 0));
    if (k >= 2) {
        low = build_bounded_dp(colored + 1, w, k - 2);
    } else {
        low[0][0] = 1;
    }

    long long answer = 0;

    for (int transitions = 0; transitions < colored; ++transitions) {
        if (m > transitions) {
            continue;
        }
        int broken = transitions - m;
        if (broken > w) {
            continue;
        }
        if (k == 1 && broken > 0) {
            continue;
        }

        int free_gaps = colored + 1 - transitions;
        int remain = w - broken;

        long long gap_ways = 0;
        for (int x = 0; x <= remain; ++x) {
            gap_ways += low[broken][x] * high[free_gaps][remain - x] % MOD;
            if (gap_ways >= MOD) {
                gap_ways -= MOD;
            }
        }

        long long ways = skeleton_count[transitions] * comb[transitions][m] % MOD * gap_ways % MOD;
        answer += ways;
        if (answer >= MOD) {
            answer -= MOD;
        }
    }

    cout << answer % MOD << '\n';
    return 0;
}
