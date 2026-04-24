#include <iostream>
#include <vector>

using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;

    explicit Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int index, long long delta) {
        for (; index <= n; index += index & -index) {
            bit[index] += delta;
        }
    }

    long long sum(int index) const {
        long long result = 0;
        for (; index > 0; index -= index & -index) {
            result += bit[index];
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    Fenwick bit(n);
    long long previous = 0;
    for (int i = 1; i <= n; ++i) {
        long long value;
        cin >> value;
        bit.add(i, value - previous);
        previous = value;
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int left, right;
            long long delta;
            cin >> left >> right >> delta;
            bit.add(left, delta);
            if (right + 1 <= n) {
                bit.add(right + 1, -delta);
            }
        } else {
            int index;
            cin >> index;
            cout << bit.sum(index) << '\n';
        }
    }

    return 0;
}
