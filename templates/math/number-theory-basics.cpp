// Template: number theory basics
// Signal: gcd/lcm, SPF sieve, and factorization are the real primitives.
// Assumes: preprocessing up to n is acceptable and the task is integer-arithmetic, not modular-combinatorics heavy.
// Exposes: gcd_ll, lcm_ll, build_spf(n), factorize_with_spf(x, spf).
// Complexity: O(n log log n) style SPF build here, then O(log x) factorization by SPF.
// Main trap: forgetting lcm can overflow before division if you reorder the formula.
// Links:
//   Topic: topics/math/number-theory-basics/README.md
//   Note: practice/ladders/math/number-theory-basics/countingdivisors.md

#include <iostream>
#include <vector>

using namespace std;

long long gcd_ll(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long lcm_ll(long long a, long long b) {
    return a / gcd_ll(a, b) * b;
}

vector<int> build_spf(int n) {
    vector<int> spf(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            if (1LL * i * i <= n) {
                for (int j = i * i; j <= n; j += i) {
                    if (spf[j] == 0) {
                        spf[j] = i;
                    }
                }
            }
        }
    }
    return spf;
}

vector<pair<int, int>> factorize_with_spf(int x, const vector<int> &spf) {
    vector<pair<int, int>> factors;
    while (x > 1) {
        int p = spf[x];
        int cnt = 0;
        while (x % p == 0) {
            x /= p;
            ++cnt;
        }
        factors.push_back({p, cnt});
    }
    return factors;
}

int main() {
    cout << gcd_ll(84, 30) << '\n';
    cout << lcm_ll(21, 6) << '\n';

    vector<int> spf = build_spf(100);
    vector<pair<int, int>> f = factorize_with_spf(84, spf);
    for (const auto &item : f) {
        cout << item.first << '^' << item.second << ' ';
    }
    cout << '\n';
    return 0;
}
