// Problem: Prime Multiples
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/2185
// Topic: inclusion-exclusion, subset enumeration, overflow-safe products
// Idea: for each non-empty subset of the primes, count numbers divisible by the
// product of that subset. Add odd-sized subsets and subtract even-sized ones.
// Guard multiplication with product > n / next_prime to avoid overflow.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    int k;
    cin >> n >> k;

    vector<long long> primes(k);
    for (long long& x : primes) {
        cin >> x;
    }

    long long answer = 0;
    for (int mask = 1; mask < (1 << k); ++mask) {
        long long product = 1;
        bool overflow = false;
        int bits = 0;

        for (int i = 0; i < k; ++i) {
            if (((mask >> i) & 1) == 0) {
                continue;
            }
            ++bits;
            if (product > n / primes[i]) {
                overflow = true;
                break;
            }
            product *= primes[i];
        }

        if (overflow) {
            continue;
        }

        long long contribution = n / product;
        if (bits & 1) {
            answer += contribution;
        } else {
            answer -= contribution;
        }
    }

    cout << answer << '\n';
    return 0;
}
