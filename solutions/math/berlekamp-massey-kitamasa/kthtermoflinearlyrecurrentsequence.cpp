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
};

static Mint operator+(Mint a, const Mint& b) { return a += b; }
static Mint operator-(Mint a, const Mint& b) { return a -= b; }
static Mint operator*(Mint a, const Mint& b) { return a *= b; }

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
    if (k < d) {
        return init[static_cast<int>(k)];
    }
    if (d == 1) {
        Mint ans = init[0];
        Mint base = rec[0];
        while (k > 0) {
            if (k & 1LL) ans *= base;
            base *= base;
            k >>= 1LL;
        }
        return ans;
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int d;
    long long k;
    cin >> d >> k;

    vector<Mint> init(d), rec(d);
    for (int i = 0; i < d; ++i) {
        long long x;
        cin >> x;
        init[i] = Mint(x);
    }
    for (int i = 0; i < d; ++i) {
        long long x;
        cin >> x;
        rec[i] = Mint(x);
    }

    cout << linear_recurrence_kth(init, rec, k).v << '\n';
    return 0;
}
