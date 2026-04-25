#include <cstdint>
#include <iostream>

using namespace std;

struct CRTResult {
    bool ok;
    long long a;
    long long m;
};

long long norm_mod(long long x, long long mod) {
    x %= mod;
    if (x < 0) x += mod;
    return x;
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

CRTResult merge_congruence(long long a1, long long m1, long long a2, long long m2) {
    a1 = norm_mod(a1, m1);
    a2 = norm_mod(a2, m2);

    long long x = 0, y = 0;
    long long g = ext_gcd(m1, m2, x, y);
    long long diff = a2 - a1;
    if (diff % g != 0) {
        return {false, 0, 0};
    }

    long long mod = m2 / g;
    long long inv = norm_mod(x, mod);
    long long step = static_cast<long long>(
        (static_cast<__int128>(diff / g) * inv) % mod
    );
    if (step < 0) step += mod;

    long long lcm = static_cast<long long>(static_cast<__int128>(m1 / g) * m2);
    long long merged = static_cast<long long>(
        (static_cast<__int128>(a1) + static_cast<__int128>(m1) * step) % lcm
    );
    merged = norm_mod(merged, lcm);
    return {true, merged, lcm};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a, n, b, m;
        cin >> a >> n >> b >> m;
        CRTResult ans = merge_congruence(a, n, b, m);
        if (!ans.ok) {
            cout << "no solution\n";
        } else {
            cout << ans.a << ' ' << ans.m << '\n';
        }
    }
    return 0;
}
