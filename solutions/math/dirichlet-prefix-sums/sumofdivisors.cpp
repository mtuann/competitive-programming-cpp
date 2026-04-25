#include <cstdint>
#include <iostream>

using namespace std;

const long long MOD = 1000000007LL;

long long sum_range_mod(long long l, long long r) {
    __int128 count = r - l + 1;
    __int128 total = static_cast<__int128>(l) + r;
    __int128 twice_sum = count * total;
    if (twice_sum % 2 == 0) {
        twice_sum /= 2;
    } else {
        count /= 2;
        twice_sum = count * total;
    }
    return static_cast<long long>(twice_sum % MOD);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long answer = 0;
    for (long long l = 1; l <= n; ) {
        long long q = n / l;
        long long r = n / q;
        answer = (answer + static_cast<long long>((static_cast<__int128>(q % MOD) * sum_range_mod(l, r)) % MOD)) % MOD;
        l = r + 1;
    }

    cout << answer << '\n';
    return 0;
}
