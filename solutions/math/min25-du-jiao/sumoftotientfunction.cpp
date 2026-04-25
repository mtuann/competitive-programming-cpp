#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const long long MOD = 998244353LL;

long long norm_mod(long long x) {
    x %= MOD;
    if (x < 0) {
        x += MOD;
    }
    return x;
}

long long sum_1_to_n_mod(long long n) {
    __int128 a = n;
    __int128 b = n + 1;
    if (a % 2 == 0) {
        a /= 2;
    } else {
        b /= 2;
    }
    return static_cast<long long>((a % MOD) * (b % MOD) % MOD);
}

vector<long long> quotient_values(long long n) {
    vector<long long> vals;
    for (long long l = 1; l <= n; ) {
        long long q = n / l;
        long long r = n / q;
        vals.push_back(q);
        l = r + 1;
    }
    reverse(vals.begin(), vals.end());
    return vals;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    vector<long long> vals = quotient_values(n);
    unordered_map<long long, int> pos;
    pos.reserve(vals.size() * 2 + 1);
    for (int i = 0; i < static_cast<int>(vals.size()); ++i) {
        pos[vals[i]] = i;
    }

    vector<long long> pref_phi(vals.size(), 0);

    for (int i = 0; i < static_cast<int>(vals.size()); ++i) {
        long long x = vals[i];
        long long phi_ans = sum_1_to_n_mod(x);

        for (long long l = 2; l <= x; ) {
            long long q = x / l;
            long long r = x / q;
            long long cnt = (r - l + 1) % MOD;
            int j = pos.at(q);
            phi_ans = norm_mod(
                phi_ans - static_cast<long long>((static_cast<__int128>(cnt) * pref_phi[j]) % MOD)
            );
            l = r + 1;
        }

        pref_phi[i] = phi_ans;
    }

    cout << pref_phi.back() << '\n';
    return 0;
}
