// Template: digit DP skeleton
// Signal: count over digits with tight/started flags and one previous-digit state.
// Assumes: decimal digits, top-down memoization, and prev_digit is part of the state.
// Exposes: solve(pos, tight, started, prev_digit) over a global digits string.
// Complexity: O(number of states * 10).
// Main trap: copying the skeleton as if it were fully generic and forgetting the prev_digit dimension is baked in.
// Links:
//   Topic: topics/dp/digit-dp/README.md
//   Note: practice/ladders/dp/digit-dp/countingnumbers.md

#include <cstring>
#include <iostream>
#include <string>

using namespace std;

string digits;
long long memo[20][2][2][10];
bool seen[20][2][2][10];

long long solve(int pos, int tight, int started, int prev_digit) {
    if (pos == static_cast<int>(digits.size())) return 1;
    long long &ans = memo[pos][tight][started][prev_digit];
    if (seen[pos][tight][started][prev_digit]) return ans;
    seen[pos][tight][started][prev_digit] = true;
    ans = 0;
    int limit = tight ? digits[pos] - '0' : 9;
    for (int dig = 0; dig <= limit; ++dig) {
        int ntight = tight && (dig == limit);
        int nstarted = started || (dig != 0);
        int nprev = nstarted ? dig : 0;
        ans += solve(pos + 1, ntight, nstarted, nprev);
    }
    return ans;
}

int main() {
    digits = "123";
    memset(seen, 0, sizeof(seen));
    cout << solve(0, 1, 0, 0) << '\n';
    return 0;
}
