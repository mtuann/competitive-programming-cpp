// Template: Discrete log via baby-step giant-step
// Signal: solve a^x ≡ b (mod m) when the unknown is the exponent and O(sqrt(m)) memory is acceptable.
// Assumes: modulus is positive, arithmetic fits in long long with __int128 products, and the contest can afford a square-root hash table.
// Exposes: pow_mod(a, e, mod), mod_inverse(a, mod), bsgs_coprime(a, b, mod), and discrete_log(a, b, mod).
// Complexity: O(sqrt(m)) time and memory after O(log^2 m)-style arithmetic overhead.
// Main trap: skipping the gcd-reduction stage and then trying to invert a modulo a non-coprime modulus.
// Links:
//   Topic: topics/math/bsgs-discrete-log/README.md
//   Note: practice/ladders/math/bsgs-discrete-log/discretelogarithmmod.md

#include <cmath>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <optional>
#include <tuple>
#include <unordered_map>

using namespace std;

long long norm_mod(long long x, long long mod) {
    x %= mod;
    if (x < 0) {
        x += mod;
    }
    return x;
}

long long mul_mod(long long a, long long b, long long mod) {
    return static_cast<long long>((static_cast<__int128>(a) * b) % mod);
}

long long pow_mod(long long a, long long e, long long mod) {
    long long result = 1 % mod;
    a = norm_mod(a, mod);
    while (e > 0) {
        if (e & 1LL) {
            result = mul_mod(result, a, mod);
        }
        a = mul_mod(a, a, mod);
        e >>= 1LL;
    }
    return result;
}

long long ext_gcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = (a >= 0 ? 1 : -1);
        y = 0;
        return a >= 0 ? a : -a;
    }
    long long x1 = 0, y1 = 0;
    long long g = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

long long mod_inverse(long long a, long long mod) {
    long long x = 0, y = 0;
    long long g = ext_gcd(a, mod, x, y);
    if (g != 1) {
        return -1;
    }
    return norm_mod(x, mod);
}

optional<long long> bsgs_coprime(long long a, long long b, long long mod) {
    a = norm_mod(a, mod);
    b = norm_mod(b, mod);

    if (mod == 1) {
        return 0;
    }
    if (b == 1 % mod) {
        return 0;
    }

    long long n = static_cast<long long>(sqrt(static_cast<long double>(mod)) + 1);
    unordered_map<long long, long long> baby;
    baby.reserve(static_cast<size_t>(n * 2 + 3));

    long long cur = 1 % mod;
    for (long long q = 0; q <= n; ++q) {
        if (!baby.count(cur)) {
            baby[cur] = q;
        }
        cur = mul_mod(cur, a, mod);
    }

    long long inv_a = mod_inverse(a, mod);
    if (inv_a == -1) {
        return nullopt;
    }
    long long factor = pow_mod(inv_a, n, mod);

    optional<long long> answer;
    cur = b;
    for (long long p = 0; p <= n; ++p) {
        auto it = baby.find(cur);
        if (it != baby.end()) {
            long long candidate = p * n + it->second;
            if (pow_mod(a, candidate, mod) == b) {
                if (!answer || candidate < *answer) {
                    answer = candidate;
                }
            }
        }
        cur = mul_mod(cur, factor, mod);
    }
    return answer;
}

optional<long long> discrete_log(long long a, long long b, long long mod) {
    if (mod == 1) {
        return 0;
    }

    a = norm_mod(a, mod);
    b = norm_mod(b, mod);

    if (b == 1 % mod) {
        return 0;
    }
    if (a == 0) {
        if (b == 0) {
            return 1;
        }
        return nullopt;
    }

    long long add = 0;
    long long k = 1 % mod;

    while (true) {
        long long g = gcd(a, mod);
        if (g == 1) {
            break;
        }
        if (b == k) {
            return add;
        }
        if (b % g != 0) {
            return nullopt;
        }
        b /= g;
        mod /= g;
        ++add;
        k = mul_mod(k, a / g, mod);
        if (mod == 1) {
            return add;
        }
    }

    long long inv_k = mod_inverse(k, mod);
    if (inv_k == -1) {
        return nullopt;
    }
    long long target = mul_mod(b, inv_k, mod);
    auto rest = bsgs_coprime(a, target, mod);
    if (!rest) {
        return nullopt;
    }
    return add + *rest;
}

int main() {
    for (const auto [a, b, mod] : {tuple<long long, long long, long long>{2, 3, 5},
                                   tuple<long long, long long, long long>{4, 2, 14},
                                   tuple<long long, long long, long long>{2, 3, 7}}) {
        auto ans = discrete_log(a, b, mod);
        cout << (ans ? *ans : -1) << '\n';
    }
    return 0;
}
