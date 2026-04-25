// Problem: Inv of Formal Power Series
// Judge: Library Checker
// Source URL: https://judge.yosupo.jp/problem/inv_of_formal_power_series
// Topic: Formal power series, Newton iteration, NTT
// Idea: build the inverse modulo x^n by doubling a correct prefix with
// B <- B * (2 - A * B), truncating every intermediate product.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

static constexpr int MOD = 998244353;
static constexpr int PRIMITIVE_ROOT = 3;

struct Mint {
    int v;

    Mint(long long x = 0) {
        x %= MOD;
        if (x < 0) x += MOD;
        v = static_cast<int>(x);
    }

    Mint& operator+=(const Mint& other) {
        v += other.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }

    Mint& operator-=(const Mint& other) {
        v -= other.v;
        if (v < 0) v += MOD;
        return *this;
    }

    Mint& operator*=(const Mint& other) {
        v = static_cast<int>(1LL * v * other.v % MOD);
        return *this;
    }

    Mint pow(long long e) const {
        Mint result(1), base(*this);
        while (e > 0) {
            if (e & 1LL) result *= base;
            base *= base;
            e >>= 1LL;
        }
        return result;
    }

    Mint inv() const {
        return pow(MOD - 2);
    }
};

static Mint operator+(Mint a, const Mint& b) { return a += b; }
static Mint operator-(Mint a, const Mint& b) { return a -= b; }
static Mint operator*(Mint a, const Mint& b) { return a *= b; }

static void ntt(vector<Mint>& a, bool invert) {
    int n = static_cast<int>(a.size());
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        Mint wlen = Mint(PRIMITIVE_ROOT).pow((MOD - 1) / len);
        if (invert) wlen = wlen.inv();
        for (int i = 0; i < n; i += len) {
            Mint w(1);
            for (int j = 0; j < len / 2; ++j) {
                Mint u = a[i + j];
                Mint v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        Mint inv_n = Mint(n).inv();
        for (Mint& x : a) x *= inv_n;
    }
}

static vector<Mint> convolution(vector<Mint> a, vector<Mint> b) {
    if (a.empty() || b.empty()) return {};
    int need = static_cast<int>(a.size() + b.size() - 1);
    int n = 1;
    while (n < need) n <<= 1;
    a.resize(n);
    b.resize(n);
    ntt(a, false);
    ntt(b, false);
    for (int i = 0; i < n; ++i) a[i] *= b[i];
    ntt(a, true);
    a.resize(need);
    return a;
}

static vector<Mint> fps_inv(const vector<Mint>& a, int need) {
    assert(need >= 1);
    assert(!a.empty() && a[0].v != 0);

    vector<Mint> b(1, a[0].inv());
    int m = 1;
    while (m < need) {
        int take = min(static_cast<int>(a.size()), m << 1);
        vector<Mint> f(take);
        for (int i = 0; i < take; ++i) f[i] = a[i];

        vector<Mint> x = convolution(f, b);
        x.resize(m << 1);
        for (Mint& coeff : x) coeff = Mint() - coeff;
        x[0] += Mint(2);

        vector<Mint> nb = convolution(b, x);
        nb.resize(m << 1);
        b.swap(nb);
        m <<= 1;
    }
    b.resize(need);
    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Mint> a(n);
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        a[i] = Mint(x);
    }

    vector<Mint> b = fps_inv(a, n);
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << b[i].v;
    }
    cout << '\n';
    return 0;
}
