// Template: Lucas theorem binomial
// Signal: compute nCk mod p for prime p when some queries may cross n >= p.
// Assumes: p is prime and small enough that O(p) precompute for 0..p-1 is feasible.
// Exposes: LucasCombPrime(p) with small_binom(n, k) and binom(n, k).
// Complexity: build O(p), query O(log_p n).
// Main trap: using Lucas under a huge prime modulus where the O(p) digit table is not contest-safe.
// Links:
//   Topic: topics/math/lucas-theorem/README.md
//   Note: practice/ladders/math/lucas-theorem/binomialcoefficientprimemod.md

#include <cstdint>
#include <iostream>
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
    LucasCombPrime comb(5);
    cout << comb.binom(10, 3) << '\n';
    return 0;
}
