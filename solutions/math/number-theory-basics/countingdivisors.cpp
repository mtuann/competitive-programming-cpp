// Problem: Counting Divisors
// Judge: CSES
// Source URL: https://cses.fi/problemset/task/1713
// Topic: divisor counting, sieve preprocessing
// Idea: every divisor d contributes once to each multiple of d. Precompute the
// divisor counts for all values up to 1e6, then answer each query in O(1).

#include <iostream>
#include <vector>

using namespace std;

static constexpr int MAX_X = 1'000'000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> divisor_count(MAX_X + 1, 0);
    for (int d = 1; d <= MAX_X; ++d) {
        for (int multiple = d; multiple <= MAX_X; multiple += d) {
            ++divisor_count[multiple];
        }
    }

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << divisor_count[x] << '\n';
    }
    return 0;
}
