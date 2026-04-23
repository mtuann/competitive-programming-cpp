// Template: two pointers / sliding window
// Assumption: all values are nonnegative.
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
