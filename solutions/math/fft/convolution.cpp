// Problem: Convolution
// Judge: AtCoder Library Practice Contest
// Source URL: https://atcoder.jp/contests/practice2/tasks/practice2_f
// Topic: NTT, exact modular convolution
// Idea: use iterative radix-2 NTT under modulus 998244353, multiply pointwise,
// inverse transform, and print the first n + m - 1 coefficients.

#include <iostream>
#include <vector>

using namespace std;

static constexpr int MOD = 998244353;
static constexpr int PRIMITIVE_ROOT = 3;

static int mod_pow(int a, long long e) {
    long long result = 1;
    long long base = a;
    while (e > 0) {
        if (e & 1LL) result = result * base % MOD;
        base = base * base % MOD;
        e >>= 1LL;
    }
    return static_cast<int>(result);
}

static void ntt(vector<int>& a, bool invert) {
    int n = static_cast<int>(a.size());

    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = mod_pow(PRIMITIVE_ROOT, (MOD - 1) / len);
        if (invert) {
            wlen = mod_pow(wlen, MOD - 2);
        }
        for (int i = 0; i < n; i += len) {
            long long w = 1;
            for (int j = 0; j < len / 2; ++j) {
                int u = a[i + j];
                int v = static_cast<int>(1LL * a[i + j + len / 2] * w % MOD);
                a[i + j] = u + v;
                if (a[i + j] >= MOD) a[i + j] -= MOD;
                a[i + j + len / 2] = u - v;
                if (a[i + j + len / 2] < 0) a[i + j + len / 2] += MOD;
                w = w * wlen % MOD;
            }
        }
    }

    if (invert) {
        int inv_n = mod_pow(n, MOD - 2);
        for (int& x : a) {
            x = static_cast<int>(1LL * x * inv_n % MOD);
        }
    }
}

static vector<int> convolution(vector<int> a, vector<int> b) {
    int result_size = static_cast<int>(a.size() + b.size() - 1);
    int n = 1;
    while (n < result_size) {
        n <<= 1;
    }
    a.resize(n);
    b.resize(n);

    ntt(a, false);
    ntt(b, false);
    for (int i = 0; i < n; ++i) {
        a[i] = static_cast<int>(1LL * a[i] * b[i] % MOD);
    }
    ntt(a, true);
    a.resize(result_size);
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int& x : a) {
        cin >> x;
    }
    for (int& x : b) {
        cin >> x;
    }

    vector<int> c = convolution(a, b);
    for (int i = 0; i < static_cast<int>(c.size()); ++i) {
        cout << c[i] << (i + 1 == static_cast<int>(c.size()) ? '\n' : ' ');
    }
    return 0;
}
