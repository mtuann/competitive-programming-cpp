#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

long long mod_pow(long long a, long long e, long long mod) {
    long long result = 1 % mod;
    a %= mod;
    while (e > 0) {
        if (e & 1LL) {
            result = static_cast<long long>((static_cast<__int128>(result) * a) % mod);
        }
        a = static_cast<long long>((static_cast<__int128>(a) * a) % mod);
        e >>= 1LL;
    }
    return result;
}

struct CombPrime {
    long long mod;
    vector<long long> fact;
    vector<long long> inv_fact;

    CombPrime(int max_n, long long mod) : mod(mod), fact(max_n + 1), inv_fact(max_n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= max_n; ++i) {
            fact[i] = fact[i - 1] * i % mod;
        }
        inv_fact[max_n] = mod_pow(fact[max_n], mod - 2, mod);
        for (int i = max_n; i > 0; --i) {
            inv_fact[i - 1] = inv_fact[i] * i % mod;
        }
    }

    long long binom(int n, int k) const {
        if (k < 0 || k > n) {
            return 0;
        }
        return fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
    }
};

struct LucasCombPrime {
    int p;
    vector<long long> fact;
    vector<long long> inv_fact;

    explicit LucasCombPrime(int prime) : p(prime), fact(prime), inv_fact(prime) {
        fact[0] = 1;
        for (int i = 1; i < p; ++i) {
            fact[i] = fact[i - 1] * i % p;
        }
        inv_fact[p - 1] = mod_pow(fact[p - 1], p - 2, p);
        for (int i = p - 1; i > 0; --i) {
            inv_fact[i - 1] = inv_fact[i] * i % p;
        }
    }

    long long small_binom(int n, int k) const {
        if (k < 0 || k > n) {
            return 0;
        }
        return fact[n] * inv_fact[k] % p * inv_fact[n - k] % p;
    }

    long long binom(long long n, long long k) const {
        if (k < 0 || k > n) {
            return 0;
        }
        long long result = 1;
        while (n > 0 || k > 0) {
            int ni = static_cast<int>(n % p);
            int ki = static_cast<int>(k % p);
            if (ki > ni) {
                return 0;
            }
            result = result * small_binom(ni, ki) % p;
            n /= p;
            k /= p;
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    long long p;
    cin >> p;

    vector<pair<long long, long long>> queries(t);
    long long max_n = 0;
    for (auto& [n, k] : queries) {
        cin >> n >> k;
        max_n = max(max_n, n);
    }

    if (max_n < p) {
        CombPrime comb(static_cast<int>(max_n), p);
        for (const auto& [n, k] : queries) {
            cout << comb.binom(static_cast<int>(n), static_cast<int>(k)) << '\n';
        }
    } else {
        LucasCombPrime comb(static_cast<int>(p));
        for (const auto& [n, k] : queries) {
            cout << comb.binom(n, k) << '\n';
        }
    }
    return 0;
}
