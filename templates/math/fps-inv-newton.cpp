// Template: Formal power series inverse modulo x^n
// Signal: invert one FPS A(x) with nonzero constant term under 998244353.
// Assumes: truncation modulo x^n, NTT-friendly modulus 998244353, and a[0] != 0.
// Exposes: convolution(a, b) and fps_inv(a, need).
// Complexity: O(n log^2 n) with Newton doubling and repeated NTT products.
// Main trap: forgetting to truncate every doubling step or calling it with a[0] = 0.
// Links:
//   Topic: topics/math/polynomial-fps/README.md
//   Note: practice/ladders/math/polynomial-fps/invofformalpowerseries.md

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
    vector<Mint> a = {1, Mint(MOD - 1)};  // 1 - x
    vector<Mint> inv = fps_inv(a, 6);
    for (Mint coeff : inv) {
        cout << coeff.v << ' ';
    }
    cout << '\n';  // 1 1 1 1 1 1
    return 0;
}
