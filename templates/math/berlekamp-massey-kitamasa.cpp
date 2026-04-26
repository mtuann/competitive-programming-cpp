// Template: Berlekamp-Massey + Kitamasa under 998244353
// Signal: one linear recurrence over a fixed prime field, where you either need the k-th term fast
// or must recover the shortest recurrence from a prefix first.
// Assumes: arithmetic under 998244353, initial terms are 0-indexed, and recurrence is
// a_n = c[0] a_{n-1} + ... + c[d-1] a_{n-d}.
// Exposes: berlekamp_massey(seq) and linear_recurrence_kth(init, rec, k).
// Complexity: O(n^2) for Berlekamp-Massey on n known terms, O(d^2 log k) for Kitamasa jump.
// Main trap: reducing x^d with the recurrence coefficients in the wrong order.
// Links:
//   Topic: topics/math/berlekamp-massey-kitamasa/README.md
//   Note: practice/ladders/math/berlekamp-massey-kitamasa/kthtermoflinearlyrecurrentsequence.md

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

static constexpr int MOD = 998244353;

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

    Mint& operator/=(const Mint& other) {
        return *this *= other.inv();
    }
};

static Mint operator+(Mint a, const Mint& b) { return a += b; }
static Mint operator-(Mint a, const Mint& b) { return a -= b; }
static Mint operator*(Mint a, const Mint& b) { return a *= b; }
static Mint operator/(Mint a, const Mint& b) { return a /= b; }

vector<Mint> berlekamp_massey(const vector<Mint>& seq) {
    vector<Mint> c(1, Mint(1)), b(1, Mint(1));
    int l = 0;
    int m = 1;
    Mint last_discrepancy = 1;

    for (int n = 0; n < static_cast<int>(seq.size()); ++n) {
        Mint discrepancy = 0;
        for (int i = 0; i <= l; ++i) {
            discrepancy += c[i] * seq[n - i];
        }
        if (discrepancy.v == 0) {
            ++m;
            continue;
        }

        vector<Mint> old_c = c;
        Mint scale = discrepancy / last_discrepancy;
        if (static_cast<int>(c.size()) < static_cast<int>(b.size()) + m) {
            c.resize(b.size() + m);
        }
        for (int i = 0; i < static_cast<int>(b.size()); ++i) {
            c[i + m] -= scale * b[i];
        }

        if (2 * l <= n) {
            l = n + 1 - l;
            b = old_c;
            last_discrepancy = discrepancy;
            m = 1;
        } else {
            ++m;
        }
    }

    c.erase(c.begin());
    for (Mint& coeff : c) coeff = Mint() - coeff;
    return c;
}

vector<Mint> combine(const vector<Mint>& a, const vector<Mint>& b, const vector<Mint>& rec) {
    int d = static_cast<int>(rec.size());
    vector<Mint> prod(2 * d - 1);
    for (int i = 0; i < d; ++i) {
        for (int j = 0; j < d; ++j) {
            prod[i + j] += a[i] * b[j];
        }
    }
    for (int deg = 2 * d - 2; deg >= d; --deg) {
        for (int j = 1; j <= d; ++j) {
            prod[deg - j] += prod[deg] * rec[d - j];
        }
    }
    prod.resize(d);
    return prod;
}

Mint linear_recurrence_kth(const vector<Mint>& init, const vector<Mint>& rec, long long k) {
    int d = static_cast<int>(rec.size());
    assert(d > 0 && static_cast<int>(init.size()) == d);
    if (k < d) {
        return init[static_cast<int>(k)];
    }

    if (d == 1) {
        return init[0] * rec[0].pow(k);
    }

    vector<Mint> pol(d), e(d);
    pol[0] = 1;
    e[1] = 1;

    while (k > 0) {
        if (k & 1LL) {
            pol = combine(pol, e, rec);
        }
        e = combine(e, e, rec);
        k >>= 1LL;
    }

    Mint ans = 0;
    for (int i = 0; i < d; ++i) {
        ans += pol[i] * init[i];
    }
    return ans;
}

int main() {
    vector<Mint> fib_prefix = {0, 1, 1, 2, 3, 5, 8, 13};
    vector<Mint> rec = berlekamp_massey(fib_prefix);
    cout << rec.size();
    for (Mint coeff : rec) {
        cout << ' ' << coeff.v;
    }
    cout << '\n';  // 2 1 1

    vector<Mint> init = {0, 1};
    cout << linear_recurrence_kth(init, rec, 10).v << '\n';  // 55
    return 0;
}
