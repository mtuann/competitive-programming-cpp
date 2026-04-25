// Template: lazy segment tree (range add, range sum)
// Signal: online range additions interleaved with range-sum queries on one array.
// Assumes: zero-based half-open intervals [l, r); updates are additive only; sums fit in long long.
// Exposes: LazySegTreeRangeAddSum with build(a), range_add(l, r, delta), and range_sum(l, r).
// Complexity: O(n) build, O(log n) range update, O(log n) range query.
// Main trap: forgetting that a fully covered node may be correct while its children are still deferred behind a lazy tag.
// Links:
//   Topic: topics/data-structures/lazy-segment-tree/README.md
//   Note: practice/ladders/data-structures/lazy-segment-tree/horriblequeries.md

#include <iostream>
#include <vector>

using namespace std;

struct LazySegTreeRangeAddSum {
    int n;
    vector<long long> sum;
    vector<long long> lazy;

    explicit LazySegTreeRangeAddSum(int n) : n(n), sum(4 * n, 0), lazy(4 * n, 0) {}

    void build(const vector<long long> &a) {
        fill(sum.begin(), sum.end(), 0);
        fill(lazy.begin(), lazy.end(), 0);
        if (n > 0) {
            build(1, 0, n, a);
        }
    }

    void range_add(int l, int r, long long delta) {
        range_add(1, 0, n, l, r, delta);
    }

    long long range_sum(int l, int r) {
        return range_sum(1, 0, n, l, r);
    }

private:
    void build(int v, int lx, int rx, const vector<long long> &a) {
        if (rx - lx == 1) {
            sum[v] = a[lx];
            return;
        }
        int mx = (lx + rx) / 2;
        build(v * 2, lx, mx, a);
        build(v * 2 + 1, mx, rx, a);
        pull(v);
    }

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
    vector<long long> a = {1, 2, 3, 4, 5};
    LazySegTreeRangeAddSum st(static_cast<int>(a.size()));
    st.build(a);
    st.range_add(1, 4, 10);
    cout << st.range_sum(0, 5) << '\n';
    cout << st.range_sum(2, 5) << '\n';
    return 0;
}
