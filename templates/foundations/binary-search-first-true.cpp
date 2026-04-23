// Template: binary search first true
// Invariant:
// - l is bad
// - r is good
// - answer is in (l, r]

#include <functional>
#include <iostream>

using namespace std;

long long first_true(long long l, long long r, const function<bool(long long)> &is_good) {
    while (r - l > 1) {
        long long mid = l + (r - l) / 2;
        if (is_good(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}

int main() {
    auto is_good = [](long long x) { return x * x >= 30; };
    cout << first_true(0, 30, is_good) << '\n';
    return 0;
}
