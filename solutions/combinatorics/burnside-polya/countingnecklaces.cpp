#include <iostream>
#include <numeric>

using namespace std;

using int64 = long long;

static constexpr int MOD = 1'000'000'007;

int64 mod_pow(int64 base, int64 exp) {
    base %= MOD;
    int64 result = 1;
    while (exp > 0) {
        if (exp & 1LL) {
            result = result * base % MOD;
        }
        base = base * base % MOD;
        exp >>= 1LL;
    }
    return result;
}

int64 mod_inv(int64 x) {
    return mod_pow(x, MOD - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64 n, m;
    cin >> n >> m;

    int64 sum = 0;
    for (int64 rotation = 0; rotation < n; ++rotation) {
        sum += mod_pow(m, std::gcd(n, rotation));
        if (sum >= MOD) {
            sum -= MOD;
        }
    }

    cout << sum * mod_inv(n % MOD) % MOD << '\n';
    return 0;
}
