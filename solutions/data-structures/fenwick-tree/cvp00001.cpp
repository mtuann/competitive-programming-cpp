// Problem: CVP00001 - Ô ăn quan
// Judge: VN SPOJ
// Source URL: https://vn.spoj.com/problems/CVP00001/
// Topic: data structures, fenwick tree, circular range updates, simulation
// Idea: simulate each distinct start with circular range-add / point-query and
// point "set to zero" corrections; cache answers because every query uses the
// original board state.

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;

    explicit Fenwick(int n_) : n(n_), bit(n_ + 2, 0) {}

    void add(int idx, long long value) {
        while (idx <= n) {
            bit[idx] += value;
            idx += idx & -idx;
        }
    }

    void range_add(int left, int right, long long value) {
        if (left > right || value == 0) return;
        add(left, value);
        add(right + 1, -value);
    }

    long long point_query(int idx) const {
        long long result = 0;
        while (idx > 0) {
            result += bit[idx];
            idx -= idx & -idx;
        }
        return result;
    }
};

static int next_pos(int pos, int n) {
    return (pos == n ? 1 : pos + 1);
}

static long long solve_one_start(const vector<int>& initial, int start) {
    const int n = static_cast<int>(initial.size()) - 1;
    Fenwick bit(n);
    vector<long long> delta(n + 1, 0);

    auto get_value = [&](int pos) -> long long {
        return initial[pos] + delta[pos] + bit.point_query(pos);
    };

    auto zero_cell = [&](int pos) -> long long {
        long long current = get_value(pos);
        delta[pos] -= current;
        return current;
    };

    auto circular_add = [&](int pos, long long stones) {
        long long full = stones / n;
        int rem = static_cast<int>(stones % n);

        if (full > 0) bit.range_add(1, n, full);
        if (rem == 0) return;

        int left = pos + 1;
        if (left > n) left -= n;
        int right = left + rem - 1;
        if (right <= n) {
            bit.range_add(left, right, 1);
        } else {
            bit.range_add(left, n, 1);
            bit.range_add(1, right - n, 1);
        }
    };

    long long eaten = 0;
    int pos = start;

    while (true) {
        long long stones = zero_cell(pos);
        circular_add(pos, stones);

        int last = static_cast<int>((pos - 1 + stones % n) % n) + 1;
        int empty = next_pos(last, n);

        if (get_value(empty) > 0) {
            pos = empty;
            continue;
        }

        while (get_value(empty) == 0) {
            int take = next_pos(empty, n);
            long long captured = get_value(take);
            if (captured == 0) return eaten;
            eaten += zero_cell(take);
            empty = next_pos(take, n);
        }

        return eaten;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> initial(n + 1);
    for (int i = 1; i <= n; ++i) cin >> initial[i];

    const long long unknown = numeric_limits<long long>::min();
    vector<long long> cache(n + 1, unknown);

    while (true) {
        int start;
        cin >> start;
        if (start == 0) break;

        if (cache[start] == unknown) {
            cache[start] = solve_one_start(initial, start);
        }
        cout << cache[start] << '\n';
    }

    return 0;
}
