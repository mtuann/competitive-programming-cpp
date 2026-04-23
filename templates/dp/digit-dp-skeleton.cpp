// Template: memoized digit DP skeleton.

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
