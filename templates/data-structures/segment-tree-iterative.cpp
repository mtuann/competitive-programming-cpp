// Template: iterative segment tree
// Signal: point updates with range sums on a mutable array.
// Assumes: values are long long sums, identity is 0, and n is the leaf base used by the iterative layout.
// Exposes: SegTree with build(a), set_value(pos, value), query(l, r).
// Complexity: O(n) build, O(log n) point update, O(log n) range query.
// Main trap: forgetting the template query is half-open [l, r), then mixing it with inclusive problem statements.
// Links:
//   Topic: topics/data-structures/segment-tree/README.md
//   Note: practice/ladders/data-structures/segment-tree/dynamicrangesumqueries.md

#include <iostream>
#include <vector>

using namespace std;

struct SegTree {
    int n;
    vector<long long> tree;

    explicit SegTree(int n) : n(n), tree(2 * n, 0) {}

    void build(const vector<long long> &a) {
        for (int i = 0; i < n; ++i) {
            tree[n + i] = a[i];
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        }
    }

    void set_value(int pos, long long value) {
        pos += n;
        tree[pos] = value;
        for (pos >>= 1; pos > 0; pos >>= 1) {
            tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
        }
    }

    long long query(int l, int r) const {
        long long result = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                result += tree[l++];
            }
            if (r & 1) {
                result += tree[--r];
            }
        }
        return result;
    }
};

int main() {
    vector<long long> a = {1, 2, 3, 4};
    SegTree st(static_cast<int>(a.size()));
    st.build(a);
    cout << st.query(1, 4) << '\n';
    st.set_value(2, 10);
    cout << st.query(1, 4) << '\n';
    return 0;
}
