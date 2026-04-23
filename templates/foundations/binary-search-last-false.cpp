// Template: binary search last false
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
