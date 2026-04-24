// Problem: Exponentiation
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1095
// Topic: binary exponentiation, modular arithmetic
// Idea: repeated squaring answers each a^b query in O(log b). Starting the
// accumulator at 1 also matches the judge convention 0^0 = 1.

#include <iostream>

using namespace std;

static constexpr long long MOD = 1'000'000'007LL;

long long mod_pow(long long base, long long exp) {
    base %= MOD;
    long long result = 1;
    while (exp > 0) {
        if (exp & 1LL) {
            result = result * base % MOD;
        }
        base = base * base % MOD;
        exp >>= 1LL;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        cout << mod_pow(a, b) << '\n';
    }
    return 0;
}
