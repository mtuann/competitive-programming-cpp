// Problem: CRYPTKEY - VOI 2015 Day 1 - Chìa khóa mã số
// Judge: VN SPOJ
// Source URL: https://vn.spoj.com/problems/CRYPTKEY/
// Topic: membership in the closure under gcd/lcm
// Idea: for each prime power p^e dividing k, gcd all input numbers divisible by p^e and check that this gcd divides k and keeps p^e exactly

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

static long long gcd_ll(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a >= 0 ? a : -a;
}

static vector<pair<long long, int> > factorize(long long x) {
    vector<pair<long long, int> > fac;
    for (long long p = 2; p * p <= x; ++p) {
        if (x % p != 0) continue;
        int e = 0;
        while (x % p == 0) {
            x /= p;
            ++e;
        }
        fac.push_back(make_pair(p, e));
    }
    if (x > 1) fac.push_back(make_pair(x, 1));
    return fac;
}

static long long power_ll(long long base, int exp) {
    long long result = 1;
    while (exp--) result *= base;
    return result;
}

static int exponent_of(long long x, long long p) {
    int e = 0;
    while (x % p == 0) {
        x /= p;
        ++e;
    }
    return e;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        long long k;
        cin >> k;

        if (k == 1) {
            long long g = 0;
            for (int i = 0; i < n; ++i) g = gcd_ll(g, a[i]);
            cout << (g == 1 ? "YES\n" : "NO\n");
            continue;
        }

        vector<pair<long long, int> > fac = factorize(k);
        bool ok = true;

        for (int idx = 0; idx < (int)fac.size() && ok; ++idx) {
            long long p = fac[idx].first;
            int e = fac[idx].second;
            long long need = power_ll(p, e);

            long long g = 0;
            bool found = false;

            for (int i = 0; i < n; ++i) {
                if (a[i] % need != 0) continue;
                found = true;
                g = (g == 0 ? a[i] : gcd_ll(g, a[i]));
            }

            if (!found) {
                ok = false;
                break;
            }

            if (k % g != 0) {
                ok = false;
                break;
            }

            if (exponent_of(g, p) != e) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
