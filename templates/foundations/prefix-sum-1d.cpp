// Template: prefix sum 1D
// Use when the array is static and you need many range sums.

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
