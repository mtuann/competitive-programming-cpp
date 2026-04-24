// Template: modular arithmetic helpers
// Signal: repeated powmod and inverse queries under one fixed prime modulus.
// Assumes: MOD is prime and all inverses are only requested for values coprime to MOD.
// Exposes: mod_pow(a, e) and mod_inv(a) under the fixed global MOD.
// Complexity: O(log e) for mod_pow, O(log MOD) for mod_inv.
// Main trap: copying the helpers into a composite-modulus problem and trusting Fermat anyway.
// Links:
//   Topic: topics/math/modular-arithmetic/README.md
//   Note: practice/ladders/math/modular-arithmetic/exponentiation2.md

#include <iostream>

using namespace std;

const long long MOD = 1000000007LL;

long long mod_pow(long long a, long long e) {
    long long result = 1 % MOD;
    a %= MOD;
    while (e > 0) {
        if (e & 1LL) {
            result = result * a % MOD;
        }
        a = a * a % MOD;
        e >>= 1LL;
    }
    return result;
}

long long mod_inv(long long a) {
    return mod_pow(a, MOD - 2);
}

int main() {
    cout << mod_pow(2, 10) << '\n';
    cout << mod_inv(5) << '\n';
    return 0;
}
