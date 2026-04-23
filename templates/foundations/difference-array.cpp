// Template: difference array
// Use for many offline range additions followed by one final reconstruction pass.

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
