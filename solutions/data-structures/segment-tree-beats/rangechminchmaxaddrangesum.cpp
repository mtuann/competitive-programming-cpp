#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct SegmentTreeBeats {
    static constexpr long long INF = (1LL << 60);

    struct Node {
        long long sum = 0;
        long long max1 = -INF, max2 = -INF;
        int maxc = 0;
        long long min1 = INF, min2 = INF;
        int minc = 0;
        long long add = 0;
    };

    int n = 0;
    vector<Node> st;

    explicit SegmentTreeBeats(const vector<long long>& a) {
        n = static_cast<int>(a.size());
        st.assign(4 * max(1, n), Node());
        if (n > 0) {
            build(1, 0, n, a);
        }
    }

    void range_chmin(int l, int r, long long x) {
        if (l < r) {
            range_chmin(1, 0, n, l, r, x);
        }
    }

    void range_chmax(int l, int r, long long x) {
        if (l < r) {
            range_chmax(1, 0, n, l, r, x);
        }
    }

    void range_add(int l, int r, long long x) {
        if (l < r) {
            range_add(1, 0, n, l, r, x);
        }
    }

    long long range_sum(int l, int r) {
        if (l >= r) {
            return 0;
        }
        return range_sum(1, 0, n, l, r);
    }

private:
    static Node make_leaf(long long x) {
        Node node;
        node.sum = x;
        node.max1 = node.min1 = x;
        node.max2 = -INF;
        node.min2 = INF;
        node.maxc = node.minc = 1;
        return node;
    }

    void build(int p, int l, int r, const vector<long long>& a) {
        if (r - l == 1) {
            st[p] = make_leaf(a[l]);
            return;
        }
        int m = (l + r) / 2;
        build(p * 2, l, m, a);
        build(p * 2 + 1, m, r, a);
        pull(p);
    }

    void pull(int p) {
        const Node& a = st[p * 2];
        const Node& b = st[p * 2 + 1];
        Node node;
        node.sum = a.sum + b.sum;

        if (a.max1 > b.max1) {
            node.max1 = a.max1;
            node.maxc = a.maxc;
            node.max2 = max(a.max2, b.max1);
        } else if (a.max1 < b.max1) {
            node.max1 = b.max1;
            node.maxc = b.maxc;
            node.max2 = max(a.max1, b.max2);
        } else {
            node.max1 = a.max1;
            node.maxc = a.maxc + b.maxc;
            node.max2 = max(a.max2, b.max2);
        }

        if (a.min1 < b.min1) {
            node.min1 = a.min1;
            node.minc = a.minc;
            node.min2 = min(a.min2, b.min1);
        } else if (a.min1 > b.min1) {
            node.min1 = b.min1;
            node.minc = b.minc;
            node.min2 = min(a.min1, b.min2);
        } else {
            node.min1 = a.min1;
            node.minc = a.minc + b.minc;
            node.min2 = min(a.min2, b.min2);
        }

        st[p] = node;
    }

    void apply_add(int p, int len, long long x) {
        Node& node = st[p];
        node.sum += x * len;
        node.max1 += x;
        if (node.max2 != -INF) {
            node.max2 += x;
        }
        node.min1 += x;
        if (node.min2 != INF) {
            node.min2 += x;
        }
        node.add += x;
    }

    void apply_chmin(int p, long long x) {
        Node& node = st[p];
        if (node.max1 <= x) {
            return;
        }
        node.sum += (x - node.max1) * node.maxc;
        if (node.min1 == node.max1) {
            node.min1 = x;
        } else if (node.min2 == node.max1) {
            node.min2 = x;
        }
        node.max1 = x;
    }

    void apply_chmax(int p, long long x) {
        Node& node = st[p];
        if (node.min1 >= x) {
            return;
        }
        node.sum += (x - node.min1) * node.minc;
        if (node.max1 == node.min1) {
            node.max1 = x;
        } else if (node.max2 == node.min1) {
            node.max2 = x;
        }
        node.min1 = x;
    }

    void push(int p, int l, int r) {
        if (r - l == 1) {
            st[p].add = 0;
            return;
        }

        int m = (l + r) / 2;
        if (st[p].add != 0) {
            apply_add(p * 2, m - l, st[p].add);
            apply_add(p * 2 + 1, r - m, st[p].add);
            st[p].add = 0;
        }

        if (st[p * 2].max1 > st[p].max1) {
            apply_chmin(p * 2, st[p].max1);
        }
        if (st[p * 2 + 1].max1 > st[p].max1) {
            apply_chmin(p * 2 + 1, st[p].max1);
        }
        if (st[p * 2].min1 < st[p].min1) {
            apply_chmax(p * 2, st[p].min1);
        }
        if (st[p * 2 + 1].min1 < st[p].min1) {
            apply_chmax(p * 2 + 1, st[p].min1);
        }
    }

    void range_chmin(int p, int l, int r, int ql, int qr, long long x) {
        if (qr <= l || r <= ql || st[p].max1 <= x) {
            return;
        }
        if (ql <= l && r <= qr && st[p].max2 < x) {
            apply_chmin(p, x);
            return;
        }
        push(p, l, r);
        int m = (l + r) / 2;
        range_chmin(p * 2, l, m, ql, qr, x);
        range_chmin(p * 2 + 1, m, r, ql, qr, x);
        pull(p);
    }

    void range_chmax(int p, int l, int r, int ql, int qr, long long x) {
        if (qr <= l || r <= ql || st[p].min1 >= x) {
            return;
        }
        if (ql <= l && r <= qr && st[p].min2 > x) {
            apply_chmax(p, x);
            return;
        }
        push(p, l, r);
        int m = (l + r) / 2;
        range_chmax(p * 2, l, m, ql, qr, x);
        range_chmax(p * 2 + 1, m, r, ql, qr, x);
        pull(p);
    }

    void range_add(int p, int l, int r, int ql, int qr, long long x) {
        if (qr <= l || r <= ql) {
            return;
        }
        if (ql <= l && r <= qr) {
            apply_add(p, r - l, x);
            return;
        }
        push(p, l, r);
        int m = (l + r) / 2;
        range_add(p * 2, l, m, ql, qr, x);
        range_add(p * 2 + 1, m, r, ql, qr, x);
        pull(p);
    }

    long long range_sum(int p, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            return st[p].sum;
        }
        push(p, l, r);
        int m = (l + r) / 2;
        return range_sum(p * 2, l, m, ql, qr) +
               range_sum(p * 2 + 1, m, r, ql, qr);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    SegmentTreeBeats st(a);
    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 3) {
            cout << st.range_sum(l, r) << '\n';
            continue;
        }
        long long x;
        cin >> x;
        if (type == 0) {
            st.range_chmin(l, r, x);
        } else if (type == 1) {
            st.range_chmax(l, r, x);
        } else {
            st.range_add(l, r, x);
        }
    }
    return 0;
}
