// Problem: Counting Numbers
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/2220
// Topic: digit DP, previous-digit state, range counting
// Idea: solve(x) counts valid numbers in [0, x]. Use digit DP with state
// (pos, prev_digit, started, tight) and forbid transitions where a real digit
// equals the previous real digit.

#include <cstring>
#include <iostream>
#include <string>

using namespace std;

long long memo[20][11][2];
bool seen[20][11][2];
string digits;

long long dfs(int pos, int prev_digit, bool started, bool tight) {
    if (pos == static_cast<int>(digits.size())) {
        return 1;
    }

    if (!tight && seen[pos][prev_digit][started]) {
        return memo[pos][prev_digit][started];
    }

    int limit = tight ? digits[pos] - '0' : 9;
    long long ways = 0;

    for (int digit = 0; digit <= limit; ++digit) {
        bool next_started = started || (digit != 0);
        if (started && digit == prev_digit) {
            continue;
        }

        int next_prev = next_started ? digit : 10;
        ways += dfs(pos + 1, next_prev, next_started, tight && digit == limit);
    }

    if (!tight) {
        seen[pos][prev_digit][started] = true;
        memo[pos][prev_digit][started] = ways;
    }
    return ways;
}

long long count_up_to(long long x) {
    if (x < 0) {
        return 0;
    }
    digits = to_string(x);
    memset(seen, 0, sizeof(seen));
    return dfs(0, 10, false, true);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    cin >> a >> b;
    cout << count_up_to(b) - count_up_to(a - 1) << '\n';
    return 0;
}
