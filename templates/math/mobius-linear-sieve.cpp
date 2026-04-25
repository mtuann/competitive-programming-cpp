// Template: Mobius / multiplicative counting
// Signal: gcd/divisor counting over all d <= MAX where inclusion-exclusion lives on divisor structure.
// Assumes: all values are positive and MAX is small enough for O(MAX log MAX) multiples loops.
// Exposes: build_mobius(max_v), count_divisible_multiples(freq), count_coprime_pairs(values).
// Complexity: O(MAX) for mu with a linear sieve, then O(MAX log MAX) for divisor-frequency aggregation.
// Main trap: using cnt[d] * cnt[d] instead of C(cnt[d], 2) for unordered pair counts.
// Links:
//   Topic: topics/math/mobius-multiplicative/README.md
//   Note: practice/ladders/math/mobius-multiplicative/countingcoprimepairs.md

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> build_mobius(int n) {
    vector<int> mu(n + 1, 0);
    vector<int> lp(n + 1, 0);
    vector<int> primes;
    mu[1] = 1;

    for (int i = 2; i <= n; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back(i);
            mu[i] = -1;
        }
        for (int p : primes) {
            long long v = 1LL * i * p;
            if (v > n) {
                break;
            }
            lp[v] = p;
            if (i % p == 0) {
                mu[v] = 0;
                break;
            }
            mu[v] = -mu[i];
        }
    }

    return mu;
}

vector<int> count_divisible_multiples(const vector<int>& freq) {
    int max_v = static_cast<int>(freq.size()) - 1;
    vector<int> cnt(max_v + 1, 0);
    for (int d = 1; d <= max_v; ++d) {
        for (int multiple = d; multiple <= max_v; multiple += d) {
            cnt[d] += freq[multiple];
        }
    }
    return cnt;
}

long long count_coprime_pairs(const vector<int>& values) {
    int max_v = *max_element(values.begin(), values.end());
    vector<int> freq(max_v + 1, 0);
    for (int x : values) {
        ++freq[x];
    }

    vector<int> mu = build_mobius(max_v);
    vector<int> cnt = count_divisible_multiples(freq);

    long long answer = 0;
    for (int d = 1; d <= max_v; ++d) {
        long long pairs = 1LL * cnt[d] * (cnt[d] - 1) / 2;
        answer += 1LL * mu[d] * pairs;
    }
    return answer;
}

int main() {
    vector<int> values = {5, 4, 20, 1, 16, 17, 5, 15};
    cout << count_coprime_pairs(values) << '\n';
    return 0;
}
