// Template: binary search last false
// Signal: monotone predicate, want the last infeasible or last bad answer.
// Assumes:
// - l is bad
// - r is good
// - answer is the last bad point before r
// Exposes: last_false(l, r, is_good).
// Complexity: O(log range) predicate calls.
// Main trap: mixing this variant with first-true semantics and returning the wrong endpoint.
// Links:
//   Topic: topics/foundations/patterns/binary-search/README.md
//   Note: practice/ladders/foundations/binary-search/factorymachines.md
// Invariant:
// - l is bad
// - r is good
// - answer is the last bad point before r

#include <functional>
#include <iostream>

using namespace std;

long long last_false(long long l, long long r, const function<bool(long long)> &is_good) {
    while (r - l > 1) {
        long long mid = l + (r - l) / 2;
        if (is_good(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return l;
}

int main() {
    auto is_good = [](long long x) { return x * x >= 30; };
    cout << last_false(0, 30, is_good) << '\n';
    return 0;
}
