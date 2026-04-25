#include <iostream>
#include <vector>

using namespace std;

struct LazySegTree {
    int n;
    vector<long long> sum;
    vector<long long> lazy;

    explicit LazySegTree(int n) : n(n), sum(4 * n, 0), lazy(4 * n, 0) {}

    void range_add(int l, int r, long long delta) {
        range_add(1, 0, n, l, r, delta);
    }

    long long range_sum(int l, int r) {
        return range_sum(1, 0, n, l, r);
    }

private:
    void apply(int v, int seg_len, long long delta) {
        sum[v] += delta * seg_len;
        lazy[v] += delta;
    }

    void push(int v, int lx, int rx) {
        if (lazy[v] == 0 || rx - lx == 1) {
            return;
        }
        int mx = (lx + rx) / 2;
        apply(v * 2, mx - lx, lazy[v]);
        apply(v * 2 + 1, rx - mx, lazy[v]);
        lazy[v] = 0;
    }

    void pull(int v) {
        sum[v] = sum[v * 2] + sum[v * 2 + 1];
    }

    void range_add(int v, int lx, int rx, int l, int r, long long delta) {
        if (r <= lx || rx <= l) {
            return;
        }
        if (l <= lx && rx <= r) {
            apply(v, rx - lx, delta);
            return;
        }
        push(v, lx, rx);
        int mx = (lx + rx) / 2;
        range_add(v * 2, lx, mx, l, r, delta);
        range_add(v * 2 + 1, mx, rx, l, r, delta);
        pull(v);
    }

    long long range_sum(int v, int lx, int rx, int l, int r) {
        if (r <= lx || rx <= l) {
            return 0;
        }
        if (l <= lx && rx <= r) {
            return sum[v];
        }
        push(v, lx, rx);
        int mx = (lx + rx) / 2;
        return range_sum(v * 2, lx, mx, l, r) + range_sum(v * 2 + 1, mx, rx, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;
        LazySegTree st(n);
        while (q--) {
            int type;
            cin >> type;
            int l, r;
            cin >> l >> r;
            --l;
            if (type == 0) {
                long long v;
                cin >> v;
                st.range_add(l, r, v);
            } else {
                cout << st.range_sum(l, r) << '\n';
            }
        }
    }
    return 0;
}
