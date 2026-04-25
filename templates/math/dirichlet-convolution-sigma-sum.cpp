// Template: Dirichlet convolution prefix sums via summatory sigma
// Signal: one arithmetic-function prefix sum opens directly into a divisor-side sum weighted by floor(n / d).
// Assumes: the first exact route is sigma = 1 * id, quotient blocks fit in O(sqrt(n)), and arithmetic uses __int128-safe products.
// Exposes: norm_mod(x, mod), sum_range_mod(l, r, mod), and sum_of_divisors_prefix(n, mod).
// Complexity: O(sqrt(n)) quotient blocks.
// Main trap: jumping to floor-grouping before deriving the exact divisor-side expansion.
// Links:
//   Topic: topics/math/dirichlet-prefix-sums/README.md
//   Note: practice/ladders/math/dirichlet-prefix-sums/sumofdivisors.md

#include <cstdint>
#include <iostream>

using namespace std;

long long norm_mod(long long x, long long mod) {
    x %= mod;
    if (x < 0) {
        x += mod;
    }
    return x;
}

long long sum_range_mod(long long l, long long r, long long mod) {
    if (l > r) {
        return 0;
    }
    __int128 count = r - l + 1;
    __int128 total = static_cast<__int128>(l) + r;
    __int128 twice_sum = count * total;
    if (twice_sum % 2 == 0) {
        twice_sum /= 2;
    } else {
        count /= 2;
        twice_sum = count * total;
    }
    return static_cast<long long>(twice_sum % mod);
}

long long sum_of_divisors_prefix(long long n, long long mod) {
    long long answer = 0;
    for (long long l = 1; l <= n; ) {
        long long q = n / l;
        long long r = n / q;
        long long block_sum = sum_range_mod(l, r, mod);
        answer = (answer + static_cast<long long>((static_cast<__int128>(q % mod) * block_sum) % mod)) % mod;
        l = r + 1;
    }
    return answer;
}

int main() {
    const long long MOD = 1000000007LL;
    for (long long n : {1LL, 4LL, 7LL}) {
        cout << sum_of_divisors_prefix(n, MOD) << '\n';
    }
    return 0;
}
