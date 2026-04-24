#include <iostream>

using namespace std;

constexpr long long MOD = 1000000007LL;

long long mod_pow(long long base, long long exponent, long long mod) {
    base %= mod;
    long long result = 1 % mod;
    while (exponent > 0) {
        if (exponent & 1LL) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent >>= 1LL;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;

        if (a % MOD == 0) {
            if (b == 0 && c > 0) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
            continue;
        }

        long long exponent = mod_pow(b, c, MOD - 1);
        cout << mod_pow(a, exponent, MOD) << '\n';
    }

    return 0;
}
