#include <iostream>
#include <vector>

using namespace std;

struct XorBasis {
    static constexpr int MAX_BIT = 60;
    long long basis[MAX_BIT + 1] = {};

    void insert(long long x) {
        for (int bit = MAX_BIT; bit >= 0; --bit) {
            if (((x >> bit) & 1LL) == 0) {
                continue;
            }
            if (basis[bit] == 0) {
                basis[bit] = x;
                return;
            }
            x ^= basis[bit];
        }
    }

    long long max_xor() const {
        long long ans = 0;
        for (int bit = MAX_BIT; bit >= 0; --bit) {
            if ((ans ^ basis[bit]) > ans) {
                ans ^= basis[bit];
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    XorBasis basis;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        basis.insert(x);
    }

    cout << basis.max_xor() << '\n';
    return 0;
}
