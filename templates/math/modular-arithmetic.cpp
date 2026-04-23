// Template: modular arithmetic helpers for prime MOD.

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
