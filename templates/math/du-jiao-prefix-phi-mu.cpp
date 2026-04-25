// Template: Du Jiao prefix sums for phi / mu on one quotient set
// Signal: one huge prefix sum of phi or mu where direct sieving to n is too large, but the repeated subproblems are floor(n / i).
// Assumes: one large query n, one modulus, and the first exact route is quotient-set DP for prefix_phi / prefix_mu rather than full Min_25.
// Exposes: norm_mod(x, mod), sum_1_to_n_mod(n, mod), quotient_values(n), and struct DujiaoPrefixTables with sum_phi(x) / sum_mu(x) for x in Q_n.
// Complexity: sublinear in n on the quotient set Q_n; this starter is the clean introductory route, not the most optimized variant.
// Main trap: overclaiming this starter as a full Min_25 implementation, or forgetting that the block coefficient is (r - l + 1).
// Links:
//   Topic: topics/math/min25-du-jiao/README.md
//   Note: practice/ladders/math/min25-du-jiao/sumoftotientfunction.md

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

long long norm_mod(long long x, long long mod) {
    x %= mod;
    if (x < 0) {
        x += mod;
    }
    return x;
}

long long sum_1_to_n_mod(long long n, long long mod) {
    __int128 a = n;
    __int128 b = n + 1;
    if (a % 2 == 0) {
        a /= 2;
    } else {
        b /= 2;
    }
    return static_cast<long long>((a % mod) * (b % mod) % mod);
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

struct DujiaoPrefixTables {
    long long n;
    long long mod;
    vector<long long> vals;
    unordered_map<long long, int> pos;
    vector<long long> pref_phi;
    vector<long long> pref_mu;

    DujiaoPrefixTables(long long n, long long mod)
        : n(n), mod(mod), vals(quotient_values(n)), pref_phi(vals.size(), 0), pref_mu(vals.size(), 0) {
        pos.reserve(vals.size() * 2 + 1);
        for (int i = 0; i < static_cast<int>(vals.size()); ++i) {
            pos[vals[i]] = i;
        }
        build();
    }

    void build() {
        for (int i = 0; i < static_cast<int>(vals.size()); ++i) {
            long long x = vals[i];
            long long mu_ans = 1 % mod;
            long long phi_ans = sum_1_to_n_mod(x, mod);

            for (long long l = 2; l <= x; ) {
                long long q = x / l;
                long long r = x / q;
                long long cnt = (r - l + 1) % mod;
                int j = pos.at(q);
                mu_ans = norm_mod(
                    mu_ans - static_cast<long long>((static_cast<__int128>(cnt) * pref_mu[j]) % mod),
                    mod
                );
                phi_ans = norm_mod(
                    phi_ans - static_cast<long long>((static_cast<__int128>(cnt) * pref_phi[j]) % mod),
                    mod
                );
                l = r + 1;
            }

            pref_mu[i] = mu_ans;
            pref_phi[i] = phi_ans;
        }
    }

    long long sum_phi(long long x) const {
        auto it = pos.find(x);
        assert(it != pos.end());
        return pref_phi[it->second];
    }

    long long sum_mu(long long x) const {
        auto it = pos.find(x);
        assert(it != pos.end());
        return pref_mu[it->second];
    }
};

int main() {
    const long long MOD = 998244353LL;
    DujiaoPrefixTables table(10, MOD);
    cout << table.sum_phi(5) << '\n';
    cout << table.sum_phi(10) << '\n';
    return 0;
}
