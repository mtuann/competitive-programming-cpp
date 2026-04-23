// Template: Fenwick tree / BIT
// Supports point updates and prefix sums.

#include <iostream>
#include <vector>

using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;

    explicit Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, long long delta) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += delta;
        }
    }

    long long sum_prefix(int idx) const {
        long long result = 0;
        for (; idx > 0; idx -= idx & -idx) {
            result += bit[idx];
        }
        return result;
    }

    long long sum_range(int l, int r) const {
        return sum_prefix(r) - sum_prefix(l - 1);
    }
};

int main() {
    Fenwick fw(5);
    fw.add(1, 3);
    fw.add(3, 4);
    fw.add(5, 2);
    cout << fw.sum_range(2, 5) << '\n';
    return 0;
}
