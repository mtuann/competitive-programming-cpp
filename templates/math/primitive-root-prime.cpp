// Template: primitive root modulo one prime
// Signal: find one generator g of the nonzero residues modulo prime p.
// Assumes: p is prime, p - 1 can be factored cheaply enough by trial division, and one primitive root is enough.
// Exposes: mul_mod(a, b, mod), pow_mod(a, e, mod), distinct_prime_divisors_trial(n), primitive_root_prime(p).
// Complexity: trial division factorization of p - 1 plus O(k log p) per candidate, where k is the number of distinct prime divisors.
// Main trap: reusing this starter unchanged when the real bottleneck is 64-bit factorization of p - 1, or when the modulus is composite.
// Links:
//   Topic: topics/math/primitive-root/README.md
//   Note: practice/ladders/math/primitive-root/primitiveroot.md

#include <cstdint>
#include <iostream>
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

vector<u64> distinct_prime_divisors_trial(u64 n) {
    vector<u64> factors;
    if ((n & 1ULL) == 0) {
        factors.push_back(2);
        while ((n & 1ULL) == 0) {
            n >>= 1ULL;
        }
    }
    for (u64 d = 3; d <= n / d; d += 2) {
        if (n % d != 0) {
            continue;
        }
        factors.push_back(d);
        while (n % d == 0) {
            n /= d;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

u64 primitive_root_prime(u64 p) {
    if (p == 2) {
        return 1;
    }
    u64 phi = p - 1;
    vector<u64> factors = distinct_prime_divisors_trial(phi);
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
    for (u64 p : {2ULL, 17ULL, 998244353ULL}) {
        cout << primitive_root_prime(p) << '\n';
    }
    return 0;
}
