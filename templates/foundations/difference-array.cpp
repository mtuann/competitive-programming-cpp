// Template: difference array
// Use for many offline range additions followed by one final reconstruction pass.
// Signal: many range updates, but you only need the final array after all updates finish.
// Assumes: offline setting; range effects start at l and stop after r.
// Exposes: one endpoint-update pattern plus one final prefix reconstruction pass.
// Complexity: O(1) per update, O(n) final rebuild.
// Main trap: forgetting the r + 1 boundary check or using this when online queries are required.
// Links:
//   Topic: topics/foundations/patterns/difference-arrays/README.md
//   Note: practice/ladders/foundations/difference-arrays/rangeupdatequeries.md

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 5;
    vector<long long> diff(n + 1, 0);

    auto range_add = [&](int l, int r, long long delta) {
        diff[l] += delta;
        if (r + 1 < n) {
            diff[r + 1] -= delta;
        }
    };

    range_add(1, 3, 2);
    range_add(0, 2, 1);

    vector<long long> a(n, 0);
    long long running = 0;
    for (int i = 0; i < n; ++i) {
        running += diff[i];
        a[i] = running;
        cout << a[i] << " \n"[i + 1 == n];
    }
    return 0;
}
