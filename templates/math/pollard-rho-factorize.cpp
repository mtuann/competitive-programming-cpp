// Template: factor one 64-bit integer with Miller-Rabin + Pollard-Rho
// Signal: factor n <= 1e18 into prime factors when trial division is too slow.
// Assumes: 64-bit unsigned arithmetic, safe __int128 modular multiplication, and one sorted prime-factor multiset is enough.
// Exposes: mul_mod(a, b, mod), pow_mod(a, e, mod), is_prime_u64(n), pollard_rho(n), factorize_u64(n).
// Complexity: deterministic 64-bit primality tests plus heuristic Pollard-Rho splitting; practical for contest-sized 64-bit inputs.
// Main trap: skipping the primality gate, accepting d == n as a good split, or forgetting to sort the final prime multiset.
// Links:
//   Topic: topics/math/pollard-rho/README.md
//   Note: practice/ladders/math/pollard-rho/factorize.md

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

using u64 = unsigned long long;
using u128 = __uint128_t;

u64 mul_mod(u64 a, u64 b, u64 mod) {
    return static_cast<u64>((static_cast<u128>(a) * b) % mod);
}

u64 pow_mod(u64 a, u64 e, u64 mod) {
    u64 result = 1 % mod;
    a %= mod;
    while (e > 0) {
        if (e & 1ULL) {
            result = mul_mod(result, a, mod);
        }
        a = mul_mod(a, a, mod);
        e >>= 1ULL;
    }
    return result;
}

bool is_prime_u64(u64 n) {
    if (n < 2) {
        return false;
    }
    for (u64 p : {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL, 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL}) {
        if (n % p == 0) {
            return n == p;
        }
    }

    u64 d = n - 1;
    int s = 0;
    while ((d & 1ULL) == 0) {
        d >>= 1ULL;
        ++s;
    }

    for (u64 a : {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL}) {
        if (a % n == 0) {
            continue;
        }
        u64 x = pow_mod(a % n, d, n);
        if (x == 1 || x == n - 1) {
            continue;
        }
        bool witness = true;
        for (int r = 1; r < s; ++r) {
            x = mul_mod(x, x, n);
            if (x == n - 1) {
                witness = false;
                break;
            }
        }
        if (witness) {
            return false;
        }
    }
    return true;
}

mt19937_64 rng(static_cast<u64>(chrono::steady_clock::now().time_since_epoch().count()));

u64 pollard_rho(u64 n) {
    if ((n & 1ULL) == 0) {
        return 2;
    }
    if (n % 3 == 0) {
        return 3;
    }
    uniform_int_distribution<u64> dist(2ULL, n - 2);
    while (true) {
        u64 c = dist(rng);
        u64 x = dist(rng);
        u64 y = x;
        u64 d = 1;
        auto f = [&](u64 v) -> u64 { return (mul_mod(v, v, n) + c) % n; };
        while (d == 1) {
            x = f(x);
            y = f(f(y));
            u64 diff = x > y ? x - y : y - x;
            d = gcd(diff, n);
        }
        if (d != n) {
            return d;
        }
    }
}

void factor_rec(u64 n, vector<u64>& out) {
    if (n == 1) {
        return;
    }
    if (is_prime_u64(n)) {
        out.push_back(n);
        return;
    }
    u64 d = pollard_rho(n);
    factor_rec(d, out);
    factor_rec(n / d, out);
}

vector<u64> factorize_u64(u64 n) {
    vector<u64> factors;
    factor_rec(n, factors);
    sort(factors.begin(), factors.end());
    return factors;
}

int main() {
    for (u64 n : {84ULL, 8051ULL, 998244353ULL}) {
        auto factors = factorize_u64(n);
        for (int i = 0; i < static_cast<int>(factors.size()); ++i) {
            if (i) {
                cout << ' ';
            }
            cout << factors[i];
        }
        cout << '\n';
    }
    return 0;
}
