#include <cassert>
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

// Counts k-colorings of an n-cycle up to rotation only.
// Exact route: Burnside over C_n using fix(rotation r) = k^(gcd(n, r)).
// Contract: fixed prime MOD, and n % MOD != 0 so averaging by |C_n| is legal.
int64 count_cyclic_necklaces(int64 n, int64 colors) {
    assert(n > 0);
    assert(n % MOD != 0);

    int64 sum = 0;
    for (int64 rotation = 0; rotation < n; ++rotation) {
        sum += mod_pow(colors, std::gcd(n, rotation));
        if (sum >= MOD) {
            sum -= MOD;
        }
    }
    return sum * mod_inv(n % MOD) % MOD;
}

int main() {
    cout << count_cyclic_necklaces(4, 3) << '\n';  // 24
    cout << count_cyclic_necklaces(3, 2) << '\n';  // 4
    return 0;
}
