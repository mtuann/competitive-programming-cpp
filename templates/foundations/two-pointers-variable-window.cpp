// Template: two pointers / sliding window
// Signal: one window boundary grows, the other only moves forward to restore validity.
// Assumption: all values are nonnegative.
// Exposes: one variable-window loop with l, r, current_sum, and best.
// Complexity: O(n) pointer movement after O(1) summary updates.
// Main trap: applying the same loop when negative values break monotonicity.
// Links:
//   Topic: topics/foundations/patterns/two-pointers/README.md
//   Note: practice/ladders/foundations/two-pointers/apartments.md
//   Note: practice/ladders/foundations/two-pointers/sumoftwovalues.md
// Example task: longest subarray with sum <= limit.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> a = {2, 1, 3, 1, 1, 2};
    long long limit = 5;

    int best = 0;
    long long current_sum = 0;
    int l = 0;

    for (int r = 0; r < static_cast<int>(a.size()); ++r) {
        current_sum += a[r];
        while (current_sum > limit) {
            current_sum -= a[l];
            ++l;
        }
        best = max(best, r - l + 1);
    }

    cout << best << '\n';
    return 0;
}
