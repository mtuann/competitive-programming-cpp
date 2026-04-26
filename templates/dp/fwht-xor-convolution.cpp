#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

static constexpr int MOD = 998244353;

struct Mint {
    int value;

    Mint(long long v = 0) {
        v %= MOD;
        if (v < 0) v += MOD;
        value = static_cast<int>(v);
    }

    Mint& operator+=(const Mint& other) {
        value += other.value;
        if (value >= MOD) value -= MOD;
        return *this;
    }

    Mint& operator-=(const Mint& other) {
        value -= other.value;
        if (value < 0) value += MOD;
        return *this;
    }

    Mint& operator*=(const Mint& other) {
        value = static_cast<int>(1LL * value * other.value % MOD);
        return *this;
    }

    friend Mint operator+(Mint a, const Mint& b) {
        a += b;
        return a;
    }

    friend Mint operator-(Mint a, const Mint& b) {
        a -= b;
        return a;
    }

    friend Mint operator*(Mint a, const Mint& b) {
        a *= b;
        return a;
    }
};

Mint mod_pow(Mint base, long long exp) {
    Mint result = 1;
    while (exp > 0) {
        if (exp & 1LL) result *= base;
        base *= base;
        exp >>= 1LL;
    }
    return result;
}

void fwht_xor(vector<Mint>& a, bool inverse) {
    const int n = static_cast<int>(a.size());
    assert(n > 0 && (n & (n - 1)) == 0);
    for (int len = 1; 2 * len <= n; len <<= 1) {
        for (int start = 0; start < n; start += 2 * len) {
            for (int offset = 0; offset < len; ++offset) {
                Mint x = a[start + offset];
                Mint y = a[start + len + offset];
                a[start + offset] = x + y;
                a[start + len + offset] = x - y;
            }
        }
    }
    if (inverse) {
        Mint inv_n = mod_pow(Mint(n), MOD - 2);
        for (Mint& x : a) x *= inv_n;
    }
}

vector<Mint> xor_convolution(vector<Mint> a, vector<Mint> b) {
    assert(a.size() == b.size());
    fwht_xor(a, false);
    fwht_xor(b, false);
    for (size_t i = 0; i < a.size(); ++i) a[i] *= b[i];
    fwht_xor(a, true);
    return a;
}

int main() {
    vector<Mint> a = {1, 2, 3, 4};
    vector<Mint> b = {4, 3, 2, 1};
    vector<Mint> c = xor_convolution(a, b);
    for (size_t i = 0; i < c.size(); ++i) {
        if (i) cout << ' ';
        cout << c[i].value;
    }
    cout << '\n';
    return 0;
}
