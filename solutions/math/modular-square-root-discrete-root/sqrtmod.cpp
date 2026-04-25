#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;

long long norm_mod(long long a, long long mod) {
    a %= mod;
    if (a < 0) {
        a += mod;
    }
    return a;
}

long long pow_mod(long long a, long long e, long long mod) {
    long long result = 1 % mod;
    a = norm_mod(a, mod);
    while (e > 0) {
        if (e & 1LL) {
            result = static_cast<long long>((static_cast<__int128>(result) * a) % mod);
        }
        a = static_cast<long long>((static_cast<__int128>(a) * a) % mod);
        e >>= 1LL;
    }
    return result;
}

long long legendre_symbol(long long a, long long p) {
    if (p == 2) {
        return norm_mod(a, p);
    }
    long long val = pow_mod(a, (p - 1) / 2, p);
    if (val == p - 1) {
        return -1;
    }
    return val;
}

long long modular_sqrt_prime(long long a, long long p) {
    a = norm_mod(a, p);
    if (a == 0 || p == 2) {
        return a;
    }
    if (legendre_symbol(a, p) != 1) {
        return -1;
    }
    if (p % 4 == 3) {
        long long r = pow_mod(a, (p + 1) / 4, p);
        return min(r, p - r);
    }

    long long q = p - 1;
    int s = 0;
    while ((q & 1LL) == 0) {
        q >>= 1LL;
        ++s;
    }

    long long z = 2;
    while (legendre_symbol(z, p) != -1) {
        ++z;
    }

    long long c = pow_mod(z, q, p);
    long long r = pow_mod(a, (q + 1) / 2, p);
    long long t = pow_mod(a, q, p);
    int m = s;

    while (t != 1) {
        int i = 1;
        long long tt = static_cast<long long>((static_cast<__int128>(t) * t) % p);
        while (i < m && tt != 1) {
            tt = static_cast<long long>((static_cast<__int128>(tt) * tt) % p);
            ++i;
        }

        long long b = c;
        for (int j = 0; j < m - i - 1; ++j) {
            b = static_cast<long long>((static_cast<__int128>(b) * b) % p);
        }

        r = static_cast<long long>((static_cast<__int128>(r) * b) % p);
        c = static_cast<long long>((static_cast<__int128>(b) * b) % p);
        t = static_cast<long long>((static_cast<__int128>(t) * c) % p);
        m = i;
    }

    return min(r, p - r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long y, p;
        cin >> y >> p;
        cout << modular_sqrt_prime(y, p) << '\n';
    }
    return 0;
}
