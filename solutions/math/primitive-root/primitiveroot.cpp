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

bool is_prime(u64 n) {
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

    uniform_int_distribution<u64> dist(2, n - 2);
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

void factor_rec(u64 n, vector<u64>& factors) {
    if (n == 1) {
        return;
    }
    if (is_prime(n)) {
        factors.push_back(n);
        return;
    }
    u64 d = pollard_rho(n);
    factor_rec(d, factors);
    factor_rec(n / d, factors);
}

vector<u64> distinct_prime_divisors(u64 n) {
    vector<u64> factors;
    factor_rec(n, factors);
    sort(factors.begin(), factors.end());
    factors.erase(unique(factors.begin(), factors.end()), factors.end());
    return factors;
}

u64 primitive_root_prime(u64 p) {
    if (p == 2) {
        return 1;
    }
    u64 phi = p - 1;
    vector<u64> factors = distinct_prime_divisors(phi);
    for (u64 g = 2; g < p; ++g) {
        bool ok = true;
        for (u64 q : factors) {
            if (pow_mod(g, phi / q, p) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return g;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        u64 p;
        cin >> p;
        cout << primitive_root_prime(p) << '\n';
    }
    return 0;
}
