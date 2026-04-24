// Template: prefix sum 1D
// Use when the array is static and you need many range sums.
// Signal: many static range queries, no updates.
// Assumes: one stable indexing convention and pref[0] = 0.
// Exposes: PrefixSum1D with sum(l, r).
// Complexity: O(n) build, O(1) range query.
// Main trap: mixing inclusive and half-open interval formulas.
// Links:
//   Topic: topics/foundations/patterns/prefix-sums/README.md
//   Note: practice/ladders/foundations/prefix-sums/staticrangesumqueries.md

#include <iostream>
#include <vector>

using namespace std;

struct PrefixSum1D {
    vector<long long> pref;

    explicit PrefixSum1D(const vector<long long> &a) : pref(a.size() + 1, 0) {
        for (int i = 0; i < static_cast<int>(a.size()); ++i) {
            pref[i + 1] = pref[i] + a[i];
        }
    }

    long long sum(int l, int r) const {
        return pref[r + 1] - pref[l];
    }
};

int main() {
    vector<long long> a = {3, 1, 4, 1, 5};
    PrefixSum1D pref(a);
    cout << pref.sum(1, 3) << '\n';
    return 0;
}
