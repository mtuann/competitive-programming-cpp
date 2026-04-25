// Template: persistent segment tree (point set, range sum)
// Signal: old versions stay queryable, copy operations are cheap, and one point assignment
// creates a new version with range-sum queries on any stored root.
// Assumes: zero-based half-open intervals [l, r); point assignment only; sums fit in long long.
// Exposes: PersistentSegTreePointSetSum with build(a), point_set(root, idx, value), and range_sum(root, l, r).
// Complexity: O(n) build, O(log n) new nodes per update, O(log n) query.
// Main trap: mutating a shared node from an old version instead of cloning the path first.
// Links:
//   Topic: topics/data-structures/persistent-data-structures/README.md
//   Note: practice/ladders/data-structures/persistent-data-structures/rangequeriesandcopies.md

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct PersistentSegTreePointSetSum {
    struct Node {
        long long sum = 0;
        int left = -1;
        int right = -1;
    };

    int n;
    vector<Node> nodes;

    explicit PersistentSegTreePointSetSum(int n) : n(n) {
        nodes.reserve(max(1, 4 * n));
    }

    int build(const vector<long long>& a) {
        nodes.clear();
        if (n == 0) {
            nodes.push_back(Node());
            return 0;
        }
        return build(0, n, a);
    }

    int point_set(int root, int idx, long long value) {
        return point_set(root, 0, n, idx, value);
    }

    long long range_sum(int root, int l, int r) const {
        return range_sum(root, 0, n, l, r);
    }

private:
    int new_node(const Node& node) {
        nodes.push_back(node);
        return static_cast<int>(nodes.size()) - 1;
    }

    int build(int l, int r, const vector<long long>& a) {
        int cur = new_node(Node());
        if (r - l == 1) {
            nodes[cur].sum = a[l];
            return cur;
        }
        int m = l + (r - l) / 2;
        nodes[cur].left = build(l, m, a);
        nodes[cur].right = build(m, r, a);
        pull(cur);
        return cur;
    }

    int point_set(int root, int l, int r, int idx, long long value) {
        int cur = new_node(nodes[root]);
        if (r - l == 1) {
            nodes[cur].sum = value;
            return cur;
        }
        int m = l + (r - l) / 2;
        if (idx < m) {
            nodes[cur].left = point_set(nodes[root].left, l, m, idx, value);
        } else {
            nodes[cur].right = point_set(nodes[root].right, m, r, idx, value);
        }
        pull(cur);
        return cur;
    }

    long long range_sum(int root, int l, int r, int ql, int qr) const {
        if (qr <= l || r <= ql) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            return nodes[root].sum;
        }
        int m = l + (r - l) / 2;
        return range_sum(nodes[root].left, l, m, ql, qr) +
               range_sum(nodes[root].right, m, r, ql, qr);
    }

    void pull(int cur) {
        nodes[cur].sum = nodes[nodes[cur].left].sum + nodes[nodes[cur].right].sum;
    }
};

int main() {
    vector<long long> a = {1, 2, 3, 4};
    PersistentSegTreePointSetSum pst(static_cast<int>(a.size()));
    int root0 = pst.build(a);
    int root1 = pst.point_set(root0, 1, 10);
    cout << pst.range_sum(root0, 0, 4) << '\n';
    cout << pst.range_sum(root1, 0, 4) << '\n';
    return 0;
}
