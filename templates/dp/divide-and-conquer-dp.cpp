// Template: Divide and conquer DP row optimization
// Signal: one partition-DP row of the form cur[i] = min(prev[k] + cost(k+1, i))
// with monotone optimal split indices.
// Assumes: cost(l, r) is O(1), segment endpoints are 1-indexed inclusive, and
// the caller has already proved or imported monotone argmins for this row.
// Exposes: compute_dnc_row(left, right, opt_left, opt_right, prev, cur, cost).
// Complexity: O(n log n) to compute one row over n states.
// Main trap: using the helper without monotone-opt evidence, or mixing cost(k, i)
// versus cost(k+1, i) conventions.
// Links:
//   Topic: topics/dp/divide-and-conquer-dp/README.md
//   Note: practice/ladders/dp/divide-and-conquer-dp/cielandgondolas.md

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

constexpr long long INF64 = numeric_limits<long long>::max() / 4;

template <class Cost>
void compute_dnc_row(int left, int right, int opt_left, int opt_right,
                     const vector<long long>& prev, vector<long long>& cur,
                     const Cost& cost) {
    if (left > right) {
        return;
    }

    int mid = (left + right) >> 1;
    pair<long long, int> best = {INF64, -1};
    int upper = min(mid - 1, opt_right);

    for (int k = opt_left; k <= upper; ++k) {
        long long cand = prev[k] + cost(k + 1, mid);
        if (cand < best.first) {
            best = {cand, k};
        }
    }

    cur[mid] = best.first;
    compute_dnc_row(left, mid - 1, opt_left, best.second, prev, cur, cost);
    compute_dnc_row(mid + 1, right, best.second, opt_right, prev, cur, cost);
}

int main() {
    const int n = 5;
    auto cost = [](int l, int r) -> long long {
        long long len = r - l + 1;
        return len * len;
    };

    vector<long long> prev(n + 1, INF64), cur(n + 1, INF64);
    prev[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prev[i] = cost(1, i);
    }

    compute_dnc_row(1, n, 0, n - 1, prev, cur, cost);
    for (int i = 1; i <= n; ++i) {
        cout << cur[i] << (i == n ? '\n' : ' ');
    }
    return 0;
}
