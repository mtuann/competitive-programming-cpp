#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct PersistentSegTree {
    struct Node {
        long long sum = 0;
        int left = -1;
        int right = -1;
    };

    int n;
    vector<Node> nodes;

    explicit PersistentSegTree(int n) : n(n) {
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (long long& x : a) {
        cin >> x;
    }

    PersistentSegTree pst(n);
    vector<int> roots;
    roots.push_back(pst.build(a));

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, pos;
            long long value;
            cin >> k >> pos >> value;
            --k;
            --pos;
            roots[k] = pst.point_set(roots[k], pos, value);
        } else if (type == 2) {
            int k, l, r;
            cin >> k >> l >> r;
            --k;
            --l;
            cout << pst.range_sum(roots[k], l, r) << '\n';
        } else {
            int k;
            cin >> k;
            --k;
            roots.push_back(roots[k]);
        }
    }

    return 0;
}
