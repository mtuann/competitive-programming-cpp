// Use when: prime-mod nCk with many queries after one precompute.
// Invariant: mod is prime and every query satisfies 0 <= k <= n <= max_n < mod.
// Complexity: build O(max_n + log mod), query O(1).

#include <vector>

using namespace std;

long long mod_pow(long long a, long long e, long long mod) {
    long long result = 1 % mod;
    a %= mod;
    while (e > 0) {
        if (e & 1LL) {
            result = result * a % mod;
        }
        a = a * a % mod;
        e >>= 1LL;
    }
    return result;
}

struct Comb {
    int max_n;
    long long mod;
    vector<long long> fact, inv_fact;

    Comb(int max_n, long long mod) : max_n(max_n), mod(mod), fact(max_n + 1), inv_fact(max_n + 1) {
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
        if (n < 0 || n > max_n || k < 0 || k > n) return 0;
        return fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
    }
};
