// Problem: Distributing Apples
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1716
// Topic: stars and bars, binomial coefficient, modular arithmetic
// Idea: the number of nonnegative solutions to x1 + ... + xn = m is
// C(n + m - 1, n - 1). Precompute factorials and inverse factorials modulo
// 1e9+7 up to n + m - 1.

#include <iostream>
#include <vector>

using namespace std;

static constexpr int MOD = 1'000'000'007;

long long mod_pow(long long base, long long exp) {
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

    int n, m;
    cin >> n >> m;

    int limit = n + m - 1;
    vector<long long> fact(limit + 1, 1);
    for (int i = 1; i <= limit; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    vector<long long> inv_fact(limit + 1, 1);
    inv_fact[limit] = mod_pow(fact[limit], MOD - 2);
    for (int i = limit; i >= 1; --i) {
        inv_fact[i - 1] = inv_fact[i] * i % MOD;
    }

    auto comb = [&](int nn, int kk) -> long long {
        if (kk < 0 || kk > nn) {
            return 0;
        }
        return fact[nn] * inv_fact[kk] % MOD * inv_fact[nn - kk] % MOD;
    };

    cout << comb(n + m - 1, n - 1) << '\n';
    return 0;
}
